/**
 *@file Competence.cpp
 *@brief Fichier contenant l'implementation de la classe Competence
 *@author Thomas Chevrel
 *@author Theo Delalande
 *@date 27 novembre 2014
 */

#include "Competence.h"

#include <iostream>

using namespace std;



//--------------------------------------------------------
/**
 *@brief Constructeur de base
 *@param v Villageois à décorer
 */
Competence::Competence( Villageois& v ) : villageois_(v) {}





//--------------------------------------------------------
/**
 *@brief Destructeur
 */
Competence::~Competence() {
	delete &villageois_;
}





//--------------------------------------------------------
/**
 *@brief Méthode retournant l'identifiant du villageois decoré
 *@return Un entier représentant l'identifiant du villageois décoré
 */
int Competence::get_id() {
	return villageois_.get_id();
}





//--------------------------------------------------------
/**
 *@brief Méthode retournant le nom du villageois decoré
 *@return Une std::string représentant le nom du villageois décoré
 */
string Competence::get_Nom() {
	return villageois_.get_Nom();
}





//--------------------------------------------------------
/**
 *@brief Méthode retournant la description du villageois decoré
 *@return Une std::string représentant la description du villageois décoré
 */
string Competence::get_Description() {
	return ( villageois_.get_Description() + ", " + description_ );
}





//--------------------------------------------------------
/**
 *@brief Méthode retournant le niveau d'energie (points d'action) du villageois décoré
 *@return Un entier representant l'energie du villageois décoré
 */
int Competence::get_Energie() {
	return villageois_.get_Energie();
}





//--------------------------------------------------------
/**
 *@brief Méthode retournant le niveau de satisfaction ( positif=heureux, negatif=mecontent ) du villageois décoré
 *@return Un entier representant la satisfaction du villageois décoré
 */
int Competence::get_Satisfaction() {
	return villageois_.get_Satisfaction();
}





//--------------------------------------------------------
/**
 *@brief Méthode retournant le villageois décoré
 *@return Un pointeur vers le villageois décoré
 */
Villageois* Competence::get_Villageois() {
	return &villageois_;
}







//--------------------------------------------------------
/**
 *@brief Méthode modifiant la description du villageois decoré
 *@param d Nouvelle description du villageois décoré
 */
void Competence::set_Description( string d ){
	villageois_.set_Description(d);
}





//--------------------------------------------------------
/**
 *@brief Méthode modifiant le niveau d'energie du villageois décoré
 *@param val Energie à ajouter/retirer au villageois décoré
 */
void Competence::change_Energie( int val ) {
	villageois_.change_Energie(val);
}





//--------------------------------------------------------
/**
 *@brief Méthode modifiant le niveau de satisfaction du villageois decoré
 *@param val Satisfaction à ajouter/retirer au villageois décoré
 */
void Competence::change_Satisfaction( int val ) {
	villageois_.change_Satisfaction(val);
}





//--------------------------------------------------------
/**
 *@brief Méthode retournant le sujet observé par le villageois decoré
 *@return Un pointeur vers le sujet, ou nullptr s'il n'existe pas
 */
Observable* Competence::get_Observable() {
	return villageois_.get_Observable();
}





//--------------------------------------------------------
/**
 *@brief Méthode retournant l'indice de satisfaction du sujet (batiment) observé par le villageois décoré
 *@return Un entier representant l'indice de satisfaction du sujet (batiment) observé par le villageois décoré
 */
int Competence::get_indiceBatiment() {
	return villageois_.get_indiceBatiment();
}





//--------------------------------------------------------
/**
 *@brief Méthode modifiant le sujet observé par le villageois décoré
 *@param obs Le nouveau sujet à observé, ou nullptr
 */
void Competence::set_Observable( Observable* obs ) {
	villageois_.set_Observable(obs);
}





//--------------------------------------------------------
/**
 *@brief Méthode actualisant le niveau de satisfaction du villageois décoré par l'indice de satisfaction reçu du sujet
 *@param newIndice l'indice de satisfaction mis à jour du sujet
 */
void Competence::actualiser( int newIndice ) {
	villageois_.actualiser( newIndice );
}





//--------------------------------------------------------
/**
 *@brief Méthode faisant recolter du bois au villageois decoré
 *@details Le cas écheant, l'energie du villageois decoré est modifiée
 *@return La quantité de bois recolté par le villageois decoré
 */
int Competence::recolter_Bois() {
	return villageois_.recolter_Bois();
}





//--------------------------------------------------------
/**
 *@brief Méthode faisant recolter de la nourriture au villageois décoré
 *@details Le cas écheant, l'energie du villageois décoré est modifiée
 *@return La quantité de nourriture recoltée par le villageois décoré
 */
int Competence::recolter_Nourriture() {
	return villageois_.recolter_Nourriture();
}





//--------------------------------------------------------
/**
 *@brief Méthode faisant construire un batiment au villageois decoré
 *@details Le cas écheant, l'energie du villageois decoré est modifiée
 *@return Un pointeur vers le nouveau batiment, ou nullptr si le villageois decoré n'a pas pu le construire
 */
Batiment* Competence::construire_Batiment( Batiment* b ) {
	return villageois_.construire_Batiment( b );
}
