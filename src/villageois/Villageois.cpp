/**
 *@file Villageois.cpp
 *@brief Fichier contenant l'implementation de la classe Villageois
 *@author Thomas Chevrel
 *@author Theo Delalande
 *@date 27 novembre 2014
 */

#include "Villageois.hpp"

#include <iostream>

using namespace std;

int Villageois::NEXTID_ = 1;



//--------------------------------------------------------
/**
 *@brief Constructeur par defaut
 */
Villageois::Villageois() :
	//necessaire uniquement lors de la création d'une competence
	observable_(nullptr), indiceBatiment_(0), id_(0), nom_(""),
	energie_(0), satisfaction_(0), description_("") {}





//--------------------------------------------------------
/**
 *@brief Constructeur de base
 *@param nom Nom du villageois
 *@param description Description du villageois
 */
Villageois::Villageois( std::string nom, std::string description ) :
	observable_(nullptr), indiceBatiment_(0), id_(NEXTID_), nom_(nom),
	energie_(1), satisfaction_(3), description_(description) { ++NEXTID_; }





//--------------------------------------------------------
/**
 *@brief Destructeur
 */
Villageois::~Villageois() {}





//--------------------------------------------------------
/**
 *@brief Méthode retournant l'identifiant du villageois
 *@return Un entier representant l'identifiant du villageois
 */
int Villageois::get_id() {
	return id_;
}





//--------------------------------------------------------
/**
 *@brief Méthode retournant le nom du villageois
 *@return Une std::string representant le nom du villageois
 */
string Villageois::get_Nom() {
	return nom_;
}





//--------------------------------------------------------
/**
 *@brief Méthode retournant la description du villageois
 *@return Une std::string representant la description du villageois
 */
string Villageois::get_Description() {
	return description_;
}





//--------------------------------------------------------
/**
 *@brief Méthode retournant le niveau d'energie (points d'action) du villageois
 *@return Un entier representant l'energie du villageois
 */
int Villageois::get_Energie() {
	return energie_;
}





//--------------------------------------------------------
/**
 *@brief Méthode retournant le niveau de satisfaction ( positif=heureux, negatif=mecontent ) du villageois
 *@return Un entier representant la satisfaction du villageois
 */
int Villageois::get_Satisfaction() {
	return satisfaction_;
}





//--------------------------------------------------------
/**
 *@brief Méthode retournant le villageois lui-même
 *@return Un pointeur vers le villageois
 */
Villageois* Villageois::get_Villageois() {
	return this;
}





//--------------------------------------------------------
/**
 *@brief Méthode modifiant la description du villageois
 *@param d Nouvelle description du villageois
 */
void Villageois::set_Description( string d ){
	description_ = d;
}



//--------------------------------------------------------
/**
 *@brief Setter du niveau d'energie du villageois
 *@param val Energie à affecter au villageois
 */
void Villageois::set_Energie( int val ) {
	energie_ = val;
}




//--------------------------------------------------------
/**
 *@brief Méthode modifiant le niveau d'energie du villageois
 *@param val Energie à ajouter/retirer au villageois
 */
void Villageois::change_Energie( int val ) {
	energie_ += val;
}





//--------------------------------------------------------
/**
 *@brief Méthode modifiant le niveau de satisfaction du villageois
 *@param val Satisfaction à ajouter/retirer au villageois
 */
void Villageois::change_Satisfaction( int val ) {
	satisfaction_ += val;
}





//--------------------------------------------------------
/**
 *@brief Méthode retournant le sujet observé par le villageois
 *@return Un pointeur vers le sujet, ou nullptr s'il n'existe pas
 */
Observable* Villageois::get_Observable() {
	return observable_;
}





//--------------------------------------------------------
/**
 *@brief Méthode retournant l'indice de satisfaction du sujet (batiment) observé par le villageois
 *@return Un entier representant l'indice de satisfaction du sujet (batiment) observé par le villageois
 */
int Villageois::get_indiceBatiment() {
	return indiceBatiment_;
}





//--------------------------------------------------------
/**
 *@brief Méthode modifiant le sujet observé par le villageois
 *@param obs Le nouveau sujet à observé, ou nullptr
 */
void Villageois::set_Observable( Observable* obs ) {
	if ( observable_ != nullptr ) {
		// si le villageois observe deja un sujet, on le supprime de ce dernier
		observable_->supprimerObs( this );
		indiceBatiment_ = 0;
	}
	observable_ = obs;
	if ( obs != nullptr ) {
		// si le nouveau sujet existe bien, on enregistre le villageois dedans
		observable_->enregistrerObs( this );
	}
}





//--------------------------------------------------------
/**
 *@brief Méthode actualisant le niveau de satisfaction du villageois par l'indice de satisfaction reçu du sujet
 *@param newIndice l'indice de satisfaction mis à jour du sujet
 */
void Villageois::actualiser( int newIndice ) {
	satisfaction_ += newIndice - indiceBatiment_;
	indiceBatiment_ = newIndice;
}





//--------------------------------------------------------
/**
 *@brief Méthode faisant recolter du bois au villageois
 *@details Le cas écheant, l'energie du villageois est modifiée
 *@return La quantité de bois recolté par le villageois
 */
int Villageois::recolter_Bois() {
    if ( energie_ < 1){
        //si son energie est insuffisante, le villageois ne recolte rien
    	cout << nom_ << ", non content d'etre incompetent pour couper du bois, est trop fatigue..." << endl;
        return 0;
    } else {
        cout << nom_ << " coupe du bois comme un souillon..." << endl;
        //on decremente son energie et on renvoie sa recolte
        --energie_;
        return 1;
    }
}





//--------------------------------------------------------
/**
 *@brief Méthode faisant recolter de la nourriture au villageois
 *@details Le cas écheant, l'energie du villageois est modifiée
 *@return La quantité de nourriture recoltée par le villageois
 */
int Villageois::recolter_Nourriture() {
    if ( energie_ < 1){
        //si son energie est insuffisante, le villageois ne recolte rien
    	cout << nom_ << ", non content d'etre incompetent pour récolter de la nourriture, est trop fatigue..." << endl;
        return 0;
    } else {
        cout << nom_ << " recolte de la nourriture comme un souillon..." << endl;
        //on decremente son energie et on renvoie sa recolte
        --energie_;
        return 1;
    }
}





//--------------------------------------------------------
/**
 *@brief Méthode faisant construire un batiment au villageois
 *@details Le cas écheant, l'energie du villageois est modifiée
 *@return Un pointeur vers le nouveau batiment, ou nullptr si le villageois n'a pas pu le construire
 */
Batiment* Villageois::construire_Batiment( Batiment* b ) {
	//un villageois classique ne peut pas construire de batiment
	cout << nom_ << " n'est pas un ouvrier" << endl;
	//on supprime le batiment temporaire créé et on renvoie nullptr
	delete b;
	b = nullptr;
	return b;
}




//--------------------------------------------------------
/**
 *@brief Méthode faisant améliorer un batiment au villageois
 *@details Le cas écheant, l'energie du villageois est modifiée
 *@return Un booléen indiquant si l'action a pu être faite
 */
bool Villageois::ameliorer_Batiment( Batiment* b ) {
	if ( get_Energie() < 1 ) {
        //si son energie est insuffisante, le villageois ne peut rien faire
		cout << get_Nom() << " est trop fatigué pour ameliorer le batiment !" << endl;
		return false;
	} else {
        //on decremente l'energie du villageois decoré et on ameliore la batiment en question
		change_Energie(-1);
		b->set_indiceSatisfaction(1+(b->get_indiceSatisfaction()));
		cout << get_Nom() << " a ameliore le batiment ! Celui-ci est desormais de niveau " << b->get_indiceSatisfaction() << endl;
		return true;
	}
}



//--------------------------------------------------------
/**
 *@brief Méthode affichant l'identifiant, l'energie, la satisfaction, le nom et la description du villageois
 */
void Villageois::afficher() {
	cout << "(ID:" << get_id() << ")(Energie:" << get_Energie() << " - Satisfaction:" << get_Satisfaction() << ") " << get_Nom() << " : " << get_Description() << endl;
}
