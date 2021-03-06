/**
 *@file EtatVillageFamine.hpp
 *@brief Fichier contenant la definition de la classe EtatVillageFamine
 *@author Thomas Chevrel
 *@author Theo Delalande
 *@date 27 novembre 2014
 */

#ifndef ETATVILLAGEFAMINE_HPP
#define ETATVILLAGEFAMINE_HPP

#include "EtatVillage.hpp"


//--------------------------------------------------------
/**
 *@class EtatVillageFamine
 *@brief Classe concrete heritant de EtatVillage et représentant l'etat Famine d'un village
 */

class EtatVillageFamine : public EtatVillage {

	public :

		// Constructeurs/Destructeurs
		EtatVillageFamine(Village* v);
		~EtatVillageFamine();

		// Actions de jeu
		void faire_Recolter_Villageois(int idRessource, int idVillageois);  //@Override
		void faire_Construire( Batiment* b, int idVillageois );				//@Override

};

//--------------------------------------------------------
#endif /* ETATVILLAGEFAMINE_HPP */
