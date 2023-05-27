    mkdir:
        Definition: Used to create a new directory.
        Basic Parameters:
            -p: Creates nested folders.
        Example Usage:
            mkdir os/new-folder

    cd:
        Definition: Used to change the current working directory.
        Basic Parameters:
            <directory>: Specifies the directory to change to.
            ..: Moves to the parent directory.
            ~: Moves to the home directory.
        Example Usage:
            cd documents
            cd ..
            cd ~/downloads

    pwd:
        Definition: Displays the current working directory.
        Example Usage:
            pwd

    rmdir:
        Definition: Used to remove an empty directory.
        Example Usage:
            rmdir empty-folder

    rm:
        Definition: Used to remove files and directories.
        Basic Parameters:
            -r: Recursively removes directories and their contents.
            -f: Forces removal without prompting for confirmation.
        Example Usage:
            rm file.txt
            rm -r directory
            rm -rf directory

    ls:
        Definition: Lists files and directories in the current directory.
        Basic Parameters:
            -l: Displays detailed information.
            -a: Shows hidden files.
        Example Usage:
            ls
            ls -l
            ls -a

    cat:
        Definition: Displays the contents of a file.
        Example Usage:
            cat file.txt

    cp:
        Definition: Copies files and directories.
        Basic Parameters:
            <source>: Specifies the source file or directory.
            <destination>: Specifies the destination directory.
        Example Usage:
            cp file.txt new-folder
            cp -r directory/ destination/

    mv:
        Definition: Moves or renames files and directories.
        Basic Parameters:
            <source>: Specifies the source file or directory.
            <destination>: Specifies the destination directory or new name.
        Example Usage:
            mv file.txt new-folder
            mv directory/ new-location/

    tail:
        Definition: Displays the last part of a file.
        Basic Parameters:
            -n: Specifies the number of lines to display.
        Example Usage:
            tail file.txt
            tail -n 10 file.txt

    more:
        Definition: Displays the contents of a file one page at a time.
        Example Usage:
            more file.txt

    less:
        Definition: Displays the contents of a file with backward navigation support.
        Example Usage:
            less file.txt

    who:
        Definition: Displays the currently logged-in users.
        Example Usage:
            who

    passwd:
        Definition: Used to change the password for a user account.
        Example Usage:
            passwd

    date:
        Definition: Displays the current date and time.
        Example Usage:
            date

    df:
        Definition: Displays information about disk space usage.
        Example Usage:
            df

    clear:
        Definition: Clears the terminal screen.
        Example Usage:
            clear

    exit:
        Definition: Exits the current shell or terminal session.
        Example Usage:
            exit

    nano:
        Definition: Opens the nano text editor.
        Basic Usage:
            nano file.txt

    hostname:
        Definition: Displays the name of the current host or sets the hostname.
        Example Usage:
            hostname

    uname:
        Definition: Displays system information.
        Example Usage:
            uname -a

    ps:
        Definition: Displays information about running processes.
        Basic Parameters:
            -e: Displays information about all processes.
        Example Usage:
            ps
            ps -e

    ip:
        Definition: Displays network configuration information.
        Example Usage:
            ip address

    ping:
        Definition: Sends ICMP Echo Request packets to a network host.
        Example Usage:
            ping google.com

    lshw:
        Definition: Displays detailed information about the hardware configuration.
        Example Usage:
            lshw

    lscpu:
        Definition: Displays information about the CPU architecture and processing units.
        Example Usage:
            lscpu

    lsmem:
        Definition: Displays information about the memory configuration.
        Example Usage:
            lsmem

    lspci:
        Definition: Displays information about PCI devices.
        Example Usage:
            lspci

    lsmod:
        Definition: Displays the status of loaded kernel modules.
        Example Usage:
            lsmod
