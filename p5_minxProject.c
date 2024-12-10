#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <ctype.h>
#include <stdint.h>
#include <pwd.h>
#include <grp.h>

// Constants for Minix filesystem
#define SUPERBLOCK_OFFSET 1024
#define SUPERBLOCK_SIZE 1024
#define ROOT_INODE 1

// Structure to hold superblock data
struct superblock {
    unsigned short s_ninodes;
    unsigned short s_nzones;
    unsigned short s_imap_blocks;
    unsigned short s_zmap_blocks;
    unsigned short s_firstdatazone;
    unsigned short s_log_zone_size;
    unsigned short s_max_size;
    unsigned short s_magic;
    unsigned short s_state;
    unsigned short s_zones;
};

struct dir_entry {	//structure for Minix directoy entires
	unsigned short inode;
	char name[60]; //assumes Minix filename length is 60
};

struct minix_inode {
	unsigned short i_mode;
	unsigned short i_uid;
	unsigned int i_size;
	unsigned int i_time;
	unsigned char i_gid;
	unsigned char i_nlinks;
	unsigned short i_zone[9];
};

// Global variables
int disk_fd = -1;
struct superblock sb;

void print_help() {
    printf("Commands supported:\n");
    printf("help : prints the commands supported in the console\n");
    printf("minimount <file> : mount a local Minix disk\n");
    printf("miniumount : unmount the mounted Minix disk\n");
    printf("showsuper : list the information of the super block\n");
    printf("traverse [-l] : list the content in the root directory\n");
    printf("showzone <zone number> : show the ASCII content of the specified zone number\n");
    printf("showfile <filename> : show the content of the target file in hex\n");
    printf("quit : quit the Minix console\n");
}

void minimount(const char *filename) {
    if (disk_fd != -1) {
        printf("Disk already mounted.\n");
        return;
    }
    disk_fd = open(filename, O_RDONLY);
    if (disk_fd < 0) {
        perror("Failed to mount disk");
        return;
    }
    lseek(disk_fd, SUPERBLOCK_OFFSET, SEEK_SET);
    read(disk_fd, &sb, sizeof(sb));
    printf("Disk mounted successfully.\n");
}

void miniumount() {
    if (disk_fd == -1) {
        printf("No disk is mounted.\n");
        return;
    }
    close(disk_fd);
    disk_fd = -1;
    printf("Disk unmounted successfully.\n");
}

void showsuper() {
    if (disk_fd == -1) {
        printf("No disk is mounted.\n");
        return;
    }
    printf("Superblock Information:\n");
    printf("Number of inodes: %u\n", sb.s_ninodes);
    printf("Number of zones: %u\n", sb.s_zones);
    printf("Number of imap_blocks: %u\n", sb.s_imap_blocks);
    printf("Number of zmap_blocks: %u\n", sb.s_zmap_blocks);
    printf("First data zone: %u\n", sb.s_firstdatazone);
    printf("Log zone size: %u\n", sb.s_log_zone_size);
    printf("Max size: %u\n", sb.s_max_size);
    printf("Magic number: %x\n", sb.s_magic);
    printf("State: %u\n", sb.s_state);
    printf("Zones: %u\n", sb.s_zones);
}

//2 other functions used by traverse
void getFileInfo(char *info, struct stat *statbuf) {
	char types[] = {'-', 'd', 'c', 'b', 'p', 'l', 's'};
	info[0] = types[(statbuf->st_mode & S_IFMT) >> 12];
	for (int i = 0; i < 3; i++) {
		info[1 + i*3] = (statbuf->st_mode & (S_IRUSR >> i*3)) ? 'r' : '-';
		info[2 + i*3] = (statbuf->st_mode & (S_IWUSR >> i*3)) ? 'w' : '-';
		info[3 + i*3] = (statbuf->st_mode & (S_IXUSR >> i*3)) ? 'x' : '-';
	}
	info[10] = '\0';
}
void printDetailedInfo(struct stat *statbuf, char *filename) {
	//printf("printDetailedInfo WORKED\n");
	char info[11];
	getFileInfo(info, statbuf);
	struct passwd *pwd = getpwuid(statbuf->st_uid);
	struct group *grp = getgrgid(statbuf->st_gid);
	char timebuf[64];
	strftime(timebuf, sizeof(timebuf), "%b %d %H:%M", localtime(&statbuf->st_mtime));
	printf("%s %4ld %s %9s %ld %s %s\n", info, statbuf->st_nlink, pwd->pw_name, grp->gr_name, statbuf->st_size, timebuf, filename);
}
void traverse(int long_list) {
	if (disk_fd == -1) {
		printf("No disk is mounted \n");
		return;
	}
	//assume root dir is at i-node 1
	lseek(disk_fd, SUPERBLOCK_OFFSET + (ROOT_INODE -1) * sizeof(struct minix_inode), SEEK_SET);
	struct minix_inode root_inode;
	read(disk_fd, &root_inode, sizeof(root_inode));
	lseek(disk_fd, root_inode.i_zone[0] * 1024, SEEK_SET);
	struct dir_entry entries[1024 / sizeof(struct dir_entry)];
	read(disk_fd, entries, sizeof(entries));
	//printf("%s\n", entries);
	for (int i=0; i < 1024 / sizeof(struct dir_entry); i++) {
		printf("%s\n", entries[i]);
		//if (entries[i].inode == 0 || strcmp(entries[i].name, ".") == 0 || strcmp(entries[i].name, "..") == 0) continue;
		if (long_list == 4) {
			//printf("start of -l\n");
			struct stat statbuf;
			memset(&statbuf, 0, sizeof(struct stat));
			lseek(disk_fd, SUPERBLOCK_OFFSET + (entries[i].inode - 1) * sizeof(struct minix_inode), SEEK_SET);
			struct minix_inode file_inode;
			read(disk_fd, &file_inode, sizeof(file_inode));
			statbuf.st_mode = file_inode.i_mode;
			statbuf.st_nlink = file_inode.i_nlinks;
			statbuf.st_uid = file_inode.i_uid;
			statbuf.st_gid = file_inode.i_gid;
			statbuf.st_size = file_inode.i_size;
			statbuf.st_mtime = file_inode.i_time;
			//printf("right before printDetail\n");
			printDetailedInfo(&statbuf, entries[i].name);
		} else {
			printf("%s\n", entries[i].name); //if not -l
		}
	}
}

void showzone(int zone_number) {
    // Implementation for showing the ASCII content of the specified zone number
    if (disk_fd == -1) {
	    printf("No disk is mounted \n");
	    return;
    }
    char buffer[1024];
    lseek(disk_fd, zone_number * 1024, SEEK_SET);
    read(disk_fd, buffer, sizeof(buffer));
    for (int i = 0; i < 1024; i++) {
	    if (isprint(buffer[i])) {
		    putchar(buffer[i]);
	    } else {
		    putchar(' ');
	    }
    }
    putchar('\n');
}

void showfile(const char *filename) {
    // Implementation for showing the content of the target file in hex
    if (disk_fd == -1) {
	    printf("No disk is mounted\n");
	    return;
    }
    //locate root dir inode
    lseek(disk_fd, SUPERBLOCK_OFFSET + (ROOT_INODE - 1) * sizeof(struct minix_inode), SEEK_SET);
    struct minix_inode root_inode;
    read(disk_fd, &root_inode, sizeof(root_inode));
    //read root dir entries
    lseek(disk_fd, root_inode.i_zone[0] * 1024, SEEK_SET);
    struct dir_entry entries[1024 / sizeof(struct dir_entry)];
    read(disk_fd, entries, sizeof(entries));

    //find the inode number for the target file
    int inode = 0;
    for (int i=0; i < 1024 / sizeof(struct dir_entry); i++) {
	    if (strcmp(entries[i].name, filename) == 0) {
		    inode = entries[i].inode;
		    break;
	    }
    }

    if (inode == 0) {
	    printf("File not found \n");
	    return;
    }

    //read the target file inode
    lseek(disk_fd, SUPERBLOCK_OFFSET + (inode - 1) * sizeof(struct minix_inode), SEEK_SET);
    struct minix_inode file_inode;
    read(disk_fd, &file_inode, sizeof(file_inode));

    //read the file content
    char buffer[file_inode.i_size];
    for (int i=0; i < (file_inode.i_size + 1023) / 1024; i++) {
	    lseek(disk_fd, file_inode.i_zone[i] * 1024, SEEK_SET);
	    read(disk_fd, buffer + i * 1024, 1024);
    }
    //print the file content in hex
    for (int i=0; i < file_inode.i_size; i++) {
	    printf("%02x ", (unsigned char)buffer[i]);
	    if ((i + 1) % 16 == 0) printf("\n");
    }
    printf("\n");
}

int main() {
    char command[256];
    printf("Minix Console. Type 'help' for a list of commands.\n");
    while (1) {
        printf("> ");
        if (!fgets(command, sizeof(command), stdin)) break;
        command[strcspn(command, "\n")] = 0; // Remove newline character

        if (strncmp(command, "help", 4) == 0) {
            print_help();
        } else if (strncmp(command, "minimount", 9) == 0) {
            char *filename = command + 10;
            minimount(filename);
        } else if (strncmp(command, "miniumount", 10) == 0) {
            miniumount();
        } else if (strncmp(command, "showsuper", 9) == 0) {
            showsuper();
        } else if (strncmp(command, "traverse", 8) == 0) {
            int long_list = 2;
	    if (strstr(command, "-l") != NULL) {
		    long_list = 4;
	    }
	    printf("long_list value: %d\n", long_list);
            traverse(long_list);
        } else if (strncmp(command, "showzone", 8) == 0) {
            int zone_number = atoi(command + 9);
            showzone(zone_number);
        } else if (strncmp(command, "showfile", 8) == 0) {
            char *filename = command + 9;
            showfile(filename);
        } else if (strncmp(command, "quit", 4) == 0) {
            break;
        } else {
            printf("Unknown command. Type 'help' for a list of commands.\n");
        }
    }
    if (disk_fd != -1) {
        close(disk_fd);
    }
    return 0;
}
