#include <string>
#include "Animal.h"
#include "Pierre.h"
#include "Attaque.h"
#include <cstdlib>
#include <ctime>
using namespace std;


Pierre::Pierre(int maxX, int maxY) : Animal(maxX,maxY){
    nom = "Pierre";
};

void Pierre::setAttaque(){
    this->typeAttaque = eType::PIERRE;
}

void Pierre::deplace(int maxX,int maxY){
}
