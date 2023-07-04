#include <iostream>
#include <string>

using namespace std;

int main() {
    const int numWeapons = 6;
    string weapons[numWeapons];  // Array to store weapons

    // Collecting weapons using a for loop
    for (int i = 0; i < numWeapons; i++) {
        cout << "Enter weapon " << (i + 1) << " to collect: ";
        getline(cin >> ws, weapons[i]);
    }

    // Displaying collected weapons
    cout << "\nCollected weapons:\n";
    for (int i = 0; i < numWeapons; i++) {
        cout << "[" << (i + 1) << "] " << weapons[i] << "\n";
    }

    // Prompt user to select a weapon to use
    string weaponChoice;
    cout << "\nEnter the name of the weapon you want to use: ";
    getline(cin >> ws, weaponChoice);

    // Validate user's weapon choice
    bool weaponFound = false;
    for (int i = 0; i < numWeapons; i++) {
        if (weapons[i] == weaponChoice) {
            cout << "You selected weapon: " << weapons[i] << "\n";
            weaponFound = true;
            break;
        }
    }

    if (!weaponFound) {
        cout << "Invalid weapon choice.\n";
    }

    return 0;
}
