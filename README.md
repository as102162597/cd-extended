**cd-extended**
===============
Version: 1.0.0\
Release date: 11/05/2024

Author
======
- Ed

Introduction
============
This is a project for Linux platform that makes changing directories more convenient. It automatically records directories visited by the user through the existing ```cd``` command by using additional files and programs. Moreover, it provides the ```cb```, ```cf``` and ```cv``` commands to help users shuttle between these directories more easily and quickly.

#### **```cb```**: **change back to previous directory**
+ This command changes the working directory to the previous working directory. It also allows you to navigate to even earlier working directories through options and parameters.
#### **```cf```**: **change forward to next directory**
+ This command helps the user to return to an even earlier working directory when using the ```cb``` command to go back to a previous working directory. It also allows the user to change to a later visited working directory through options and parameters.
#### **```cv```**: **change to a visited directory**
+ This command displays the history of directories you have visited, and it also allows you to change to a specified directory using options and parameters.

Usage
=====
The commands ```cb``` and ```cf``` are similar to the *back* and *forward* buttons in a web browser, respectively. As their names suggest, they allow users to navigate through previously visited directories. The ```cv``` command provides a method to view your history and allows you to navigate to previous directories in a specified way. Here are the detailed usage and formats for them:
#### ```cb``` [NUMBER]
- Change the working directory to the *NUMBER*-th directory in reverse order. If *NUMBER* is not specified, go to the previous directory.
#### ```cf``` [NUMBER]
- Change the current working directory to the *NUMBER*-th directory after the current one. Go to the next directory if *NUMBER* is not specified.
#### ```cv``` [COUNT [-a]]|[-n NUMBER]
- Displays the *COUNT* most recent directories before and after the current directory, with *COUNT* defaulting to 4. You can also use the '-n' option to directly jump to a specified directory.

Install
=======
Please make sure that your computer has g++ version **11.4.0** or **higher** installed before proceeding with the installation.

1. Afterward, you need to clone this repository.

       git clone https://github.com/as102162597/cd-extended.git

1. Navigate to the downloaded repository folder after the program finishes.

       cd cd-extended

1. Then compile the program in the folder.

       make

1. Install the compiled scripts and binaries.

       sudo make install

1. Finally, apply the settings that were just configured to the environment.

       . install.sh

Uninstall
=========
You should return to the *cd-extended* directory.
1. You can undo the environment setting after entering the repository directory, the *cd-extended* folder.

       . uninstall.sh

1. Next, remove the installed scripts and binaries from the environment.

       sudo make uninstall

1. You can remove the compiled files if necessary.

       make clean

1. Thus, you have completed the uninstallation of *cd-extended*.

In case of an emergency, or if you've lost the installation files and want to manually remove this command, you can achieve this by following the method outlined below:

    unalias cb cd cf cv
    rm /etc/profile.d/cd-extended.sh
    rm /usr/local/share/cd-extended/*

License
=======
*cd-extended* is distributed under the MIT license, which allows for the modification and redistribution of the code. For more details, please refer to the *LICENSE* file.

Please note that while we have made every effort to ensure the functionality of this repository, we cannot guarantee that it will work flawlessly in every situation. Users assume all risks associated with the use of this code.

Additionally, we cannot guarantee that updates will be provided in a timely manner. However, we welcome any contributions or feedback from users to help improve the code.
