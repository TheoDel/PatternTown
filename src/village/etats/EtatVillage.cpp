/**
 *@file EtatVillage.cpp
 *@brief Fichier contenant l'implementation de la classe EtatVillage
 *@author Thomas Chevrel
 *@author Theo Delalande
 *@date 27 novembre 2014
 */

#include "EtatVillage.hpp"

#include "../../villageois/Villageois.hpp"
#include "../../batiments/Batiment.hpp"
#include "../Village.hpp"

#include <iostream>

using namespace std;



//--------------------------------------------------------
/**
 *@brief Constructeur de base
 *@param v Village sur lequel s'applique les etats
 */
EtatVillage::EtatVillage(Village* v){
	village_ = v;
}





//--------------------------------------------------------
/**
 *@brief Destructeur
 */
EtatVillage::~EtatVillage(){}





//--------------------------------------------------------
/**
 *@brief Méthode faisant effectuer de la recolte à un villageois
 *@details Le cas écheant, la ressource recoltée est ajoutée aux ressources du village et l'energie du villageois est modifiée
 *@param idRessource Identifiant de la ressource à recolter
 *@param idVillageois Identifiant du villageois recoltant
 */
void EtatVillage::faire_Recolter_Villageois(int idRessource, int idVillageois){
	Villageois* v = village_->get_Villageois(idVillageois);
	if ( village_->existe_Villageois( v->get_id() ) ) {
		if		(idRessource == 1)	{ village_->change_Ressource(1,v->recolter_Bois()); }
		else if (idRessource == 2)	{ village_->change_Ressource(2,v->recolter_Nourriture()); }
	}
}





//--------------------------------------------------------
/**
 *@brief Méthode faisant construire (sous condition) un batiment à un villageois
 *@details Le cas écheant, le batiment est ajouté à la liste des batiments et l'energie du villageois est modifiée
 *@param b Pointeur vers le batiment à construire
 *@param idVillageois Identifiant du villageois construisant
 */
void EtatVillage::faire_Construire( Batiment* b, int idVillageois){
	if ( village_->existe_Villageois(idVillageois) ) {
		village_->add_Batiment( village_->get_Villageois(idVillageois)->construire_Batiment(b) );
	}
}
