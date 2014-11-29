/**
 *@file Bucheron.cpp
 *@brief Fichier contenant l'implementation de la classe Bucheron
 *@author Thomas Chevrel
 *@author Theo Delalande
 *@date 27 novembre 2014
 */

#include "Bucheron.hpp"

#include <string>
#include <iostream>

using namespace std;



//--------------------------------------------------------
/**
 *@brief Constructeur de base
 *@param v Villageois à décorer
 */
Bucheron::Bucheron( Villageois& v ) :
	Competence(v) {
	description_ = "Bucheron";
}





//--------------------------------------------------------
/**
 *@brief Destructeur
 */
Bucheron::~Bucheron() {}





//--------------------------------------------------------
/**
 *@brief Méthode faisant recolter du bois a ce decorator
 *@details Le cas écheant, l'energie du villageois decoré est modifiée
 *@return La quantité de bois recolté par le decorator
 */
int Bucheron::recolter_Bois() {
    if ( villageois_.get_Energie() < 1 ){
        cout << villageois_.get_Nom() << ", a beau etre un pro pour couper du bois, il est trop fatigue..." << endl ;
        return 0;
    } else {
        cout << villageois_.get_Nom() << " coupe du bois comme un pro !" << endl ;
        villageois_.change_Energie(-1);
        return 5;
    }
}
