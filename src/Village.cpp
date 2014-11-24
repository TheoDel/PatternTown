#include "Village.h"

#include "EtatVillage.h"
#include "Villageois.h"
#include "Batiment.h"
#include "Ressource.h"
#include <iostream>
#include <vector>

using namespace std;



Village::Village( string nom ) {
	nom_ = nom;
	etatVillageNormal_= new EtatVillageNormal(this);
	etatVillageFamine_ = new EtatVillageFamine(this);
	etatVillage_ = etatVillageNormal_;
}


Village::~Village() {
	for ( auto v : villageois_ ) { delete v.second; }
	for ( auto b : batiments_ )  { delete b.second; }
	delete etatVillageNormal_;
	delete etatVillageFamine_;
}



///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////



// renvoie vrai si id est present
bool Village::existe_Batiment( int id ) {
	if ( villageois_.find(id) == villageois_.end() ) {
			return false;
		}
	return true;
}


// renvoie vrai si id est present
bool Village::existe_Villageois( int id ) {
	if ( batiments_.find(id) == batiments_.end() ) {
		return false;
	}
	return true;
}



///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////



// retourne le nom du village
string Village::get_Nom() {
	return nom_;
}


// retourne le villageois correspondant a id
// id doit exister dans le vector !
Villageois* Village::get_Villageois( int id ) {
	if ( villageois_.find(id) != villageois_.end() ) {
		return villageois_[id];
	}
	return nullptr;
}


// retourne le batiment correspondant a id
// id doit exister dans le vector !
Batiment* Village::get_Batiment( int id ) {
	if ( batiments_.find(id) != batiments_.end() ) {
			return batiments_[id];
		}
	return nullptr;
	}


// retourne la quantité de la ressource id
int Village::get_Ressource( int id ) {
	return ressources_.get_Ressource(id);
}


// retourne les ressources
Ressource* Village::get_Ressources() {
	return &ressources_;
}


// retourne le nombre d'habitants du village
int Village::get_Population() {
	return villageois_.size();
}


// retourne le nombre de batiments du village
int Village::get_Constructions() {
	return batiments_.size();
}



///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////



// ajoute un villageois
// si déja present, ne fait rien
void Village::add_Villageois( Villageois* v ) {
	if ( v != nullptr ) {
		villageois_.emplace( v->get_id(), v );
	}
}


// modifie un villageois (decoration)
void Village::change_Villageois( Villageois* nv ) {
	villageois_[ nv->get_id() ] = nv;
}


// ajoute un batiment
// si déja present, ne fait rien
void Village::add_Batiment( Batiment* b ) {
	if ( b != nullptr ) {
		batiments_.emplace( b->get_id(), b );
	}
}


// supprime le villageois correspondant à id
// si absent, ne fait rien
void Village::remove_Villageois( int id ) {
	if ( villageois_.find(id) != villageois_.end() ) {
		if ( villageois_[id]->get_Observable() != nullptr ) {
			villageois_[id]->get_Observable()->supprimerObs( villageois_[id] );
		}
		delete villageois_[id];
		villageois_.erase(id);
	}
}


// supprime le batiment correspondant à id
// si absent, ne fait rien
void Village::remove_Batiment( int id ) {
	if ( batiments_.find(id) != batiments_.end() ) {
		for ( auto o : batiments_[id]->get_Observers() ) {
			o.second->set_Observable( nullptr );
		}
		delete batiments_[id];
		batiments_.erase(id);
		}
}


void Village::change_Ressource(int id, int quantite) {
	ressources_.change_Ressource(id, quantite);
}



///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////



// faire recolter la ressource idRessource par le villageois idVillageois
// le cas écheant, l'ajoute aux ressources et modifie l'energie du villageois
void Village::faire_Recolter_Villageois(int idRessource, int idVillageois){
	etatVillage_->faire_Recolter_Villageois(idRessource, idVillageois);
}


// si possible, faire recolter le batiment b par le villageois idVillageois
// sinon, ne fait rien
void Village::faire_Construire( Batiment* b, int idVillageois ) {
	etatVillage_->faire_Construire(b, idVillageois);
}

// Effectue toutes les actions suivant le fin de tour
void Village::jour_Suivant() {

	cout << "\n...Prélèvement de la nourriture... ";
	int nourritureNecessaire = get_Population()*2;
	if (get_Ressource(2)<nourritureNecessaire){
		cout << " il n'y a pas assez de nourriture, le village est en famine !";
		ressources_.set_Ressource(2,0);
		etatVillage_=etatVillageFamine_;
	}
	else {
		cout << nourritureNecessaire << " rations de nourriture prélevées !";
		ressources_.change_Ressource(2,-nourritureNecessaire);
		etatVillage_=etatVillageNormal_;
	}
}


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////



// affiche la liste des villageois
void Village::afficher_Villageois() {
	for ( auto v : villageois_ ) {
		v.second->afficher();
	}
}


// affiche la liste des batiments
void Village::afficher_Batiments() {
	for ( auto b : batiments_ ) {
		b.second->afficher();
	}
}
