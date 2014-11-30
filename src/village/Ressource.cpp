/**
 *@file Ressource.cpp
 *@brief Fichier contenant l'implementation de la classe Ressource
 *@author Thomas Chevrel
 *@author Theo Delalande
 *@date 27 novembre 2014
 */

#include "Ressource.hpp"

#include <iostream>

using namespace std;





//--------------------------------------------------------
/**
 *@brief Constructeur de base
 */
Ressource::Ressource() : stock_Bois_(0), stock_Nourriture_(0) {}





//--------------------------------------------------------
/**
 *@brief Destructeur
 */
Ressource::~Ressource() {}





//--------------------------------------------------------
/**
 *@brief Méthode retournant la quantité de la ressource correspondant à id
 *@param id Identifiant de la ressource
 */
int Ressource::get_Ressource( int id ){
	if ( id == 1 ) { return stock_Bois_; }
	if ( id == 2 ) { return stock_Nourriture_; }
	return -1;
}





//--------------------------------------------------------
/**
 *@brief Méthode(1) modifiant la quantité de la ressource correspondant à id
 *@param id Identifiant de la ressource
 *@param quantite Quantité à ajouter/retirer à la ressource
 */
void Ressource::change_Ressource ( int id, int quantite ){
	if ( id == 1 ) { stock_Bois_ += quantite; }
	if ( id == 2 ) { stock_Nourriture_ += quantite; }
}





//--------------------------------------------------------
/**
 *@brief Méthode(2) modifiant la quantité de la ressource correspondant à id
 *@param id Identifiant de la ressource
 *@param quantite Nouvelle quantité de la ressource
 */
void Ressource::set_Ressource ( int id, int quantite ){
	if ( id == 1 ) { stock_Bois_ = quantite; }
	if ( id == 2 ) { stock_Nourriture_ = quantite; }
}





//--------------------------------------------------------
/**
 *@brief Méthode affichant les quantités de toutes les ressources
 */
void Ressource::afficher_Ressources(){
    cout << "Bois: " << stock_Bois_ << endl ;
    cout << "Nourriture: " << stock_Nourriture_ << endl ;
}
