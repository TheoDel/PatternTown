/**
 *@file Ouvrier.cpp
 *@brief Fichier contenant l'implementation de la classe Ouvrier
 *@author Thomas Chevrel
 *@author Theo Delalande
 *@date 27 novembre 2014
 */

#include "Ouvrier.hpp"

#include <string>
#include <iostream>

using namespace std;



//--------------------------------------------------------
/**
 *@brief Constructeur de base
 *@param v Villageois à décorer
 */
Ouvrier::Ouvrier( Villageois& v ) :
	Competence(v) {
	description_ = "Ouvrier du batiment";
}





//--------------------------------------------------------
/**
 *@brief Destructeur
 */
Ouvrier::~Ouvrier() {}





//--------------------------------------------------------
/**
 *@brief Méthode faisant construire un batiment a ce decorator
 *@details Le cas écheant, l'energie du villageois decoré est modifiée
 *@return Un pointeur vers le nouveau batiment, ou nullptr si le decorator n'a pas pu le construire
 */
Batiment* Ouvrier::construire_Batiment( Batiment* b ) {
	if ( get_Energie() < 1 ) {
        //si son energie est insuffisante, le decorator ne peut rien construire
		cout << get_Nom() << " est trop fatigué pour construire !" << endl;
		//on supprime le batiment temporaire créé et on renvoie nullptr
		delete b;
		b = nullptr;
		return b;
	} else {
		cout << get_Nom() << " a construit le batiment !" << endl;
        //on decremente l'energie du villageois decoré et on renvoie le batiment créé
		change_Energie(-1);
		return b;
	}
}
