/**
 *@file Fermier.cpp
 *@brief Fichier contenant l'implementation de la classe Fermier
 *@author Thomas Chevrel
 *@author Theo Delalande
 *@date 27 novembre 2014
 */

#include "Fermier.h"

#include <string>
#include <iostream>

using namespace std;



//--------------------------------------------------------
/**
 *@brief Constructeur par defaut
 *@param v Villageois à décorer
 */
Fermier::Fermier( Villageois& v ) :
	Competence(v) {
	description_ = "Fermier";
}





//--------------------------------------------------------
/**
 *@brief Destructeur
 */
Fermier::~Fermier() {}





//--------------------------------------------------------
/**
 *@brief Méthode faisant recolter de la nourriture a ce decorator
 *@details Le cas écheant, l'energie du villageois décoré est modifiée
 *@return La quantité de nourriture recoltée par le decorator
 */
int Fermier::recolter_Nourriture() {
    if ( villageois_.get_Energie() < 1 ){
        cout << villageois_.get_Nom() << ", a beau etre un pro pour cultiver, il est trop fatigue..." << endl ;
        return 0;
    } else {
        cout << villageois_.get_Nom() << " recolte avec talent !" << endl ;
        villageois_.change_Energie(-1);
        return 5;
    }
}
