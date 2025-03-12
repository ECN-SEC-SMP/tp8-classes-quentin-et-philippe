#include <cstdlib>
#include <string>

enum eType {PIERRE = 0, FEUILLE = 1, CISEAUX = 2
};

class Attaque {

    

// Membres :

    private : eType m_type;
//---- 

// Constructeurs :

    public : 
        Attaque::Attaque(); 
        Attaque::Attaque(eType i_type);
//----

// Getters

        eType getTypeAttaque();
//----

// Methodes specifiques
        
        bool resoudreAttaque(Attaque &a);
//----

};


