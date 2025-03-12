#include <string>
#include "Animal.h"
#include "Loup.h"
#include "Attaque.h"
#include <cstdlib>
#include <ctime>
using namespace std;

Loup::Loup(int maxX, int maxY) : Animal(maxX,maxY){
    nom = "Loup";
};

void Loup::setAttaque(){
    this->typeAttaque = Attaque();
}

void Loup::deplace(int maxX,int maxY){
    this->x = rand() % maxX + 1;
    this->y = rand() % maxY + 1;
}
