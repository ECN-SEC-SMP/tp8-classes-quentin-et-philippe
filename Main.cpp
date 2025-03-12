#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Lion.h"
#include "Loup.h"
#include "Ours.h"

using namespace std;

/* ---------------------INIT PREALABLES AU JEU ---------------------- */
int cptTour = 0;
bool jeuPossible = true;
char actionJoueur = ' ';
const int maxX = 10;  
const int maxY = 10; 

// Fonction qui génère un tableau de taille maxX * maxY et le remplit
string** genererBoard() {
    srand(time(0)); // Initialisation du générateur aléatoire

    std::string v_animal[] = {"W", "S", "B", "L"};

    // Allocation dynamique du tableau 2D
    std::string** board = new std::string*[maxX];
    for (int i = 0; i < maxX; ++i) {
        board[i] = new std::string[maxY];
    }

    int totalCells = maxX * maxY;
    int filledCells = totalCells / 4;  // 25% des cellules

    // Initialisation du tableau vide
    for (int i = 0; i < maxX; ++i) {
        for (int j = 0; j < maxY; ++j) {
            board[i][j] = " ";  // Cellule vide
        }
    }

    // Remplissage de cellules avec des animaux
    for (int i = 0; i < filledCells; ++i) {
        int r = rand() % maxX;
        int c = rand() % maxY;

        // S"assurer que la cellule n"est pas déjà remplie
        while (board[r][c] != " ") {
            r = rand() % maxX;
            c = rand() % maxY;
        }
        board[r][c] = v_animal[rand() % 4];  // Remplir la cellule avec une lettre
    }

    return board;
}


// Fonction qui affiche le tableau
void afficherBoard(std::string** i_board) {
    int nombreAnimauxVivants = 0;
    // Ligne supérieure
    for (int j = 0; j < maxY; ++j) {
        cout << "|----";
    }
    cout << "|" << endl;

    for (int i = 0; i < maxX; ++i) {
        for (int j = 0; j < maxY; ++j) {
            // Afficher la cellule avec sa bordure
            if (i_board[i][j] != " ") nombreAnimauxVivants++;
            cout << "| " << i_board[i][j] << "  ";
        }
        cout << "|" << endl;

        // Ligne de séparation
        for (int j = 0; j < maxY; ++j) {
            cout << "|----";  // Bordure de cellule
        }
        cout << "|" << endl;
    }
    cout << "Nombre d'animaux vivants : " << nombreAnimauxVivants << endl;
}
/* ------------------------------------------------ */

/* ---------------------FONCTIONS DE JEU ---------------------- */
void deplacementAnimaux(string **i_board) {
    string cellule;
    for (int ligne = 0; ligne < maxX; ligne++) {
        for (int col = 0; col < maxY; col++) {

            cellule = i_board[ligne][col];

            if (i_board[ligne][col] != " ") {
                for (int chaqueAnimal = 0; chaqueAnimal < size(cellule); chaqueAnimal++) {

                    switch (cellule[chaqueAnimal]) {

                        // "Pierre - Stone"
                        case 'S': {
                            //Un pierre ne peut se deplacer... Bien que chacun le sait : pierre qui **roule** n'amasse pas mousse...
                            break;
                        }

                        // "Loup - Wolf"
                        case 'W': {

                            Loup* currentLoup = new Loup(ligne, col); // Instanciation d'un Loup
                            currentLoup->deplace(ligne, col); // deplace par rapport a l'origine

                            if (i_board[currentLoup->getX()][currentLoup->getY()] = ' ') i_board[currentLoup->getX()][currentLoup->getY()] = 'L'; // La case etait vide, on remplace le carac vide par L
                            else i_board[currentLoup->getX()][currentLoup->getY()]+= 'L'; // La case n'est pas vide, on ajoute a la fin de la chaine
                             
                            break;
                        }

                        // "Lion - Lion "
                        case 'L': {

                            Lion* currentLion = new Lion(ligne, col); // Instanciation d'un Lion
                            currentLion->deplace(ligne, col); // deplace par rapport a l'origine

                            int XCorrige = 0;
                            int YCorrige = 0;
                    
                            //TODO : Gérer le cas de débord

                            if (currentLion->getX() >= maxX) XCorrige = currentLion->getX() - maxX; //Traite le cas X > taille de plateau
                            if (currentLion->getX() <= maxX) XCorrige =  maxX - currentLion->getX(); //Traite le cas X < taille de plateau
                            
                            if (currentLion->getY() >= maxY) YCorrige = currentLion->getY() - maxY; //Traite le cas Y > taille de plateau
                            if (currentLion->getY() <= maxY) YCorrige =  maxY - currentLion->getY(); //Traite le cas Y < taille de plateau
                            
                            

                            if (XCorrige != 0) {

                                if (YCorrige != 0) { 
                                    // Pas de correction en X ni en Y
                                    if (i_board[currentLion->getX()][currentLion->getY()] = ' ') i_board[currentLion->getX()][currentLion->getY()] = 'L'; // La case etait vide, on remplace le carac vide par L
                                    else i_board[currentLion->getX()][currentLion->getY()]+= 'L'; // La case n'est pas vide, on ajoute a la fin de la chaine
                                } 
                                else {
                                    // Correction uniquement en Y 
                                    if (i_board[currentLion->getX()][YCorrige] = ' ') i_board[currentLion->getX()][YCorrige->getY()] = 'L'; // La case etait vide, on remplace le carac vide par L
                                    else i_board[currentLion->getX()][YCorrige]+= 'L'; // La case n'est pas vide, on ajoute a la fin de la chaine
                                }
                            }

                            else {

                                if (YCorrige != 0) { 
                                    // Correction uniquement en X
                                    if (i_board[XCorrige][currentLion->getY()] = ' ') i_board[XCorrige][currentLion->getY()] = 'L'; // La case etait vide, on remplace le carac vide par L
                                    else i_board[XCorrige][currentLion->getY()]+= 'L'; // La case n'est pas vide, on ajoute a la fin de la chaine
                                } 
                                else {
                                    // Correction en X et en Y 
                                    if (i_board[XCorrige][YCorrige] = ' ') i_board[XCorrige][YCorrige] = 'L'; // La case etait vide, on remplace le carac vide par L
                                    else i_board[XCorrige][YCorrige]+= 'L'; // La case n'est pas vide, on ajoute a la fin de la chaine
                                }
                            }  

                            break;
                        }

                        // "Ours - Ours "
                        case 'B': {

                            Ours* currentOurs = new Ours(ligne, col); // Instanciation d'un Ours
                            currentOurs->deplace(ligne, col); // deplace par rapport a l'origine

                            int XCorrige = 0;
                            int YCorrige = 0;
                    
                            //TODO : Gérer le cas de débord

                            if (currentOurs->getX() >= maxX) XCorrige = currentOurs->getX() - maxX; //Traite le cas X > taille de plateau
                            if (currentOurs->getX() <= maxX) XCorrige =  maxX - currentOurs->getX(); //Traite le cas X < taille de plateau
                            
                            if (currentOurs->getY() >= maxY) YCorrige = currentOurs->getY() - maxY; //Traite le cas Y > taille de plateau
                            if (currentOurs->getY() <= maxY) YCorrige =  maxY - currentOurs->getY(); //Traite le cas Y < taille de plateau
                            
                            

                            if (XCorrige != 0) {

                                if (YCorrige != 0) { 
                                    // Pas de correction en X ni en Y
                                    if (i_board[currentOurs->getX()][currentOurs->getY()] = ' ') i_board[currentOurs->getX()][currentOurs->getY()] = 'L'; // La case etait vide, on remplace le carac vide par L
                                    else i_board[currentOurs->getX()][currentOurs->getY()]+= 'L'; // La case n'est pas vide, on ajoute a la fin de la chaine
                                } 
                                else {
                                    // Correction uniquement en Y 
                                    if (i_board[currentOurs->getX()][YCorrige] = ' ') i_board[currentOurs->getX()][YCorrige->getY()] = 'L'; // La case etait vide, on remplace le carac vide par L
                                    else i_board[currentOurs->getX()][YCorrige]+= 'L'; // La case n'est pas vide, on ajoute a la fin de la chaine
                                }
                            }

                            else {

                                if (YCorrige != 0) { 
                                    // Correction uniquement en X
                                    if (i_board[XCorrige][currentOurs->getY()] = ' ') i_board[XCorrige][currentOurs->getY()] = 'L'; // La case etait vide, on remplace le carac vide par L
                                    else i_board[XCorrige][currentOurs->getY()]+= 'L'; // La case n'est pas vide, on ajoute a la fin de la chaine
                                } 
                                else {
                                    // Correction en X et en Y 
                                    if (i_board[XCorrige][YCorrige] = ' ') i_board[XCorrige][YCorrige] = 'L'; // La case etait vide, on remplace le carac vide par L
                                    else i_board[XCorrige][YCorrige]+= 'L'; // La case n'est pas vide, on ajoute a la fin de la chaine
                                }
                            }  
                            break;

                        

                    }
                    if (cellule[chaqueAnimal] != 'S') cellule.erase(chaqueAnimal, 1); // Supprime l'animal de la case actuelle sauf si c'est une pierre
                }
            }
        }
    }
}

void jeu() {

    if (jeuPossible) {
        cout << "--- Appuyez sur la touche Y puis Enter pour continuer, sur N pour arreter le jeu. ---" << endl;

        cin >> actionJoueur;

        if (actionJoueur == 'Y' || actionJoueur == 'y') {
            cptTour++;
            deplacementAnimaux();
            roundAttaque();
        } else if (actionJoueur == 'N' || actionJoueur == 'n') {
            jeuPossible = false;
            game();
        }
    } else {
        cout << "Merci d'avoir jouer. Relancez pour une nouvelle partie" << endl;
        jeuPossible = false;

        return;
    }
    
}

int main() {

    std::string** board = genererBoard();
    afficherBoard(board);

    // Libérer la mémoire allouée
    for (int i = 0; i < maxX; ++i) {
        delete[] board[i];
    }
    delete[] board;

    return 0;
}
