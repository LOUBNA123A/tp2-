#include <iostream>
#include <string>

using namespace std;

#ifndef HASH_H_INCLUDED
#define HASH_H_INCLUDED

class hash1{
    private:
    static const int tailleTableau = 10;

    struct item{
        string nom;
        string tel;
        string telCel;
        item* next;
    };

    item* HashTable[tailleTableau];

    public:
        int Hash(string cle);
        hash1();
        int  ajouterItem(string nom, string tel, string telCel);
        int  nombreItems(int index);
        void afficherItems();
        void afficherItemsDansIndex(int index); // les items qui ont le même resultat de hashage et qui sont empilés

};


#endif // HASH_H_INCLUDED
