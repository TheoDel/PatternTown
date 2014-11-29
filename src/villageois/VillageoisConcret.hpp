/**
 *@file VillageoisConcret.hpp
 *@brief Fichier contenant la definition de la classe VillageoisConcret
 *@author Thomas Chevrel
 *@author Theo Delalande
 *@date 27 novembre 2014
 */

#ifndef VILLAGEOISCONCRET_HPP
#define VILLAGEOISCONCRET_HPP

#include "Villageois.hpp"


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
#endif /* VILLAGEOISCONCRET_HPP */
