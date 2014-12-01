/**
 *@file Maison.cpp
 *@brief Fichier contenant l'implementation de la classe Maison
 *@author Thomas Chevrel
 *@author Theo Delalande
 *@date 27 novembre 2014
 */

#include "Maison.hpp"

#include "Batiment.hpp"
#include "Observable.hpp"

using namespace std;

//--------------------------------------------------------
/**
 *@brief Constructeur de base
 *@param nom Nom de la maison
 *@param description Description de la maison
 */
Maison::Maison( string nom, string description ) : Batiment( nom, description ) {}





//--------------------------------------------------------
/**
 *@brief Destructeur
 */
Maison::~Maison() {}

//--------------------------------------------------------
/**
 *@brief Obtenir le nombre d'observeurs (habitants) maximum pour cette maison
 */
unsigned Maison::get_HabitantsMax() {
	return habitants_max_;
}
