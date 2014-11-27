/**
 *@file Batiment.cpp
 *@brief Fichier contenant l'implementation de la classe SystemeJeu
 *@author Thomas Chevrel
 *@author Theo Delalande
 *@date 27 novembre 2014
 */

#include "Batiment.h"
#include "../villageois/Observer.h"

#include <iostream>
#include <unordered_map>

using namespace std;
int Batiment::NEXTID_ = 1;



//--------------------------------------------------------
/**
 *@brief Constructeur de base
 *@param nom Nom du batiment
 *@param description Description du batiment
 */
Batiment::Batiment( string nom, string description ) :
		id_(NEXTID_), nom_(nom), description_(description), indiceSatisfaction_(5) { ++NEXTID_; }





//--------------------------------------------------------
/**
 *@brief Destructeur
 */
Batiment::~Batiment() {}





//--------------------------------------------------------
/**
 *@brief Méthode retournant l'id du batiment
 *@return Un entier representant l'id du batiment
 */
int Batiment::get_id(){
	return id_;
}





//--------------------------------------------------------
/**
 *@brief Méthode retournant le nom du batiment
 *@return Une std::string representant le nom du batiment
 */
string Batiment::get_Nom(){
	return nom_;
}





//--------------------------------------------------------
/**
 *@brief Méthode retournant la description du batiment
 *@return Une std::string representant la description du batiment
 */
string Batiment::get_Description() {
	return description_;
}





//--------------------------------------------------------
/**
 *@brief Méthode modifiant la description du batiment
 *@param d Nouvelle description du batiment
 */
void Batiment::set_Description( string d ) {
	description_ = d;
}





//--------------------------------------------------------
/**
 *@brief Méthode retournant d'indice de satisfaction liée au batiment
 *@return Un entier representant le satisfaction liée au batiment
 */
int Batiment::get_indiceSatisfaction() {
	return indiceSatisfaction_;
}





//--------------------------------------------------------
/**
 *@brief Méthode retournant la liste des observateurs du batiment
 *@return Un std::unordered_map contenant tous les observateurs du batiment
 */
std::unordered_map<int,Observer*> Batiment::get_Observers() {
	return observers_;
}





//--------------------------------------------------------
/**
 *@brief Méthode modifiant l'indice de satisfaction lié au batiment
 *@param is Nouvel indice de satisfaction du batiment
 */
void Batiment::set_indiceSatisfaction( int is ) {
	indiceSatisfaction_ = is;
	// on notifie la modification aux observateurs
	notifierObs();
}





//--------------------------------------------------------
/**
 *@brief Méthode ajoutant un nouvel observateur
 *@param observer Observateur à ajouter
 */
void Batiment::enregistrerObs( Observer* observer ) {
	observers_.emplace( observer->get_id(), observer );
	//on transmet l'indice de satisfaction à tous les observateurs
	observers_[ observer->get_id() ]->actualiser(indiceSatisfaction_);
}





//--------------------------------------------------------
/**
 *@brief Méthode un observateur
 *@param observer Observateur à supprimer
 */
void Batiment::supprimerObs( Observer* observer ) {
	if ( observers_.find( observer->get_id() ) != observers_.end() ) {
		observers_.erase( observer->get_id() );
		//on supprime ce sujet dans l'observateur en paramètre
		observer->set_Observable( nullptr );
	}
}





//--------------------------------------------------------
/**
 *@brief Méthode transmettant l'indice de satisfaction à tous les observateurs
 */
void Batiment::notifierObs() {
	for( auto o : observers_ ) {
		o.second->actualiser( indiceSatisfaction_ );
	}
}





//--------------------------------------------------------
/**
 *@brief Méthode affichant le nom, l'id et la description du batiment
 */
void Batiment::afficher() {
	 cout << "(ID:" << get_id() << ") " << get_Nom() << " : " << get_Description() << endl;
}
