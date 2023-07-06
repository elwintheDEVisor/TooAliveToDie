#include <iostream>
#include <stack>
#include <string>
#include <cstdlib> // For generating random numbers

using namespace std;

class Enemy {
public:
    string name;
    string weapon;
    int health;

    Enemy(const string& name, const string& weapon, int health) : name(name), weapon(weapon), health(health) {}
};

class Weapon {
public:
    string name;
    int damage;

    Weapon(const string& name, int damage) : name(name), damage(damage) {}

    void grenadeLauncher(){

    }
};

// Function to generate a random number within a range
int generateRandomNumber(int min, int max) {
    return min + rand() % (max - min + 1);
}

int main() {
    const int maxWeapons = 12;
    const int maxEnemyHealth = 100;
    string collectedWeapons[maxWeapons];  // Array to store collected weapons
    int numCollectedWeapons = 0;  // Number of weapons collected

    stack<Enemy> enemyStack;

    // Declare the names of the enemies and their assigned weapons for Scenario A
    string enemyNamesScenarioA[] = { "Mr. Gamma", "Enemy 2", "Enemy 3", "Enemy 4", "Dead(?) Body"};
    string enemyWeaponsScenarioA[] = { "Grenade Launcher", "Sweet Steel", "Iron Flail", "Metal Pipe", "Katana"};

    // Declare the names of the enemies and their assigned weapons for Scenario B
    string enemyNamesScenarioB[] = { "BossB", "Enemy 2B", "Enemy 3B", "Enemy 4B", "Enemy 5B" };
    string enemyWeaponsScenarioB[] = {"Machete","Machine Gun","Shotgun","Double Barrel Pistol", "Mace","Sniper", "Ar15" };

    // Prompt the user to select a scenario
    cout << "Select a scenario:\n";
    cout << "A - Scenario A\n";
    cout << "B - Scenario B\n";
    char scenarioChoice;
    cout << "Enter your choice: ";
    cin >> scenarioChoice;

    // Determine the enemy names and weapons based on the selected scenario
    string* enemyNames;
    string* enemyWeapons;
    int numEnemies;
    if (scenarioChoice == 'A' || scenarioChoice == 'a') {
        enemyNames = enemyNamesScenarioA;
        enemyWeapons = enemyWeaponsScenarioA;
        numEnemies = sizeof(enemyNamesScenarioA) / sizeof(enemyNamesScenarioA[0]);
    } else if (scenarioChoice == 'B' || scenarioChoice == 'b') {
        enemyNames = enemyNamesScenarioB;
        enemyWeapons = enemyWeaponsScenarioB;
        numEnemies = sizeof(enemyNamesScenarioB) / sizeof(enemyNamesScenarioB[0]);
    } else {
        cout << "Invalid scenario choice.\n";
        return 0;
    }

    // Push the enemies onto the stack with their assigned weapons and random health
    for (int i = 0; i < numEnemies; i++) {
        int enemyHealth = generateRandomNumber(50, maxEnemyHealth);
        Enemy enemy(enemyNames[i], enemyWeapons[i], enemyHealth);
        enemyStack.push(enemy);
    }

    cout << "Prepare for battle!" << endl;

    // Face each enemy one by one during the battle
    while (!enemyStack.empty()) {
        cout << "\nA new enemy approaches: " << enemyStack.top().name << "!" << endl;

        // Prompt the user to face the enemy
        cout << "Press any key to face the enemy...";
        cin.ignore();  // Ignore any previous newline characters
        cin.get();     // Wait for user input

        // Remove the enemy from the stack after facing
        Enemy defeatedEnemy = enemyStack.top();
        enemyStack.pop();

        // Simulating the enemy dropping a weapon
        cout << "The enemy dropped a weapon: " << defeatedEnemy.weapon << endl;

        // Check if the weapon is already collected
        bool weaponFound = false;
        for (int i = 0; i < numCollectedWeapons; i++) {
            if (collectedWeapons[i] == defeatedEnemy.weapon) {
                weaponFound = true;
                break;
            }
        }

        // Collect the weapon if it's not already collected
        if (!weaponFound) {
            collectedWeapons[numCollectedWeapons] = defeatedEnemy.weapon;
            numCollectedWeapons++;
            cout << "You collected: " << defeatedEnemy.weapon << endl;
        } else {
            cout << "You already have this weapon.\n";
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

        // Validate user's weapon choice and get the selected weapon's damage
        int weaponDamage = 0;
        bool weaponChoiceFound = false;
        for (int i = 0; i < numCollectedWeapons; i++) {
            if (collectedWeapons[i] == weaponChoice) {
                cout << "You selected weapon: " << collectedWeapons[i] << "\n";
                weaponChoiceFound = true;

                // Assign the damage of the selected weapon
                // Customize the damage values for each weapon as desired
                if (collectedWeapons[i] == "Mace") {
                    weaponDamage = 15;
                } else if (collectedWeapons[i] == "Sweet Steel") {
                    weaponDamage = 20;
                } else if (collectedWeapons[i] == "Iron Flail") {
                    weaponDamage = 25;
                } else if (collectedWeapons[i] == "Metal Pipe") {
                    weaponDamage = 10;
                } else if (collectedWeapons[i] == "Katana") {
                    weaponDamage = 30;
                } else if (collectedWeapons[i] == "Machete") {
                    weaponDamage = 12;
                } else if (collectedWeapons[i] == "Machine Gun") {
                    weaponDamage = 8;
                } else if (collectedWeapons[i] == "Shotgun") {
                    weaponDamage = 18;
                } else if (collectedWeapons[i] == "Double Barrel Pistol") {
                    weaponDamage = 16;
                } else if (collectedWeapons[i] == "Grenade Launcher") {
                    // Set grenade launcher damage to instantly kill the enemy
                    weaponDamage = defeatedEnemy.health;
                } else if (collectedWeapons[i] == "Sniper") {
                    weaponDamage = 35;
                } else if (collectedWeapons[i] == "Ar15") {
                    weaponDamage = 22;
                }

                break;
            }
        }

        if (!weaponChoiceFound) {
            cout << "Invalid weapon choice.\n";
            continue;
        }

        // Simulate battle with the enemy using the selected weapon
        while (defeatedEnemy.health > 0) {
            defeatedEnemy.health -= weaponDamage;

            //Ensure enemy health does not go below 0
            if (defeatedEnemy.health < 0) {
                defeatedEnemy.health = 0;
            }

            cout << "You attacked the enemy with " << weaponChoice << ". Enemy health: " << defeatedEnemy.health << endl;

            // Simulate enemy attacking back (optional)
            // Uncomment the code below to include enemy's attack
            /*
            int enemyDamage = generateRandomNumber(5, 15);
            // Subtract enemy's damage from player's health (assuming the player's health is being tracked)
            playerHealth -= enemyDamage;
            cout << "The enemy counterattacks! Player health: " << playerHealth << endl;
            */

            // Wait for user input to continue the battle
            cout << "Press any key to continue the battle...";
            cin.ignore();
            cin.get();
        }

        cout << "You defeated the enemy!" << endl;
    }

    cout << "\nAll enemies faced! Victory is yours!" << endl;

    return 0;
}
