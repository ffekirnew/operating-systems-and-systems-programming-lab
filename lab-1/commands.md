# Basic Commands
1. `mkdir`:

   - Definition: Used to create a new directory.
   - Basic Parameters:
     - `-p`: Creates nested folders.
   - Example Usage:
     - `mkdir os/new-folder`

2. `cd`:

   - Definition: Used to change the current directory.
   - Basic Parameters:
     - `.`: Refers to the current directory.
     - `..`: Refers to the parent directory.
     - `-`: Refers to the previous directory.
   - Example Usage:
     - `cd /home/user/documents/`: Changes the current directory to "/home/user/documents".
     - `cd ..`: Changes the current directory to the parent directory.
     - `cd -`: Changes the current directory to the previous directory.

3. `pwd`:

   - Definition: Used to print the current working directory.
   - Basic Parameters: None
   - Example Usage:
     - `pwd`: Prints the current working directory.

4. `rmdir`:

   - Definition: Used to remove an empty directory.
   - Basic Parameters:
     - `-p`: Removes nested directories.
   - Example Usage:
     - `rmdir os/new-folder`: Removes the directory "new-folder" inside the "os" directory.
     - `rmdir -p os/`: Removes the "os" directory and all its contents.

5. `rm`:

   - Definition: Used to remove files and directories.
   - Basic Parameters:
     - `-r`: Removes directories and their contents recursively.
     - `-f`: Removes files without prompting for confirmation.
   - Example Usage:
     - `rm file.txt`: Removes the file "file.txt".
     - `rm -r os/`: Removes the directory "os" and all its contents.
     - `rm -f file.txt`: Removes the file "file.txt" without confirmation.

6. `ls`:

   - Definition: Used to list the contents of a directory.
   - Basic Parameters:
     - `-a`: Shows hidden files.
     - `-l`: Shows detailed information about each file.
     - `-h`: Shows file sizes in human-readable format.
   - Example Usage:
     - `ls`: Lists the contents of the current directory.
     - `ls -a`: Lists all the contents of the current directory, including hidden files.
     - `ls -l -h`: Lists the contents of the current directory with detailed information and human-readable file sizes.

7. `cat`:

   - Definition: Used to display the contents of a file.
   - Basic Parameters: None
   - Example Usage:
     - `cat file.txt`: Displays the contents of the file "file.txt".

8. `cp`:

   - Definition: Used to copy files and directories.
   - Basic Parameters:
     - `-r`: Copies directories and their contents recursively.
     - `-f`: Overwrites the destination file without prompting for confirmation.
   - Example Usage:
     - `cp file.txt new-file.txt`: Copies the file "file.txt" and renames it to "new-file.txt".
     - `cp -r os/ os-backup/`: Copies the directory "os" and all its contents to "os-backup".
     - `cp -f file.txt backup/`: Copies the file "file.txt" to the "backup" directory, overwriting any existing file with the same name.

9. `mv`:
   - Definition: Used to move or rename files and directories.
   - Basic Parameters: None
   - Example Usage:
     - `mv file.txt new-file.txt`: Renames the file "file.txt" to "new-file.txt".
     - `mv file.txt documents/`: Moves the file "file.txt" to the "documents" directory.
     - `mv os/ os-backup/`: Renames the directory "os" to "os-backup".

10. `tail`:

  - Definition: Used to display the last few lines of a file.
  - Basic Parameters:
    - `-f`: Follows the end of the file and displays any new content that gets added.
    - `-n`: Specifies the number of lines to display.
  - Example Usage:
    - `tail file.txt`: Displays the last 10 lines of the file "file.txt".
    - `tail -n 5 file.txt`: Displays the last 5 lines of the file "file.txt".
    - `tail -f file.txt`: Displays the last few lines of the file "file.txt" and following any new content that gets added to the file.
