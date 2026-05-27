#include "player.h"
#include <iomanip>

Player::Player() {
	name = "Unknown";
	position = "Bench";
	number = 0;
	goals = 0;
	rating = 6.0;
}

Player::Player(string n, string p, int num, int g, double r) {
	name = n;
	position = p;
	number = num;
	goals = g;

	// Fool-protection for wrong rating
	if (r >= 0 && r <= 10) {
		rating = r;
	}
	else {
		rating = 6.0;
	}
}

// Getters
string Player::getName() const {
	return name;
}
string Player::getPosition() const {
	return position;
}
int Player::getNumber() const {
	return number;
}
int Player::getGoals() const {
	return goals;
}
double Player::getRating() const {
	return rating;
}

// Setters with defense
void Player::setName(string n) {
	name = n;
}
void Player::setPosition(string p) {
	position = p;
}
void Player::setNumber(int num) {
	if (num >= 1 && num <= 99) {
		number = num;
	}
	else {
		cout << "Invalid number! Set to 0.\n";
		number = 0;
	}
}

void Player::setGoals(int g) {
	if (g >= 0) {
		goals = g;
	}
	else {
		cout << "Goals cannot be negative! Set to 0.\n";
		goals = 0;
	}
}

void Player::setRating(double r) {
	if (r >= 0 && r <= 10) {
		rating = r;
	}
	else {
		cout << "Rating must be between 0 and 10! Set to 6.0.\n";
		rating = 6.0;
	}
}

// Show player info
void Player::displayInfo() const {
	cout << "\n=== Player Info ===\n";
	cout << "Name: " << name << "\n";
	cout << "Position: " << position << "\n";
	cout << "Number: " << number << "\n";
	cout << "Goals: " << goals << "\n";
	cout << "Rating: " << fixed << setprecision(1) << rating << "/10\n";
	cout << "==================\n";
}

// Score a goal
void Player::scoreGoal() {
	goals++;
	cout << name << " scored a goal! Total goals: " << goals << "\n";
}

// Update rating
void Player::updateRating(double newRating) {
	if (newRating >= 0 && newRating <= 10) {
		rating = newRating;
		cout << name << "'s rating updated to " << rating << "\n";
	}
	else {
		cout << "Invalid rating! Must be between 0 and 10.\n";
	}
}

// Assignment operator
Player& Player::operator=(const Player& other) {
	cout << "\n=== Assignment operator called ===\n";
	if (this != &other) {
		name = other.name;
		position = other.position;
		number = other.number;
		goals = other.goals;
		rating = other.rating;
		cout << "Player data copied succesfully!\n";
	}
	else {
		cout << "Self-assignment detected. No changes made.\n";
	}
	return *this;
}