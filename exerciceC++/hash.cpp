#include <iostream>
#include <string>
#include "hash.h"

using namespace std;

void hash1::afficherItemsDansIndex(int index){
    item* ptr = HashTable[index];
    if (ptr->nom == "empty"){
        cout << "index vide " << index << endl;
    }
    else {
        cout << "--liste des items qui ont le meme index meme case du tableau--" << endl;
        cout << "l index =  " << index << " Contient des items" ;
        // on lit en profondeur le contenu d une case du tableau
        while (ptr != NULL){
            cout << "     ----------\n";
            cout << ptr->nom << endl;
            cout << ptr->tel << endl;
            cout << ptr->telCel << endl;
            cout << "     ----------\n";
            ptr= ptr->next;
        }
    }
}

void hash1::afficherItems(){
    int compteurItem =0;
    for(int i=0; i<tailleTableau; i++){
        compteurItem = nombreItems(i);
        cout <<"-------------\n";
        cout << "index = "  << i << endl;
        cout << HashTable[i]->nom  << endl;
        cout << HashTable[i]->tel  << endl;
        cout << HashTable[i]->telCel << endl;
        cout << " # des items = " << compteurItem << endl;
        cout <<"-------------\n";
    }
}

int hash1::nombreItems(int index){
    int nbItem =0;
    if (HashTable[index]->nom == "empty"){
        return nbItem;
    }
    else {
        nbItem ++;
        item* ptr = HashTable[index];
        while (ptr->next!=NULL){
            nbItem ++;
            ptr= ptr->next;
        }
    return nbItem;
    }

}



int hash1::ajouterItem(string nom, string tel, string telCel){
    int index = Hash(nom);
    if (HashTable[index]->nom == "empty"){
        // place libre, inserer element
        HashTable[index]->nom = nom;
        HashTable[index]->tel = tel;
        HashTable[index]->telCel = telCel;
        HashTable[index]->next = NULL;
    }
    else {
        // la place n est pas libre, collision --- chainnage
        item* ptr = HashTable[index];
        item* nouv = new item; // mon nouveau item
            nouv->nom = nom;   // charger les parametres dans le pointeur
            nouv->tel = tel;
            nouv->telCel = telCel;
            nouv->next = NULL;
            while (ptr->next !=NULL){
                ptr = ptr->next;    // avancer dans la liste
            }
            ptr->next = nouv;       // inserer item a la fin de la liste
    }
return index;
}
hash1::hash1(){
    //int tailleTableau = 50;
    for (int i=0; i<tailleTableau; i++){
        HashTable[i]= new item;
        HashTable[i]->nom = "empty";
        HashTable[i]->tel = "empty";
        HashTable[i]->telCel = "empty";
        HashTable[i]->next = NULL;
    }
}

int hash1::Hash(string cle){
    int hashage =0;
    int index;
    index = cle.length();
    for(int i=0; i<cle.length(); i++){
       hashage = hashage + (int) cle[i];
    }
    index = hashage % tailleTableau;

    //cout << "index = " << index << endl;
    //cout << "cle[0] = " << (int)cle[0] << endl;
    //cout << "cle[1] = " << (int)cle[1] << endl;
    //cout << "cle[2] = " << cle[2] << endl;

    return index;

}
