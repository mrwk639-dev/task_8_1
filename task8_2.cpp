#include<string>
#include<random>
#include<iostream>
#include<vector>

using namespace std ;
class weapon {
private:
    string name;
    int damage;
    int accuracy;
public:
    weapon(string n, int d, int a){ 
        name=n;
        damage=d;
        accuracy=a;

    }
    string get_name(){ 
        return name;
     }
    int get_damage(){
        return damage;
     }
     bool hit(){//i use ai to write this function
        int random = rand() % 100 + 1;
       return random <= accuracy;
        }
};
class soldier {
protected:
    string name;
    int health;
public:
    soldier(string n, int h){ 
        name=n;
        health=h;
    }
    int get_health(){
        return health;
    }
    void stats(){
        cout<<"Name: "<<name<<"Health: "<<health<<endl;
    }
    void damage(int d){
        health-=d;
    }
    string get_name(){
        return name;
    }
    void attack(weapon w, soldier &opponent){// i use ai to write this function
    if (w.hit()){
        cout << name << " hits " << opponent.get_name()
             << " with " << w.get_name()
             << " for " << w.get_damage() << " damage!" << endl;
        opponent.damage(w.get_damage());
    } else {
        cout << name << " misses with " << w.get_name() << "!" << endl;
        }
    }
};


class optimus: public soldier {
public:
    vector<weapon> weapons;
    optimus(string n, int h, vector<weapon> w):soldier(n,h){
        weapons=w;
    }

};
class megatron: public soldier {
public:
    vector<weapon> weapons;
    megatron(string n, int h, vector<weapon> w):soldier(n,h){
        weapons=w;
    }
};

int main(){
    srand(time(0));
    vector<weapon> weapons_optimus={
        weapon("lon rifle",6,100),
        weapon("energon swords",12,80),
        weapon("shoulder canon",45,25)
    };
    vector<weapon> weapons_megatron={
        weapon("fusion cannon",9,90),
        weapon("fusion",18,70),
        weapon("tank mode",60,15)
    };

    optimus Optimus("Optimus Prime",100,weapons_optimus);
    megatron Megatron("Megatron",100,weapons_megatron);
    while (Optimus.get_health()>0 && Megatron.get_health()>0)
    {
        Optimus.attack(Optimus.weapons[rand()%weapons_optimus.size()], Megatron);
        Megatron.attack(Megatron.weapons[rand()%weapons_megatron.size()], Optimus);
        Optimus.stats();
        Megatron.stats();
        _sleep(1000);
    }
    if (Optimus.get_health()<=0)
    {
        cout<<"Megatron wins!"<<endl;
    }
    else
    {
        cout<<"Optimus wins!"<<endl;
    }
    
}