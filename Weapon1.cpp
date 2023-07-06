#include <iostream>
#include <string>

using namespace std;

int main() {
    const int maxWeapons = 6;
    string collectedWeapons[maxWeapons];  // Array to store collected weapons
    int numCollectedWeapons = 0;  // Number of weapons collected

    // Simulating the enemy giving weapons
    cout << "An enemy gives you some weapons!\n";
    cout << "Enter the names of the weapons one by one:\n";

    while (numCollectedWeapons < maxWeapons) {
        string weapon;
        cout << "Enter weapon " << (numCollectedWeapons + 1) << ": ";
        getline(cin >> ws, weapon);

        // Collect the weapon
        collectedWeapons[numCollectedWeapons] = weapon;
        numCollectedWeapons++;

        cout << "You collected: " << weapon << "\n";
    }

    // Displaying collected weapons
    cout << "\nCollected weapons:\n";
    for (int i = 0; i < numCollectedWeapons; i++) {
        cout << "[" << (i + 1) << "] " << collectedWeapons[i] << "\n";
    }

    // Prompt user to select a weapon to use
    string weaponChoice;
    cout << "\nEnter the name of the weapon you want to use: ";
    getline(cin >> ws, weaponChoice);

    // Validate user's weapon choice
    bool weaponFound = false;
    for (int i = 0; i < numCollectedWeapons; i++) {
        if (collectedWeapons[i] == weaponChoice) {
            cout << "You selected weapon: " << collectedWeapons[i] << "\n";
            weaponFound = true;
            break;
        }
    }

    if (!weaponFound) {
        cout << "Invalid weapon choice.\n";
    }

    return 0;
}
