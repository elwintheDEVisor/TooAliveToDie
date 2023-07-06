#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Enemy {
public:
    string name;

    Enemy(const string& name) : name(name) {}
};

int main() {
    stack<Enemy> enemyStack;

    // Declare the names of the enemies
    string enemyNames[] = { "Mr. Gamma", "Enemy 2", "Enemy 3", "Enemy 4", "Dead(?) Body" };

    // Push the enemies onto the stack
    for (const auto& name : enemyNames) {
        Enemy enemy(name);
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
        enemyStack.pop();
    }

    cout << "\nAll enemies faced! Victory is yours!" << endl;

    return 0;
}
