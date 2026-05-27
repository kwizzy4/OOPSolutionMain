#include "player.h"
#include <vector>
#include <cstdlib>

void autoFillPlayer(Player& p, int index) {
	string names[] = { "Lionel", "Cristiano", "Kylian", "Erling", "Kevin", "Luka", "Neymar", "Mohamed", "Sergio" };
	string positions[] = { "Forward", "Midfielder", "Defender", "Goalkeeper", "Winger" };

	string name = names[index % 10] + "Player";
	string position = positions[rand() % 5];
	int number = rand() % 99 + 1;
	int goals = rand() % 50;
	double rating = (rand() % 100) / 10.0;

	p.setName(name);
	p.setPosition(position);
	p.setNumber(number);
	p.setGoals(goals);
	p.setRating(rating);
}

// Manual player info input
void manualFillPlayer(Player& p) {
	string name, position;
	int number, goals;
	double rating;

	cout << "\n=== Enter Player Data ===\n";
	cout << "Name: ";
	cin.ignore();
	getline(cin, name);

	cout << "Position (Forward/Midfielder/Defender/Goalkeeper/Winger): ";
	getline(cin, position);

	cout << "Number(1-99): ";
	cin >> number;

	cout << "Goals scored: ";
	cin >> goals;

	cout << "Rating(0-10): ";
	cin >> rating;

	p.setName(name);
	p.setPosition(position);
	p.setNumber(number);
	p.setGoals(goals);
	p.setRating(rating);

	cout << "Player created succesfully!\n";
}

// Assignment operator demonstration
void demonstrateAssignment() {
	cout << "\n" << string(50, '=') << "\n";
	cout << "ASSIGNMENT OPERATOR DEMONSTRATION\n";
	cout << string(50, '=') << "\n";

	Player player1("Cristiano Ronaldo", "Forward", 7, 960, 9.8);
	Player player2("Lionel Messi", "Forward", 10, 850, 9.9);

	cout << "\nBefore assignment:\n";
	player1.displayInfo();
	player2.displayInfo();

	cout << "\nAssigning player2 = player1...\n";
	player2 = player1;

	cout << "\nAfter assignment:\n";
	player1.displayInfo();
	player2.displayInfo();

	cout << "\nConclusion: After assignment, player2 becomes a copy of player1.\n";
	cout << "The two objects are independent(deep copy was performed).\n";
}

int main() {
	srand(time(0));

	cout << "======================================\n";
	cout << "   FOOTBALL MANAGER SYSTEM\n";
	cout << "======================================\n";
	
	vector<Player> team;
	int choice;

	do
	{
		cout << "\n--- MENU --- \n";
		cout << "1. Add player (manual input)\n";
		cout << "2. Add player (auto-generated)\n";
		cout << "3. Show all players\n";
		cout << "4. Player scores a goal\n";
		cout << "5. Update player rating\n";
		cout << "6. Demonstrate assignment operator\n";
		cout << "7. Exit\n";
		cout << "Your choice: ";
		cin >> choice;

		switch (choice) {
		case 1: {
			Player newPlayer;
			manualFillPlayer(newPlayer);
			team.push_back(newPlayer);
			cout << "Player added to team! Team size: " << team.size() << "\n";
			break;
		} 
		case 2: {
			Player newPlayer;
			autoFillPlayer(newPlayer, team.size());
			team.push_back(newPlayer);
			cout << "Auto-generated player added!\n";
			team.back().displayInfo();
			break;
		}
		case 3: {
			if (team.empty()) {
				cout << "No players in the team yet!\n";
			}
			else {
				cout << "\n=== TEAM ROSTER ===\n";
				for (size_t i = 0; i < team.size(); i++) {
					cout << "\nPlayer #" << i + 1;

					team[i].displayInfo();
				}
			}
			break;
		}
		case 4: {
			if (team.empty()) {
				cout << "No players available!\n";
				break;
			}
			int idx;
			cout << "Enter player number(1-" << team.size() << "): ";
			cin >> idx;
			if (idx >= 1 && idx < +(int)team.size()) {
				team[idx - 1].scoreGoal();
			}
			else {
				cout << "Invalid player number!\n";
			}
			break;
		}
		case 5: {
			if (team.empty()) {
				cout << "No players available!\n";
				break;
			}
			int idx;
			double newRating;
			cout << "Enter player number(1-" << team.size() << "): ";
			cin >> idx;
			if (idx >= 1 && idx <= (int)team.size()) {
				cout << "Enter new rating (0-10): ";
				cin >> newRating;

				team[idx - 1].updateRating(newRating);
			}
			else {
				cout << "Imvalid player number!\n";
			}
			break;
		}
		case 6: {
			demonstrateAssignment();
			break;
		}
		case 7: {
			cout << "Goodbye! Thanks for using Football Manager System!\n";
			break;
		}
		default: {
			cout << "Invalid choice! Please try again.\n";
			break;
		}
		}
	} while (choice != 7);

	return 0;
}