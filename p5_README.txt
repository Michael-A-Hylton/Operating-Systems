Project Authors: Ethan Pedrick and Michael Hylton
Contribution Amounts:
  Ethan Pedrick - 2835438: 50%
  Michael Hylton - 2788154: 50%

The bonus is incomplete. The Traverse function is working, but printDetailedInformation is not working correctly.

Brief project description:
A minix disk program that allows a user to execute multiple commands in a minx console while accessing a minix disk locally mounted on a computer.

Compilation Instructions and the Execution Command:
Type make while in the directory with the correct file and Makefile. Then type ./minxProject. This then brings you to the menu where you can type the commands.

A sample test run:

Minix Console. Type 'help' for a list of commands.
> help
Commands supported:
help : prints the commands supported in the console
minimount <file> : mount a local Minix disk
miniumount : unmount the mounted Minix disk
showsuper : list the information of the super block
traverse [-l] : list the content in the root directory
showzone <zone number> : show the ASCII content of the specified zone number
showfile <filename> : show the content of the target file in hex
quit : quit the Minix console
> minimount imagefile.img
Disk mounted successfully.
> showsuper
Superblock Information:
Number of inodes: 3424
Number of zones: 0
Number of imap_blocks: 1
Number of zmap_blocks: 2
First data zone: 112
Log zone size: 0
Max size: 7168
Magic number: 1008
State: 5007
Zones: 0
> 

> traverse 
long_list value: 2

ong_list value: 2
               ..                              A.cla                           Aloop1.cla                      Aloop1.jav                      Aloop2.cla                      Aloop2.jav                      Aloop3.cla                      Aloop3.jav                      B.cla                           Condit.cla                      Condit.jav                      D.cla                           Demo.cla                        Demo.jav                        dir1                            PolyTest.cla                    PolyTest.jav                    some.cla                        some.java                                                                                                                                                                                                                                                                                                                                                                                                                     


              ..                              A.cla                           Aloop1.cla                      Aloop1.jav                      Aloop2.cla                      Aloop2.jav                      Aloop3.cla                      Aloop3.jav                      B.cla                           Condit.cla                      Condit.jav                      D.cla                           Demo.cla                        Demo.jav                        dir1                            PolyTest.cla                    PolyTest.jav                    some.cla                        some.java                                                                                                                                                                                                                                                                                                                                                                                                                     
                  

                 
                           A.cla                           Aloop1.cla                      Aloop1.jav                      Aloop2.cla                      Aloop2.jav                      Aloop3.cla                      Aloop3.jav                      B.cla                           Condit.cla                      Condit.jav                      D.cla                           Demo.cla                        Demo.jav                        dir1                            PolyTest.cla                    PolyTest.jav                    some.cla                        some.java                                                                                                                                                                                                                                                                                                                                                                                                                     


                 
        A.cla                           Aloop1.cla                      Aloop1.jav                      Aloop2.cla                      Aloop2.jav                      Aloop3.cla                      Aloop3.jav                      B.cla                           Condit.cla                      Condit.jav                      D.cla                           Demo.cla                        Demo.jav                        dir1                            PolyTest.cla                    PolyTest.jav                    some.cla                        some.java                                                                                                                                                                                                                                                                                                                                                                                                                     


                 
                     Aloop1.cla                      Aloop1.jav                      Aloop2.cla                      Aloop2.jav                      Aloop3.cla                      Aloop3.jav                      B.cla                           Condit.cla                      Condit.jav                      D.cla                           Demo.cla                        Demo.jav                        dir1                            PolyTest.cla                    PolyTest.jav                    some.cla                        some.java                                                                                                                                                                                                                                                                                                                                                                                                                     



                 
  Aloop1.cla                      Aloop1.jav                      Aloop2.cla                      Aloop2.jav                      Aloop3.cla                      Aloop3.jav                      B.cla                           Condit.cla                      Condit.jav                      D.cla                           Demo.cla                        Demo.jav                        dir1                            PolyTest.cla                    PolyTest.jav                    some.cla                        some.java                                                                                                                                                                                                                                                                                                                                                                                                                     

                         
               Aloop1.jav                      Aloop2.cla                      Aloop2.jav                      Aloop3.cla                      Aloop3.jav                      B.cla                           Condit.cla                      Condit.jav                      D.cla                           Demo.cla                        Demo.jav                        dir1                            PolyTest.cla                    PolyTest.jav                    some.cla                        some.java                                                                                                                                                                                                                                                                                                                                                                                                                     



                 
p1.jav                      Aloop2.cla                      Aloop2.jav                      Aloop3.cla                      Aloop3.jav                      B.cla                           Condit.cla                      Condit.jav                      D.cla                           Demo.cla                        Demo.jav                        dir1                            PolyTest.cla                    PolyTest.jav                    some.cla                        some.java                                                                                                                                                                                                                                                                                                                                                                                                                     


                 
         Aloop2.cla                      Aloop2.jav                      Aloop3.cla                      Aloop3.jav                      B.cla                           Condit.cla                      Condit.jav                      D.cla                           Demo.cla                        Demo.jav                        dir1                            PolyTest.cla                    PolyTest.jav                    some.cla                        some.java                                                                                                                                                                                                                                                                                                                                                                                                                     

     

                 

v                      B.cla                           Condit.cla                      Condit.jav                      D.cla                           Demo.cla                        Demo.jav                        dir1                            PolyTest.cla                    PolyTest.jav                    some.cla                        some.java                                                                                                                                                                                                                                                                                                                                                                                                                     

                 
                 

     D.cla                           Demo.cla                        Demo.jav                        dir1                            PolyTest.cla                    PolyTest.jav                    some.cla                        some.java                                                                                                                                                                                                                                                                                                                                                                                                                     

                 
                 

PolyTest.cla                    PolyTest.jav                    some.cla                        some.java                                                                                                                                                                                                                                                                                                                                                                                                                     

> > traverse -l
long_list value: 4

----------    0 root      root 0 Dec 31 19:00 
----------    0 root      root 0 Dec 31 19:00 
        

                 

                 

                 

                 

                                                                                                               

                                                                                                                                   

                                                                                                                                   

                                                                                                                

                 

                                                                                                                

                 

                                                                                             

                 

                 

                 

                 

                 

                 

                 

                  
----------    0 root      root 0 Dec 31 19:00 
----------    0 root      root 0 Dec 31 19:00 
        

                 

                 

                 

                 

                                                                                                               

                                                                                                                                   

                                                                                                                                   

                                                                                                                

                 

                                                                                                                

                 

                                                                                             

                 

                 

                 

                 

                 

                 

                 

                  
----------    0 root      root 0 Dec 31 19:00 
----------    0 root      root 0 Dec 31 19:00 
        

                 

                 

                 

                 

                                                                                                               

                                                                                                                                   

                                                                                                                                   

                                                                                                                

                 

                                                                                                                

                 

                                                                                             

                 

                 

                 

                 

                 

                 

                 

                  
----------    0 root      root 0 Dec 31 19:00 
----------    0 root      root 0 Dec 31 19:00 
        

                 

                 

                 

                 

                                                                                                               

                                                                                                                                   

                                                                                                                                   

                                                                                                                

                 

                                                                                                                

                 

                                                                                             

                 

                 

                 

                 

                 

                 

                 

                  
----------    0 root      root 0 Dec 31 19:00 
----------    0 root      root 0 Dec 31 19:00 
        

                 

                 

                 

                 

                                                                                                               

                                                                                                                                   

                                                                                                                                   

                                                                                                                

                 

                                                                                                                

                 

                                                                                             

                 

                 

                 

                 

                 

                 

                 

                  
----------    0 root      root 0 Dec 31 19:00 
----------    0 root      root 0 Dec 31 19:00 
        

                 

                 

                 

                 

                                                                                                               

                                                                                                                                   

                                                                                                                                   

                                                                                                                

                 

                                                                                                                

                 

                                                                                             

                 

                 

                 

                 

                 

                 

                 

                  
----------    0 root      root 0 Dec 31 19:00 
----------    0 root      root 0 Dec 31 19:00 
        

                 

                 

                 

                 

                                                                                                               

                                                                                                                                   

                                                                                                                                   

                                                                                                                

                 

                                                                                                                

                 

                                                                                             

                 

                 

                 

                 

                 

                 

                 

                  
----------    0 root      root 0 Dec 31 19:00 
----------    0 root      root 0 Dec 31 19:00 
        

                 

                 

                 

                 

                                                                                                               

                                                                                                                                   

                                                                                                                                   

                                                                                                                

                 

                                                                                                                

                 

                                                                                             

                 

                 

                 

                 

                 

                 

                 

                  
----------    0 root      root 0 Dec 31 19:00 
----------    0 root      root 0 Dec 31 19:00 
        

                 

                 

                 

                 

                                                                                                               

                                                                                                                                   

                                                                                                                                   

                                                                                                                

                 

                                                                                                                

                 

                                                                                             

                 

                 

                 

                 

                 

                 

                 

                  
----------    0 root      root 0 Dec 31 19:00 
----------    0 root      root 0 Dec 31 19:00 
        

                 

                 

                 

                 

                                                                                                               

                                                                                                                                   

                                                                                                                                   

                                                                                                                

                 

                                                                                                                

                 

                                                                                             

                 

                 

                 

                 

                 

                 

                 

                  
----------    0 root      root 0 Dec 31 19:00 
----------    0 root      root 0 Dec 31 19:00 
        

                 

                 

                 

                 

                                                                                                               

                                                                                                                                   

                                                                                                                                   

                                                                                                                

                 

                                                                                                                

                 

                                                                                             

                 

                 

                 

                 

                 

                 

                 

                  
----------    0 root      root 0 Dec 31 19:00 
----------    0 root      root 0 Dec 31 19:00 
        

                 

        

                 

                  
----------    0 root      root 0 Dec 31 19:00 
----------    0 root      root 0 Dec 31 19:00 
        

                                                                                                        

                 

                                                                                             

                  
----------    0 root      root 0 Dec 31 19:00 
----------    0 root      root 0 Dec 31 19:00 
        



                 

                                                                                                               

                                                                                                                                   

                                                                                                                                   

                                                                                                                

                 

                                                                                                                

                 

                                                                                             


                  
----------    0 root      root 0 Dec 31 19:00 
----------    0 root      root 0 Dec 31 19:00 
        

                                                                                                               

                                                                                                                                   

                                                                                                                                   

                                                                                                                

                 

                                                                                                                

                 

                                                                                             



                  
----------    0 root      root 0 Dec 31 19:00 
> showfile B.cla
File not found 
> quit
