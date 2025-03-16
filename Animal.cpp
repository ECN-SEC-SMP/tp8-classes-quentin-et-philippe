#include <string>
#include "Animal.h"
#include "Attaque.h"
#include <cstdlib>
#include <ctime>
#include "Attaque.h"
using namespace std;

Animal::Animal(int maxX, int maxY){
    this->x = rand() % maxX + 1;
    this->y = rand() % maxY + 1;
    this->vivant = 1;
}

Animal::Animal(int maxX, int maxY, int a, int b){
    if (a<=maxX && a >= 0) this->x = a ;
    else this->x = rand() % maxX + 1;

    if (b<=maxY && b >= 0) this->y = b ;
    else this->y = rand() % maxY + 1;
    this->vivant = 1;
    
}

string Animal::getNom()const{return nom;};

int Animal::getX() const{return x;};

int Animal::getY() const{return y;};

bool Animal::getVivant() const{return vivant;};

Attaque Animal::getAttaque()const{return typeAttaque;};

int Animal::getNbDeplacements() {return this->nBDeplacement;};

void Animal::incrementerNbDeplacements() {this->nBDeplacement++;};

void Animal::setVivant(bool v){vivant = v;};
 
bool Animal::attaque(Animal &a){
    this -> setAttaque();
    Attaque attaqueadverse = a.getAttaque();//on récupère l'attaque adverse
    bool victoire = typeAttaque.resoudreAttaque(attaqueadverse); // on résout le duel

    if (victoire) a.setVivant(0);// on précise la mort ou non 
    else this->setVivant(0);

    return victoire; //renvoie l'état du combat (1 = victoire)
};

