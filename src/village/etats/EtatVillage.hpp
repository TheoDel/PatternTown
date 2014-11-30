/**
 *@file EtatVillage.hpp
 *@brief Fichier contenant la definition de la classe EtatVillage
 *@author Thomas Chevrel
 *@author Theo Delalande
 *@date 27 novembre 2014
 */

#ifndef ETATVILLAGE_HPP
#define ETATVILLAGE_HPP

class Village;
class Batiment;


//--------------------------------------------------------
/**
 *@class EtatVillage
 *@brief Classe abstraite représentant l'etat d'un village
 */

class EtatVillage {

	protected :

		Village* village_; /**< Village sur lequel s'applique les etats */


	public :

		// Constructeurs/Destructeurs
		EtatVillage(Village* v);
		virtual ~EtatVillage() = 0;

		// Actions de jeu
		virtual void faire_Recolter_Villageois(int idRessource, int idVillageois);
		virtual void faire_Construire( Batiment* b, int idVillageois );

};

//--------------------------------------------------------
#endif /* ETATVILLAGE_HPP */
