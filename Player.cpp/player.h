#include <iostream>
#include <string>
using namespace std;

class Player {
private:
	string name;
	string position;
	int number;
	int goals;
	double rating;
public:
	Player();
	Player(string n, string p, int num, int g, double r);

	// Getters
	string getName() const;
	string getPosition() const;
	int getNumber() const;
	int getGoals() const;
	double getRating() const;

	// Setters
	void setName(string n);
	void setPosition(string p);
	void setNumber(int num);
	void setGoals(int g);
	void setRating(double r);

	// Methods
	void displayInfo() const;
	void scoreGoal();
	void updateRating(double newRating);

	// Assignment operator
	Player& operator = (const Player& other);
};