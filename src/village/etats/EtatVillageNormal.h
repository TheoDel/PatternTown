/**
 *@file EtatVillageNormal.h
 *@brief Fichier contenant la definition de la classe EtatVillageNormal
 *@author Thomas Chevrel
 *@author Theo Delalande
 *@date 27 novembre 2014
 */

#ifndef ETATVILLAGENORMAL_H_
#define ETATVILLAGENORMAL_H_

#include "EtatVillage.h"


//--------------------------------------------------------
/**
 *@class EtatVillageNormal
 *@brief Classe concrete heritant de EtatVillage et représentant l'etat Normal d'un village
 */

class EtatVillageNormal : public EtatVillage {

	public :

		// Constructeurs/Destructeurs
		EtatVillageNormal(Village* v);
		~EtatVillageNormal();

		// Actions de jeu
		void faire_Recolter_Villageois(int idRessource, int idVillageois);	//@Override
		void faire_Construire( Batiment* b, int idVillageois );				//@Override

};

//--------------------------------------------------------
#endif /* ETATVILLAGENORMAL_H_ */
