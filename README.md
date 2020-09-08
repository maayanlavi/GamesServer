# GamesServer

c++

Implementation of an interactive game server that contains a number of board games and allows players to select a game and play it.

The server contains the tic-tac-toe games and grabs the bunny and allows the programmer to easily add more games.

There are 2 user interface options: console interface and graphical user interface.

There are 2 difficulty levels per game: easy (the computer takes random steps), medium (the computer takes intelligent steps). Additional difficulty levels can be added easily.

As far as the customer is concerned, a game is run as follows: first, the player makes a movement (reflected in the user interface), then the computer makes a movement. 

These two actions are repeated again until the game ends.

The BoardGameController department manages the game using the play method.

The project focuses on desing pattern, STL, MVC.
