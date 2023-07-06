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
};

// Function to generate a random number within a range
int generateRandomNumber(int min, int max) {
    return min + rand() % (max - min + 1);
}

class Game {
private:
    stack<Enemy> enemyStack;
    string collectedWeapons[12];  // Array to store collected weapons
    int numCollectedWeapons = 0;  // Number of weapons collected
    Weapon weapons[12];  // Array of weapons with their damage values

public:
    Game(): weapons{
        // Initialize weapons with their damage values
Weapon("Mace", 15),
Weapon("Sweet Steel", 20),
Weapon("Iron Flail", 25),
Weapon("Metal Pipe", 10),
Weapon("Katana", 30),
Weapon("Machete", 12),
Weapon("Machine Gun", 8),
Weapon("Shotgun", 18),
Weapon("Double Barrel Pistol", 16),
Weapon("Grenade Launcher", 1000), // Instant kill damage
Weapon("Sniper", 35),
Weapon("Ar15", 22),
    }{

        // Declare the names of the enemies and their assigned weapons
        string enemyNames[] = { "Mr. Gamma", "Enemy 2", "Enemy 3", "Enemy 4", "Dead(?) Body", "BossB", "Enemy 2B", "Enemy 3B", "Enemy 4B", "Enemy 5B" };
        string enemyWeapons[] = { "Mace", "Sweet Steel", "Iron Flail", "Metal Pipe", "Grenade Launcher","Machete","Machine Gun","Shotgun","Double Barrel Pistol", "Katana","Sniper", "Ar15"};

        // Push the enemies onto the stack with their assigned weapons and random health
        for (int i = 0; i < sizeof(enemyNames) / sizeof(enemyNames[0]); i++) {
            int enemyHealth = generateRandomNumber(50, 100);
            Enemy enemy(enemyNames[i], enemyWeapons[i], enemyHealth);
            enemyStack.push(enemy);
        }
    }

    // Function to check if the weapon is already collected
    bool isWeaponCollected(const string& weaponName) {
        for (int i = 0; i < numCollectedWeapons; i++) {
            if (collectedWeapons[i] == weaponName) {
                return true;
            }
        }
        return false;
    }

    // Function to collect a weapon
    void collectWeapon(const string& weaponName) {
        collectedWeapons[numCollectedWeapons] = weaponName;
        numCollectedWeapons++;
    }

   // Function to simulate the battle with an enemy using the selected weapon
    void battleEnemy(const Enemy& enemy, const string& weaponChoice) {
        // Find the selected weapon's damage
    int weaponDamage = 0;
    for (int i = 0; i < 12; i++) {
    if (weapons[i].name == weaponChoice) {
    weaponDamage = weapons[i].damage;
    break;
}
}
    // Ensure the weapon damage is valid
    if (weaponDamage == 0) {
        cout << "Invalid weapon choice.\n";
        return;
    }

    // Simulate the battle
    Enemy currentEnemy = enemy;
    while (currentEnemy.health > 0) {
        currentEnemy.health -= weaponDamage;

        // Ensure enemy health does not go below 0
        if (currentEnemy.health < 0) {
            currentEnemy.health = 0;
        }

        cout << "You attacked the enemy with " << weaponChoice << ". Enemy health: " << currentEnemy.health << endl;

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

// Function to run the game
void run() {
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
        if (isWeaponCollected(defeatedEnemy.weapon)) {
            cout << "You already have this weapon.\n";
            continue;
        }

        // Collect the weapon
        collectWeapon(defeatedEnemy.weapon);
        cout << "You collected: " << defeatedEnemy.weapon << endl;

        // Display collected weapons
        cout << "\nCollected weapons:\n";
        for (int i = 0; i < numCollectedWeapons; i++) {
            cout << "[" << (i + 1) << "] " << collectedWeapons[i] << "\n";
        }

        // Prompt user to select a weapon to use
        string weaponChoice;
        cout << "\nEnter the name of the weapon you want to use: ";
        getline(cin >> ws, weaponChoice);

        // Battle the enemy using the selected weapon
        battleEnemy(defeatedEnemy, weaponChoice);
    }

    cout << "\nAll enemies faced! Victory is yours!" << endl;
}
};

int main() {
    // Prompt the user to choose a scenario
    cout << "Welcome to the game!\n";
    cout << "Choose a scenario:\n";
    cout << "A. Scenario A\n";
    cout << "B. Scenario B\n";
    cout << "Enter your choice (A/B): ";

    string scenarioChoice;
    cin >> scenarioChoice;

    // Create a game object based on the chosen scenario
    Game game;

    // Run the game based on the chosen scenario
    if (scenarioChoice == "A" || scenarioChoice == "a") {
        cout << "Running Scenario A...\n";
        // Add code for Scenario A
    } else if (scenarioChoice == "B" || scenarioChoice == "b") {
        cout << "Running Scenario B...\n";
        // Add code for Scenario B
    } else {
        cout << "Invalid scenario choice. Exiting the game.\n";
        return 0;
    }

    // Run the game
    game.run();

    return 0;
}
