#include <iostream>
using namespace std;

class Enemy{
    private:
        int healthValue;
    public:
        Enemy(){
            healthValue=5;
        }
       void setHealth(int health){
        healthValue=health;
       }
       int getHealth(){
        return healthValue;
       }
       void talk(){
        cout << "I am enemy. Runnnnn!!"<< endl;
       }

};

class vampire: public Enemy{
    public:
       vampire(){
        this->setHealth(10);
       }
       void talk(){
        cout << "I want to suck your blood"<< endl;
       }
       int duductHealth(){
        int health=getHealth();
        health-=1;
        return health;
       }
};

class werewolf : public Enemy{
    public:
       void talk(){
        cout << "I bite you"<< endl;
       }
       void moonTalk(){
        cout << "Aooooooo"<< endl;
       }

};

int main(){
    Enemy e;
    vampire v;
    werewolf w;
    e.talk();
    v.talk();
    int currHealth= v.duductHealth();
    cout << currHealth<< endl;

}
