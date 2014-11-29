/**
 *@file VillageoisConcret.cpp
 *@brief Fichier contenant l'implementation de la classe VillageoisConcret
 *@author Thomas Chevrel
 *@author Theo Delalande
 *@date 27 novembre 2014
 */

#include "VillageoisConcret.hpp"

#include <iostream>

using namespace std;



//--------------------------------------------------------
/**
 *@brief Constructeur de base
 *@param nom Nom à donner au Village
 *@param description Description du villageois
 */
VillageoisConcret::VillageoisConcret( string nom, string description ) :
	Villageois( nom, description ) {}





//--------------------------------------------------------
/**
 *@brief Destructeur
 */
VillageoisConcret::~VillageoisConcret() {}
