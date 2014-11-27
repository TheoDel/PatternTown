/**
 *@file EtatVillageFamine.cpp
 *@brief Fichier contenant l'implementation de la classe EtatVillageFamine
 *@author Thomas Chevrel
 *@author Theo Delalande
 *@date 27 novembre 2014
 */

#include "EtatVillageFamine.h"

#include "../../villageois/Villageois.h"
#include "../../batiments/Batiment.h"
#include "../Village.h"
#include "../Ressource.h"
#include <iostream>

using namespace std;



//--------------------------------------------------------
/**
 *@brief Constructeur de base
 *@param v Village sur lequel s'applique cet etat
 */
EtatVillageFamine::EtatVillageFamine(Village* v) : EtatVillage(v) {}





//--------------------------------------------------------
/**
 *@brief Destructeur
 */
EtatVillageFamine::~EtatVillageFamine() {}





//--------------------------------------------------------
/**
 *@brief Méthode faisant effectuer de la recolte à un villageois
 *@details Le cas écheant, la ressource recoltée est ajoutée aux ressources du village et l'energie du villageois est modifiée
 *@param idRessource Identifiant de la ressource à recolter
 *@param idVillageois Identifiant du villageois recoltant
 */
void EtatVillageFamine::faire_Recolter_Villageois(int idRessource, int idVillageois){
	Villageois* v = village_->get_Villageois(idVillageois);
	if ( village_->existe_Villageois( v->get_id() ) ) {
		if		(idRessource == 1)	{ cout << "Le villageois refuse de travailler, il a trop faim !"; }
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
void EtatVillageFamine::faire_Construire( Batiment* b, int idVillageois){
	cout << "Le villageois refuse de construire, il a trop faim !";
}
