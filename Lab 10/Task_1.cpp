#include <iostream>
using namespace std;

class BaseCharacter
{
    protected:
        string name;
        int health;
        int mana;
        int attackPower;
        string specialAbility;
        int specialAbilityPower;
        bool isAbilityAvailable;
        bool isDefendCalled;
        bool isCharacterAlive;
    public:
        BaseCharacter(string name, double health, int attackPower, string specialAbility, int specialAbilityPower)
        {
            this->name = name;
            this->health = health;
            this->mana = 0;
            this->attackPower = attackPower;
            this->specialAbilityPower = specialAbilityPower;
            this->specialAbility = specialAbility;
            isAbilityAvailable = false;
            isDefendCalled = false;
            isCharacterAlive = true;
        }

        int attack()
        {
            cout << name << " attacks with power " << attackPower << "!\n";
            int damageDeal = attackPower; 
            mana += 50;
            if(mana == 100)
            {
                isAbilityAvailable = true;
                damageDeal += useSpecialAbility();
            }
            return damageDeal;
        }

        int defend()
        {
            isDefendCalled = true;
        }

        void setDefend(bool type)
        {
            isDefendCalled = type;
        }

        int useSpecialAbility()
        {
            cout << name << " uses " << specialAbility << " with power " << specialAbilityPower << "!\n";
            mana = 0;
            isAbilityAvailable = false;
            return specialAbilityPower;
        }

        void displayStats()
        {
            cout << "Character name : " << name;
            cout << "\nHealth : " << health;
            cout << "\nMana : " << mana;
            cout << "\nMana status: ";
            if(mana < 100)
                cout << "Not Available";
            else
                cout << "Available";
            cout << "\nAttack Power : " << attackPower;
            cout << "\nSpecial Ability : " << specialAbility;
            cout << "\nSpecial Ability Power : " << specialAbilityPower << endl;
        }

        void takeDamage(int damage)
        {
            if(isDefendCalled)
                return;
            health -= damage;
            cout << name << " takes " << damage << " damage! Health now: " << health << "!\n"; 
            if(health <= 0)
            {
                isCharacterAlive = false;
                cout << name << " dies!";
            }
        }

        bool isAlive()
        {
            return isCharacterAlive;
        }
};

class Warrior : public BaseCharacter
{
    public:
        Warrior(int health, int attackPower, string specialAbility, int specialAbilityPower) : BaseCharacter("Warrior", health, attackPower, specialAbility, specialAbilityPower)
        {}
        
};

class Mage : public BaseCharacter
{
    public:
        Mage(int health, int attackPower, string specialAbility, int specialAbilityPower) : BaseCharacter("Mage", health, attackPower, specialAbility, specialAbilityPower)
        {}
        
};

class Archer : public BaseCharacter
{
    public:
        Archer(int health, int attackPower, string specialAbility, int specialAbilityPower) : BaseCharacter("Archer", health, attackPower, specialAbility, specialAbilityPower)
        {}
        
};


class Boss : public BaseCharacter
{
    public:
        Boss(int health, int attackPower) : BaseCharacter("Boss", health, attackPower, "", 0)
        {}
        
        int attack(string player)
        {
            cout << name << " attacks " << player << " with power " << attackPower << "!\n";
            return attackPower;
        }
};

class Game
{
    private:
        Warrior warrior;
        Mage mage;
        Archer archer;
        Boss boss;
        bool isPlayerTurn;
        bool isGameEnded;
        int playerAlive;
    public:
        Game() : warrior(100, 25, "Berserk Rage", 35), mage(120, 20, "Arcane Blast", 30), archer(90, 20, "Fire Arrow", 35), boss(150, 30)
        {
            cout << "Game begins! Players vs. Boss\n";
            isPlayerTurn = true;
            isGameEnded = false;
            playerAlive = 3;
        }

        void start()
        {
            while(!isGameEnded)
            {
                if(isPlayerTurn)
                    playerMove();
                else
                    bossMove();
            }
        }

        void playerMove()
        {
            char choice;

            cout << "Warrior's turn! Choose Attack/Defense (A/D) : ";
            cin >> choice;
            if(choice == 'A')
            {
                int warriorAttack = warrior.attack();
                boss.takeDamage(warriorAttack);
                if(!boss.isAlive())
                {
                    isGameEnded = true;
                    return;
                }
            }

            cout << "Mage's turn! Choose Attack/Defense (A/D) : ";
            cin >> choice;
            if(choice == 'A')
            {
                int mageAttack = mage.attack();
                boss.takeDamage(mageAttack);
                if(!boss.isAlive())
                {
                    isGameEnded = true;
                    return;
                }
            }

            cout << "Archer's turn! Choose Attack/Defense (A/D) : ";
            cin >> choice;
            if(choice == 'A')
            {
                int archerAttack = archer.attack();
                boss.takeDamage(archerAttack);
                if(!boss.isAlive())
                {
                    isGameEnded = true;
                    return;
                }
            }
            cout << endl;
            isPlayerTurn = false;
        }

        void bossMove()
        {
            warrior.takeDamage(boss.attack("Warrior"));
            if(!warrior.isAlive())
            {
                playerAlive--;
                if(playerAlive == 0)
                {
                    cout << "Boss wins! Player defeated!\n";
                    isGameEnded = true;
                    return;
                }
            }

            mage.takeDamage(boss.attack("Mage"));
            if(!mage.isAlive())
            {
                playerAlive--;
                if(playerAlive == 0)
                {
                    cout << "Boss wins! Player defeated!\n";
                    isGameEnded = true;
                    return;
                }
            }

            archer.takeDamage(boss.attack("Archer"));
            if(!archer.isAlive())
            {
                playerAlive--;
                if(playerAlive == 0)
                {
                    cout << "Boss wins! Player defeated!\n";
                    isGameEnded = true;
                    return;
                }
            }
            cout << endl;
            isPlayerTurn = true;
        }
};

int main()
{
    Game game;
    game.start();
}