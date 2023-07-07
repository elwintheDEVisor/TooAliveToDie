#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Enemy {
public:
    Enemy(const string& name, int currentHp, int maxHp, int damage)
        : name(name), currentHp(currentHp), maxHp(maxHp), damage(damage) {}

    void printInfo() const {
        cout << "Name: " << name << endl;
        cout << "CurrentHp: " << currentHp << endl;
        cout << "MaxHp: " << maxHp << endl;
        cout << "Damage: " << damage << endl;
    }

    void takeDamage(int damage) {
        currentHp -= damage;
    }

    bool isDefeated() const {
        return currentHp <= 0;
    }

private:
    string name;
    int currentHp;
    int maxHp;
    int damage;
};

int main() {
    stack<Enemy> enemyStack;
    enemyStack.push(Enemy("BOSS A1", 75, 100, 60));
    enemyStack.push(Enemy("Enemy4 A1", 65, 100, 50));
    enemyStack.push(Enemy("Enemy3 A1", 55, 100, 40));
    enemyStack.push(Enemy("Enemy2 A1", 45, 100, 30));
    enemyStack.push(Enemy("Dead(?) Body - Weak", 35, 100, 20));

    while (!enemyStack.empty()) {
        Enemy& enemy = enemyStack.top();
        enemy.printInfo();
        cout << "------------" << endl;

        cout << "Press any key to attack this enemy: ";
        cin.ignore();
        cin.get();

        enemy.takeDamage(35);

        if (enemy.isDefeated()) {
            cout << "Enemy defeated!" << endl;
            enemyStack.pop();
        }

        cout << "Remaining enemies in the stack: " << enemyStack.size() << endl;
        cout << "------------" << endl;
    }

    cout << "No more enemies in the stack!" << endl;

    return 0;
}
