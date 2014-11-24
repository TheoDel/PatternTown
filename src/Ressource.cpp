#include "Ressource.h"

#include <iostream>

using namespace std;



Ressource::Ressource() : stock_Bois_(0), stock_Nourriture_(0) {}

Ressource::~Ressource() {}



///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////



int Ressource::get_Ressource( int id ){
	if ( id == 1 ) { return stock_Bois_; }
	if ( id == 2 ) { return stock_Nourriture_; }
	return -1;
}


void Ressource::change_Ressource ( int id, int quantite ){
	if ( id == 1 ) { stock_Bois_ += quantite; }
	if ( id == 2 ) { stock_Nourriture_ += quantite; }
}

void Ressource::set_Ressource ( int id, int quantite ){
	if ( id == 1 ) { stock_Bois_ = quantite; }
	if ( id == 2 ) { stock_Nourriture_ = quantite; }
}

void Ressource::afficher_Ressources(){
    cout << "Bois: " << stock_Bois_ << endl ;
    cout << "Nourriture: " << stock_Nourriture_ << endl ;
}
