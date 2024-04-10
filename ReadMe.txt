vp504 - Vikrant Pulipati / aa2362 - Arjun Ajesh

Systems Programming - MyShell

This program is a custom command line shell. It is meant to work the same way as standard bash. However, there are a couple of limitations:
1. Quote marks are not supported: "word1 word2" will result in two arguments: "word1, and word2".
2. Only 2 commands can be piped at a time: "ls | wc | grep 1" will give the same output as "ls | wc"
3. Limited wildcard expansion: only filenames can undergo wildcard expansion - "folder/*.txt" can be expanded but not "*/file.txt"
4. When using in batch mode: input file must end in a newline character

How to use:

To compile the program:
    make

To run in interactive mode:
    ./mysh

To run in batch mode:
    ./mysh [Filename]

Test Plan:

1. Batch mode works as intended.

    Run:
    ./mysh bat.txt

    OUTPUT:
    bat.txt macros.h Makefile mysh mysh.c README.md test1 test.c testInput testOuput
    This is a test!

2. Interactive mode works as intended.

    Run in MyShell:
    ls

    OUTPUT:
    bat.txt macros.h Makefile mysh mysh.c README.md test1 test.c testInput testOutput

3. Wildcard expansion works properly - * is in file name

    Run in MyShell:
    echo test1/test*

    OUTPUT:
    test1/test test1/test2

4. Wildcard expansion works properly - * is in path name

    Run in MyShell:
    echo test*/test

    OUTPUT:
    test*/test

5. Conditionals work properly - THEN, previous command failed

    Run in MyShell:
    ls arg
    then ls
    
    OUTPUT:
    ls: cannot access 'arg': No such file or directory
    [blank]

6. Conditionals work properly - THEN, previous command succeeded

    Run in MyShell:
    ls
    then ls

    OUTPUT:
    bat.txt  macros.h  Makefile  mysh  mysh.c  README.md  test1  test.c  testInput  testOutput
    bat.txt  macros.h  Makefile  mysh  mysh.c  README.md  test1  test.c  testInput  testOutput

7. Conditionals work properly - ELSE, previous command failed

    Run in MyShell:
    ls arg
    else ls

    OUTPUT:
    ls: cannot access 'arg': No such file or directory
    bat.txt  macros.h  Makefile  mysh  mysh.c  README.md  test1  test.c  testInput  testOutput

8. Conditionals work properly - ELSE, previous command succeeded

    Run in MyShell:
    ls
    else ls

    OUTPUT:
    bat.txt  macros.h  Makefile  mysh  mysh.c  README.md  test1  test.c  testInput  testOutput
    [blank]

9. Input redirect works as intended

    Run in MyShell:
    grep test < testInput

    OUTPUT:
    testing

10. Output redirect works as intended

    Run in MyShell:
    ls > testOutput

    OUTPUT:

    testOutput:
    bat.txt
    macros.h
    Makefile
    mysh
    mysh.c
    README.md
    test1
    test.c
    testInput
    testOutput

11. Piped commands work as intended

    Run in MyShell:
    ls | grep test

    OUTPUT:
    test1
    test.c
    testInput
    testOutput

12. Piped commands work as intended - First command output redirect

    Run in MyShell:
    ls > testOutput | wc

    OUTPUT:

    std_out:
    0   0   0

    testOutput:
    bat.txt
    macros.h
    Makefile
    mysh
    mysh.c
    README.md
    test1
    test.c
    testInput
    testOutput

13. Piped commands work as intended - Second command input redirect

    Run in MyShell:
    ls | wc < testInput

    OUTPUT:
    4   5   38

14. cd and pwd work as intended

    Run in MyShell:
    pwd
    cd test1
    pwd
    cd ..
    pwd

    OUTPUT:
    /common/home/vp504/Desktop/SystemsProgramming/MyShell
    /common/home/vp504/Desktop/SystemsProgramming/MyShell/test1
    /common/home/vp504/Desktop/SystemsProgramming/MyShell

15. which works as intended

    Run in MyShell:
    which ls

    OUTPUT:
    /usr/bin/ls

16. Calling program from path works as intended

    Run in MyShell:
    test1/test

    OUTPUT:
    This is a test!