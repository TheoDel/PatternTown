/**
 *@file EtatVillageFete.h
 *@brief Fichier contenant la definition de la classe EtatVillageFete
 *@author Thomas Chevrel
 *@author Theo Delalande
 *@date 27 novembre 2014
 */

#ifndef ETATVILLAGEFETE_H_
#define ETATVILLAGEFETE_H_

#include "EtatVillage.h"


//--------------------------------------------------------
/**
 *@class EtatVillageFete
 *@brief Classe concrete heritant de EtatVillage et représentant l'etat Fete d'un village
 */

class EtatVillageFete : public EtatVillage {

	public :

		// Constructeurs/Destructeurs
		EtatVillageFete(Village* v);
		~EtatVillageFete();

		// Actions de jeu
		void faire_Recolter_Villageois(int idRessource, int idVillageois);  //@Override
		void faire_Construire( Batiment* b, int idVillageois );				//@Override

	private :
		static const int bonus_=2; /**< Constante définissant le bonus de récolte dans l'état fête */
};

//--------------------------------------------------------
#endif /* ETATVILLAGEFETE_H_ */
