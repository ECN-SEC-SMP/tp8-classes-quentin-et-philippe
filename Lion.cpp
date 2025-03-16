#include <string>
#include "Animal.h"
#include "Lion.h"
#include "Attaque.h"
#include <cstdlib>
#include <ctime>

using namespace std;

Lion::Lion(int maxX, int maxY) : Animal(maxX,maxY){
    nom = "Lion";
};

void Lion::setAttaque(){
    this->typeAttaque = Attaque();
}

void Lion::deplace(int maxX,int maxY){
    this->x = rand() % maxX + 1;
    this->y = rand() % maxY + 1;
}

Lion::callBack callBacks[4] = {this->&x+=1, this ->&y+=1} 
