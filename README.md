## File structure

* The unit tests are located in `test/TennisTest.cpp`
* The Tennis class is defined in `src/Tennis.hpp` and `src/Tennis.cpp`

## Prerequisites

The project has been tested on a Linux Ubuntu system with the following installed:

* g++   >= version 5   
* gcc   >= version 5   
* gdb (optional for debugging)  
* cmake >= version 3.5 

## Command line

### How to build tests

    cd build
    cmake ..
    make

### How to run tests

    cd build
    test/tennistest

## Eclipse CDT

### How to import project

1. Select File - Import...
1. Select Git - Projects from Git
1. Click Next
1. Select Clone URI
1. Paste `https://github.com/jmossberg/tenniskatacpp.git` into URI
    ![](/assets/eclipse_001.png)
1. Click Next
1. Select master branch
1. Click Next
1. Enter Directory, e.g. `/home/tdd/github/tenniskatacpp`.
1. Click Next
1. Select Import existing projects
1. Click Next
1. Make sure the Tennis project is selected
    ![](/assets/eclipse_002.png)
1. Click Finish
1. The Tennis project should now be available in the Project Explorer
    ![](/assets/eclipse_003.png)


### How to build tests

1. Right click on the Tennis project and select New - Folder
1. Enter folder name `build` and click Finish
    ![](/assets/eclipse_004.png)
1. Doubleclick on the `cmake` target in the Make Target tab on the right side of Eclipse
    ![](/assets/eclipse_005.png)
1. You should get something similar as the following in the Console tab
    ![](/assets/eclipse_006.png)
1. Doubleclick on the `tennistest` target in the Make Target tab on the right side of Eclipse
1. The Console tab build output should end with:

        [100%] Built target tennistest

### How to run tests

1. Select  Run - Run Configurations...
1. Selct C/C++ Application
1. Click on New
1. Enter name `tennistest`
1. Make sure Project is set to Tennis in the Project field on the Main tab
1. Enter `build/test/tennistest` in C/C++ Application field on the Main tab
1. Select Disable auto build in the Main tab
    ![](/assets/eclipse_007.png)
1. Click Apply and then Run
1. You should get the following in the Console tab

        [==========] Running 1 test from 1 test case.
        [----------] Global test environment set-up.
        [----------] 1 test from TennisTest
        [ RUN      ] TennisTest.ScoresAreZeroAtStart
        [       OK ] TennisTest.ScoresAreZeroAtStart (0 ms)
        [----------] 1 test from TennisTest (0 ms total)
        
        [----------] Global test environment tear-down
        [==========] 1 test from 1 test case ran. (11 ms total)
        [  PASSED  ] 1 test.


## Tennis kata

Credit: This kata can be found at http://codingdojo.org/kata/Tennis/ and also in the [The Coding Dojo Handbook](https://leanpub.com/codingdojohandbook) written by Emily Bache.

1. The Tennis scoring system is described at http://codingdojo.org/kata/Tennis/ 
1. Write a Tennis class to keep track of the Tennis score in one set. You don't have to consider multiple sets.
1. The Tennis class should implement a function, `getScore()` that returns the current score as a string. The `getScore()` function would return "Player 1: 15 Player 2: 0" if Player 1 has won one ball for example. 
1. The `getScore()` function shall return whether anyone has won the set, e.g. "Player 1 wins".
1. The `getScore()` function shall return if the if any player has the "advantage", e.g. "Player 1: 40 Player 2: 40 (advantage)". 
1. The class should implement a function, `winBall("<player>")` to report which player wins a ball, `winBall("Player 1")` is called if Player 1 wins the ball for example. 
1. Below is one scenario showing what `getScore()` returns in a set where Player 2 finally wins after the set being in deuce.
   * The set begins -> `"Player 1: 0 Player 2: 0"`
   * Player 1 wins the ball -> `"Player 1: 15 Player 2: 0"`
   * Player 1 wins the ball -> `"Player 1: 30 Player 2: 0"`
   * Player 1 wins the ball -> `"Player 1: 40 Player 2: 0"`
   * Player 2 wins the ball -> `"Player 1: 40 Player 2: 15"`
   * Player 2 wins the ball -> `"Player 1: 40 Player 2: 30"`
   * Player 2 wins the ball -> `"Player 1: 40 Player 2: 40"`
   * Player 2 wins the ball -> `"Player 1: 40 Player 2: 40 (advantage)"`
   * Player 2 wins the ball -> `"Player 2 wins"`
