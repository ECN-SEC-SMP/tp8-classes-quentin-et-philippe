#include <_stdlib.h>
#include <string>


class Attaque {

    enum eType {PIERRE = 0, FEUILLE = 1, CISEAUX = 2
    };

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


