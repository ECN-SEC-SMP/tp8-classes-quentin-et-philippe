#include <string>
#include "Animal.h"
using namespace std;


class Lion : public Animal{
    public :
        Lion(int maxX, int maxY);
        void setAttaque();
        void deplace(int maxX,int maxY);
        typedef void (*callBack)(int X, int Y); // Tableau de fonction de deplacements
        callBack callBacks[4] = {{nullptr}}; // On initialise a zero par securite
};

