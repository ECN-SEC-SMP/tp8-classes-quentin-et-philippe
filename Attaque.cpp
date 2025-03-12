#include "Attaque.h"
#include <cstdlib>
#include <string>



class Attaque {

    enum eType {PIERRE = 0, FEUILLE = 1, CISEAUX = 2
    };

// Membres :

    private : eType m_type;
//---- 

// Constructeurs :

    public : 
        Attaque::Attaque() {this->m_type = static_cast<eType>(rand() % 3 + 1);}; // Génère une attaque aleatoire
        Attaque::Attaque(eType i_type) {this->m_type = i_type;};
//----

// Getters

        eType getTypeAttaque() const {
            return this->m_type;
        }

        std::string getNomAttaque() const {

            switch (this->m_type) {

                case PIERRE : {
                    return "Pierre";
                }

                case FEUILLE : {
                    return "Feuille";
                    break;
                }

                case CISEAUX : {
                    return "Ciseaux";
                    break;
                }
            }
        }
//----

// Methodes specifiques
        
        bool resoudreAttaque(Attaque &a) const {
            
            switch (this->m_type) {

                case PIERRE : {

                    switch (a.m_type) {

                        case PIERRE : {
                            // Match nul
                            while (a.m_type == this->m_type) a.m_type = static_cast<eType>(rand() % 3 + 1);
                            resoudreAttaque(a);
                        }
        
                        case FEUILLE : {
                            return false;
                        }
        
                        case CISEAUX : {
                            return true;
                        }
                    }
                }

                case FEUILLE : {
                    switch (a.m_type) {

                        case PIERRE : {
                            return true;
                        }
        
                        case FEUILLE : {
                            // Match nul
                            while (a.m_type == this->m_type) a.m_type = static_cast<eType>(rand() % 3 + 1);
                            resoudreAttaque(a);
                        }
        
                        case CISEAUX : {
                            return false;
                        }
                    }
                }

                case CISEAUX : {
                    switch (a.m_type) {

                        case PIERRE : {
                            return false;
                        }
        
                        case FEUILLE : {
                            return true;
                        }
        
                        case CISEAUX : {
                            // Match nul
                            while (a.m_type == this->m_type) a.m_type = static_cast<eType>(rand() % 3 + 1);
                            resoudreAttaque(a);
                        }
                    }
                }
            }
        }
//----

};


