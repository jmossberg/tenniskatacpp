This git repository can be used as a starting point for the Tennis kata described below. The project contains one initial unit test. Google Test is used as test framework. 

You should solve the kata incrementally by adding more and more unit tests to `test/TennisTest.cpp`. Keep each unit test small and focused. Make use of the [TDD (Test Driven Development) cycle](https://en.wikipedia.org/wiki/Test-driven_development#Test-driven_development_cycle):

1. Write a test
1. Make sure it fails
1. Make it pass
1. Refactor
1. Goto step 1

## Tennis kata

Credit: This kata can be found at http://codingdojo.org/kata/Tennis/ and also in the [The Coding Dojo Handbook](https://leanpub.com/codingdojohandbook) written by Emily Bache.

1. Write a Tennis class to keep track of the Tennis score in one [game](https://en.wikipedia.org/wiki/Tennis_scoring_system#Game_score). You don't have to consider [sets](https://en.wikipedia.org/wiki/Tennis_scoring_system#Set_score) and [matches](https://en.wikipedia.org/wiki/Tennis_scoring_system#Match_score).
1. The Tennis scoring system is described at http://codingdojo.org/kata/Tennis/
1. The Tennis class shall implement a method `winBall("<player>")` to report which player wins a ball, `winBall("Player 1")` is called if Player 1 wins the ball for example.
1. The Tennis class shall implement a method, `score()` that returns the current score as a string. The `score()` function would return `Player 1: 15 Player 2: love` if Player 1 has won the first ball in the game for example. 
1. The `score()` method shall return whether anyone has **won** the set, e.g. `Player 1 wins`.
1. The `score()` method shall return whether anyone has the **advantage**, e.g. `Player 2 advantage`.
1. The `score()` method shall return whether the game is in **deuce**, e.g. `Deuce`.  
1. Below is one scenario showing what `score()` returns in a game where Player 2 finally wins after the game being in deuce.
   * The game begins -> `"Player 1: love Player 2: love"`
   * Player 1 wins the ball -> `"Player 1: 15 Player 2: love"`
   * Player 1 wins the ball -> `"Player 1: 30 Player 2: love"`
   * Player 1 wins the ball -> `"Player 1: 40 Player 2: love"`
   * Player 2 wins the ball -> `"Player 1: 40 Player 2: 15"`
   * Player 2 wins the ball -> `"Player 1: 40 Player 2: 30"`
   * Player 2 wins the ball -> `"Deuce"`
   * Player 2 wins the ball -> `"Player 2 advantage"`
   * Player 2 wins the ball -> `"Player 2 wins"`

## File structure

* The unit tests are located in `test/TennisTest.cpp`
* The Tennis class is declared in `src/Tennis.hpp` and defined `src/Tennis.cpp`
* The Google Test framework is located in the `google` folder
* The `assets` folder contains the pictures used in this readme file

## Prerequisites

The project has been tested on a Linux Ubuntu system with the following installed:

* g++   >= version 5   
* gcc   >= version 5   
* cmake >= version 3.5 
* Eclipse CDT 4.4.2
* gdb (optional for debugging)

## Command line

### How to build tests

	mkdir build
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
    <img src="/assets/eclipse_001.png" width="600">
1. Click Next
1. Select master branch
1. Click Next
1. Enter Directory, e.g. `/home/tdd/github/tenniskatacpp`.
1. Click Next
1. Select Import existing projects
1. Click Next
1. Make sure the Tennis project is selected
    <img src="/assets/eclipse_002.png" width="600">
1. Click Finish
1. The Tennis project should now be available in the Project Explorer
    <img src="/assets/eclipse_003.png" width="600">


### How to build tests

1. Right click on the Tennis project and select New - Folder
1. Enter folder name `build` and click Finish
    <img src="/assets/eclipse_004.png" width="600">
1. Doubleclick on the `cmake` target in the Make Target tab on the right side of Eclipse
    <img src="/assets/eclipse_005.png" width="400">
1. You should get something similar as the following in the Console tab
    <img src="/assets/eclipse_006.png" width="600">
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
    <img src="/assets/eclipse_007.png" width="600">
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
