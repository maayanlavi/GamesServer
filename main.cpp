#include "GameAlgorithm.h"
#include "BoardGame.h"
#include "CatchTheBunny.h"
#include "TicTacToe.h"
#include "Interface.h"
#include "BoardGameController.h"

#include <string>

using namespace std;

int main() {
	int GameType;
	int InterfaceType;
	int GameLevel;
	cout << "welcome to our GAME WORLD!" << endl;
	cout << "choose an INTERFACE (right now, only 'console' is available, please press 1)" << endl;
	cin >> InterfaceType;
	cout << "choose a game: press 1 for CATCH THE BUNNY and 2 for TIC TAC TOE" << endl;
	cin >> GameType;
	cout << "choose a level: press 1 for RANDOM and 2 for EDUCATE" << endl;
	cin >> GameLevel;

	int choose=0;
	if (GameType == 1 && GameLevel == 1)
		choose = 1; // random catch the bunny
	if (GameType == 1 && GameLevel == 2)
		choose = 2; // educate catch the bunny
	if (GameType == 2 && GameLevel == 1)
		choose = 3; // random tic tac toe
	if (GameType == 2 && GameLevel == 2)
		choose = 4; // educate tic tac toe


	Interface* interface = new ConsoleInterFace();
	switch (choose) {
	case 1: {
		CatchTheBunny* CTB = new CatchTheBunnyRand ();
		BoardGameController BGC(CTB, interface);
		BGC.play();
		break; }
	case 2: {
		CatchTheBunny* CTB = new CatchTheBunnyEdu();
		BoardGameController BGC(CTB, interface);
		BGC.play();
		break;
	}
	case 3: {
		TicTacToe* CTB = new TicTacToeRand();
		BoardGameController BGC(CTB, interface);
		BGC.play();
		break;
	}
	case 4: {
		TicTacToe* CTB = new TicTacToeEdu();
		BoardGameController BGC(CTB, interface);
		BGC.play();
		break;
	}

	}


}