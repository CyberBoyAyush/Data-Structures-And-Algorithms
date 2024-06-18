#include<bits/stdc++.h>
using namespace std;

class Hero{
    //properties

    public: // we can use the properties below public anywhere in the code 
    // private: // we can only use properties below private in the class only
    int health;
    char level;

    // Getters And Setters --> Functions we write to fetch of push values in classes.

    //Getters
    int gethealth(){
        return health;
    }

    char getlevel(){
        return level;
    }

    // Setters-- It sets the value
    void sethealth(int h){
        health = h;
    }

    void setlevel(int h){
        level = h;
    }

    // Constructor
    Hero(){
        cout<<"Constructor Called"<<endl;
    }

    /*
    //Parametriseed Constructor
    Hero(int health,char level){
        this->health = health; // we use this keyword here which means first health is the health in object the second health is the one in the constructor.
        this->level = level;
    } 
    */
   /*
    // Copy Constructor
    Hero(Hero &sharma){
        this -> health = sharma.health;
        this->level = sharma.level;

    }
    */
    
    };

int main(){
    // Object

    // Static Allocation --> Calling Constructor ayush.Hero()
    Hero ayush; 

    // Dynamic ALlocation --> In Heap
    Hero *b = new Hero;


    // Copy constructor
    Hero sharma(ayush); // It copies all vlaues in ayush to sharma

    cout<<"Health: "<< (*b).health<<endl;
    cout<<"Level: " << (*b).getlevel()<<endl;

    //
    ayush.health = 100;
    ayush.level = 'L';

    cout<<"Health from Getter: "<< ayush.gethealth()<<endl;

    // Setting value from setter to main functions
    ayush.sethealth(200);

    cout<<"Health: "<< ayush.health<<endl;
    cout<<"level: "<< ayush.level<<endl;


    cout<<"Size of Hero Class is "<<sizeof(ayush);
}