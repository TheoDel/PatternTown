/**
 *@file VillageoisConcret.h
 *@brief Fichier contenant la definition de la classe VillageoisConcret
 *@author Thomas Chevrel
 *@author Theo Delalande
 *@date 27 novembre 2014
 */

#ifndef VILLAGEOIS_C_H
#define VILLAGEOIS_C_H

#include "Villageois.h"


//--------------------------------------------------------
/**
 *@class VillageoisConcret
 *@brief Classe concrete heritant de Villageois et représentant les villageois
 */

class VillageoisConcret : public Villageois {

    public :

		// Constructeurs/Destructeurs
		VillageoisConcret( std::string nom, std::string description );
		~VillageoisConcret();

};

//--------------------------------------------------------
#endif
