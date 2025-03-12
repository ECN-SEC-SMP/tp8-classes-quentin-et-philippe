#include <string>
#include "Animal.h"
using namespace std;

class Pierre : public Animal{
    public :
        Pierre(int maxX, int maxY);
        void setAttaque();
        void deplace(int maxX,int maxY);
};

