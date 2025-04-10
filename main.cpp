#include <iostream>
#include <algorithm>
#include <ctime>
using namespace std;

int main() {

	srand(time(NULL));

	//game variables
	string input;
	bool MatchFound = false;
	int PHandSize = 5;
	int CHandSize = 5;
	int NextDeckCard = 10;
	bool HasCard = false;
	int PlayerScore = 0;
	int ComputerScore = 0;
	int TurnNumber = 1;
	int ComputerPick;
	enum TURNS {player, computer};
	int turn = player;
	int quads = 0;
	char match;
	bool isEmpty = false;

	string deck[52] = {
		"Ace Hearts", "2 Hearts", "3 Hearts", "4 Hearts", "5 Hearts", "6 Hearts",
		"7 Hearts", "8 Hearts", "9 Hearts", "10 Hearts", "Jack Hearts", "Queen Hearts", "King Hearts",
		"Ace Diamonds", "2 Diamonds", "3 Diamonds", "4 Diamonds", "5 Diamonds", "6 Diamonds",
		"7 Diamonds", "8 Diamonds", "9 Diamonds", "10 Diamonds", "Jack Diamonds", "Queen Diamonds", "King Diamonds",
		"Ace Clubs", "2 Clubs", "3 Clubs", "4 Clubs", "5 Clubs", "6 Clubs",
		"7 Clubs", "8 Clubs", "9 Clubs", "10 Clubs", "Jack Clubs", "Queen Clubs", "King Clubs",
		"Ace Spades", "2 Spades", "3 Spades", "4 Spades", "5 Spades", "6 Spades",
		"7 Spades", "8 Spades", "9 Spades", "10 Spades", "Jack Spades", "Queen Spades", "King Spades"
	};

	random_shuffle(&deck[0], &deck[52]);
	//for (int i = 0; i < 52; i++) {
	//	cout << deck[i] << endl;
	//}


	//create two arrays to represent the cars that the player and computer will have in their hands,
	//initialize each slot in both array's to the word "empty"
	string PlayerHand[52];
	string ComputerHand[52];
	for (int i = 0; i < 52; i++) {
		PlayerHand[i] = "empty";
		ComputerHand[i] = "empty";
	}

	//swap out the first five of the deck into the players hand
	//and the second five into the computer hand
	for (int i = 0; i < 5; i++) {
		PlayerHand[i] = deck[i];
		deck[i] = "empty";
	}
	for (int i = 0; i < 5; i++) {
		ComputerHand[i] = deck[i];
		deck[i] = "empty";
	}

	cout << "Welcome to Go Fish!" << endl << endl;
	while (PlayerScore + ComputerScore < 13) {
		//Game Turn Start: print important information
		cout << endl << endl << endl << "*************************************************" << endl;
		cout << "it is turn number " << TurnNumber << endl;
		if (turn == player) cout << "It is currently the human's turn." << endl;
		else cout << "It is currently the comuter's turn" << endl;
		cout << "you have " << PHandSize << " cards in your hand, and your opponent has " << CHandSize << endl;
		cout << "The scores are Player: " << PlayerScore << ", Computer: " << ComputerScore << endl << endl;
		system("pause");
		cout << endl << endl;

		switch (turn) {
		case player:
			sort(PlayerHand, PlayerHand + 51);
			sort(ComputerHand, ComputerHand + 51);
			cout << "your current hand: " << endl;
			for (int i = 0; i < 52; i++) {
				if (PlayerHand[i] != "empty") {
					cout << PlayerHand[i] << endl;
				}
			}

			//cull any sets of 4 that exist in player's hand
			for (int i = 0; i < 52; i++) {
				quads = 0; // this is a counter being reset

			//look at slot 0, and search slots 1-52 for that value, then look at slot 1 and search slots 2-52 for that value
				for (int j = i + 1; j < 51; j++) {
					if (PlayerHand[i].at(0)!= 'e'){ //dont count and empty slots as matches
						if (PlayerHand[i].at(0) == PlayerHand[j].at(0)) {
							quads++;
						}
						if (quads == 3) { //check if we have all 4 (remember we start counting at 0)
							match = PlayerHand[i].at(0); //hold onto the card type we got a match for
							PlayerScore++;
							cout << "you got all 4! Culling cards and giving you a point" << endl;
							for (int m = 0; m < 52; m++) {
								if (PlayerHand[m].at(0) == match) { // earse all the cards that have been matched
									PlayerHand[m] = "empty";
								}
							}
							cout << endl << "Your new hand: " << endl; // reshuffle your hand
							for (int i = 0; i < 52; i++) {
								if (PlayerHand[i].at(0) != 'e') {
									cout << PlayerHand[i] << endl;
								}
							}

						}
					}
				}

			}

			cout << endl << "What card are you looking for?" << endl;
			cin >> input;
			cout << input << endl;
			break;
		case computer:

			break;

		}
	}
}
