/**
 *@file EtatVillageFete.hpp
 *@brief Fichier contenant la definition de la classe EtatVillageFete
 *@author Thomas Chevrel
 *@author Theo Delalande
 *@date 27 novembre 2014
 */

#ifndef ETATVILLAGEFETE_HPP
#define ETATVILLAGEFETE_HPP

#include "EtatVillage.hpp"


//--------------------------------------------------------
/**
 *@class EtatVillageFete
 *@brief Classe concrete heritant de EtatVillage et représentant l'etat Fete d'un village
 */

class EtatVillageFete : public EtatVillage {

	private :

		static const int bonus_=2; /**< Constante définissant le bonus de récolte dans l'état fête */


	public :

		// Constructeurs/Destructeurs
		EtatVillageFete(Village* v);
		~EtatVillageFete();

		// Actions de jeu
		void faire_Recolter_Villageois(int idRessource, int idVillageois);  //@Override
		void faire_Construire( Batiment* b, int idVillageois );				//@Override

};

//--------------------------------------------------------
#endif /* ETATVILLAGEFETE_HPP */
