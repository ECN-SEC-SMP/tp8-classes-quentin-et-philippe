#include <string>
#include "Animal.h"
using namespace std;


class Loup : public Animal{
    public :
        Loup(int maxX, int maxY);
        void setAttaque();
        void deplace(int maxX,int maxY);
};

