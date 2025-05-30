CFLAGS = -Wall -Werror -std=c99

TARGET = mempart1
SRC = mempart1.c
all: $(TARGET)
$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

# Run the program with input file and save output to part1out
run: $(TARGET)
	./$(TARGET) part1sequence > part1out

# Generate the checksum file
checksum: run
	@md5sum part1out | awk '{ print $$1 }' | tee p1result.txt

# Clean up build files
clean:
	rm -f $(TARGET) part1out p1result.txt
