#include <iostream>
#include "candybar.h"
#include <iostream>
using namespace std;

void setCandyBar(CandyBar& cb) {
	cout << "Enter brand name of a Candy bar: ";
	cin.get(cb.brand, 20);
	cout << "Enter weight of the Candy bar: ";
	cin >> cb.weight;
	cout << "Enter calories (an integer value) in the Candy bar: ";
	cin >> cb.calorie;
	cout << endl;
	cin.ignore();
}

void setCandyBar(CandyBar* cb) {
	cout << "Enter brand name of a Candy bar: ";
	cin.get(cb->brand, 20);
	cout << "Enter weight of the Candy bar: ";
	cin >> cb->weight;
	cout << "Enter calories (an integer value) in the Candy bar: ";
	cin >> cb->calorie;
	cout << endl;
	cin.ignore();
}

void showCandyBar(const CandyBar& cb) {
	cout << "Brand: " << cb.brand << endl;
	cout << "Weight: " << cb.weight << endl;
	cout << "Calories: " << cb.calorie << endl;
	cout << endl;
}

void showCandyBar(const CandyBar* cb) {
	cout << "Brand: " << cb->brand << endl;
	cout << "Weight: " << cb->weight << endl;
	cout << "Calories: " << cb->calorie << endl;
	cout << endl;
}
