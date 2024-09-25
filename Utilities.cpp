#include "Utilities.h"
#include <iostream>
using namespace std;

int ShowReadMenu(const vector<string>& choices) {
    cout << "Menu:\n";
    for (int i = 0; i < choices.size(); ++i) {
        cout << "\t" << (i + 1) << ") " << choices[i] << "\n";
    }
    cout << "\nEnter choice: ";
    int choice;
    cin >> choice;

    // To prevent invalid choices
    if (choice < 1 || choice > choices.size()) {
        cout << "Invalid choice. Please try again.\n";
        return ShowReadMenu(choices);  // Recursive call until valid choice
    }

    return choice;
}
