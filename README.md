## How to build tests

### Prerequisites

The project has been tested on a Linux Ubuntu system with the following installed:

* g++   >= version 5   
* gcc   >= version 5   
* gdb (optional for debugging)  
* cmake >= version 3.5 

### Build commands

    cd build
    cmake ..
    make

## How to run tests

    cd build
    test/tennistest

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
