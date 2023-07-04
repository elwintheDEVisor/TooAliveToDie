#include <iostream>

using namespace std;

int main() {
    cout << "Welcome to the Ultimate Attack Simulator!" << endl;

    // Character information
    string characterName;
    string characterWeapon;
    int level;

    // User input for character information
    cout << "Enter your character's name: ";
    getline(cin, characterName);

    cout << "Enter your character's weapon: ";
    getline(cin, characterWeapon);

    cout << "Enter your level: ";
    cin >> level;

    // Ultimate attack trigger
    string ultimateAttackInput;
    cout << "Do you want to use the ultimate attack? (yes/no): ";
    cin >> ultimateAttackInput;

    if (ultimateAttackInput == "yes") {
        cout << characterName << " unleashes the ultimate attack with their " << characterWeapon << "!" << endl;

        // Perform specific ultimate attack based on the character's weapon and level
        if (characterWeapon == "Melee") {
            if (level >= 1) {
                cout << characterName << " uses Bone Crusher! " << endl;
            } else {
                cout << characterName << " your ultimate bar needs to be full." << endl;
            }
        } else if (characterWeapon == "Ranger") {
            if (level >= 2) {
                cout << characterName << " uses Gunslinger! " << endl;
            } else {
                cout << characterName << " your ultimate bar needs to be full." << endl;
            }
        } else if (characterWeapon == "Tank") {
            if (level >= 3) {
                cout << characterName << " uses Fortify! " << endl;
            } else {
                cout << characterName << " your ultimate bar needs to be full." << endl;
            }
        } else {
            cout << "Unknown weapon. " << characterName << " is unable to perform the ultimate attack." << endl;
        }
    } else {
        cout << "No ultimate attack was used." << endl;
    }

    cout << "Thank you for using the Ultimate Attack Simulator. Goodbye!" << endl;

    return 0;
}
