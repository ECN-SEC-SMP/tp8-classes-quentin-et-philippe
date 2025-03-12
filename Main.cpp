#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int maxX = 10;  
const int maxY = 10; 

// Fonction qui génère un tableau de taille maxX * maxY et le remplit
char** genererBoard() {
    srand(time(0)); // Initialisation du générateur aléatoire

    char v_animal[] = {'W', 'P', 'O', 'L'};

    // Allocation dynamique du tableau 2D
    char** board = new char*[maxX];
    for (int i = 0; i < maxX; ++i) {
        board[i] = new char[maxY];
    }

    int totalCells = maxX * maxY;
    int filledCells = totalCells / 4;  // 25% des cellules

    // Initialisation du tableau vide
    for (int i = 0; i < maxX; ++i) {
        for (int j = 0; j < maxY; ++j) {
            board[i][j] = ' ';  // Cellule vide
        }
    }

    // Remplissage de cellules avec des animaux
    for (int i = 0; i < filledCells; ++i) {
        int r = rand() % maxX;
        int c = rand() % maxY;

        // S'assurer que la cellule n'est pas déjà remplie
        while (board[r][c] != ' ') {
            r = rand() % maxX;
            c = rand() % maxY;
        }
        board[r][c] = v_animal[rand() % 4];  // Remplir la cellule avec une lettre
    }

    return board;
}

// Fonction qui affiche le tableau
void afficherBoard(char** i_board) {
    // Ligne supérieure
    for (int j = 0; j < maxY; ++j) {
        cout << "|----";
    }
    cout << "|" << endl;

    for (int i = 0; i < maxX; ++i) {
        for (int j = 0; j < maxY; ++j) {
            // Afficher la cellule avec sa bordure
            cout << "| " << i_board[i][j] << "  ";
        }
        cout << "|" << endl;

        // Ligne de séparation
        for (int j = 0; j < maxY; ++j) {
            cout << "|----";  // Bordure de cellule
        }
        cout << "|" << endl;
    }
}

int main() {

    char** board = genererBoard();
    afficherBoard(board);

    // Libérer la mémoire allouée
    for (int i = 0; i < maxX; ++i) {
        delete[] board[i];
    }
    delete[] board;

    return 0;
}
