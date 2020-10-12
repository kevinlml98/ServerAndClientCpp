/**
 * @file floydwarshall.h
 * @version 1.1
 * @date 10/10/2020
 * @author kevinlml
 * @title Algoritmo de FloydWarshall
 * @brief Retorna la ruta mas corta entre dos nodos de un grafo con matrices de adyacensia
*/
#include <iostream>
#include <string>


using namespace std;

class FloydWarshall {
private:
    int infinit = 10000;
    int ma[5][5] = { 0, 4, 8, infinit, infinit,
                     4, 0, 1, 2, infinit,
                     8, infinit, 0, 4, 2,
                     infinit, 2, 4, 0, 7,
                     infinit, infinit, 2, 7, 0 };
    char mr[5][5] = { 'a','b','c','d','e',
                      'a','b','c','d','e',
                      'a','b','c','d','e',
                      'a','b','c','d','e',
                      'a','b','c','d','e' };

    char vec_nodos[5] = { 'a','b','c','d','e' };

    static int cambioNodo(char nodo) {
        switch (nodo) {
        case 'a':
            return 0;
        case 'b':
            return 1;
        case 'c':
            return 2;
        case 'd':
            return 3;
        case 'e':
            return 4;
        default:
            return 0;
        }

    }

public:

    FloydWarshall() {
        cout << "New floydwarshall object created" << endl;
        fwStart();
    }

    /**
     *
     */

    void fwStart() {

        for (int k = 0; k < 5; k++) {
            for (int i = 0; i < 5; i++) {
                for (int j = 0; j < 5; j++) {
                    int a = ma[i][j];
                    int b = ma[i][k] + ma[k][j];
                    if (a > b) {
                        ma[i][j] = b;
                        mr[i][j] = vec_nodos[k];
                    }
                }
            }
        }


    }



    /**
     * @see shortDistance() Retorna la distancia más corta entre dos nodos, máximo 20 nodos.
     * @param init_node Nodo inicial
     * @param finish_node Nodo final
     */
    void shortDistance(char* recvbuf, char* result) {

        int columna = cambioNodo(recvbuf[0]);
        int fila = cambioNodo(recvbuf[1]);
        char inode = recvbuf[0];
        char fnode = recvbuf[1];
        char fnodeaux = recvbuf[1];
        
        int c, aux, i = 1;
        bool wbool = true;

        /*
        string s = to_string(ma[fila][columna]);
        result[0] = s;
        */
        result[0] = inode;

        c = cambioNodo(inode);
        aux = cambioNodo(fnode);

        while (wbool) {
            if (c != aux) {
                fnodeaux = mr[aux][c];
                aux = cambioNodo(fnodeaux);
                result[i] = fnodeaux;
                i++;
            }
            else {
                wbool = false;
            }
        }

        result[i - 1] = fnode;
       

    }

    void printMR() {
        for (auto& i : mr) {
            for (char j : i) {
                cout << " " << j;
            }
            cout << endl;
        }

    }

    void printMA() {
        for (auto& i : ma) {
            for (int j : i) {
                cout << " " << j;
            }
            cout << endl;
        }

    }

};