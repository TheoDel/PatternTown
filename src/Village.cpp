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
	for ( size_t i=0 ; i<villageois_.size() ; ++i ) {
			delete villageois_[i];
	}
	for ( size_t i=0 ; i<batiments_.size() ; ++i ) {
			delete batiments_[i];
	}
}



///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////



// renvoie vrai si id est present dans le vector de batiments
bool Village::existe_Batiment( int id ) {
	for( Batiment* b : batiments_ ) {
		if ( b->get_id() == id ) {
			return true;
		}
	}
	return false;
}


// renvoie vrai si id est present dans le vector de villageois
bool Village::existe_Villageois( int id ) {
	for( Villageois* v : villageois_ ) {
		if ( v->get_id() == id ) {
			return true;
		}
	}
	return false;
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
	for ( Villageois* v : villageois_ ) {
		if ( v->get_id() == id ) {
			return v;
		}
	}
	return nullptr;
}


// retourne le batiment correspondant a id
// id doit exister dans le vector !
Batiment* Village::get_Batiment( int id ) {
	for ( Batiment* b : batiments_ ) {
		if ( b->get_id() == id ) {
			return b;
		}
	}
	return nullptr;
}


// retourne la quantité de la ressource id
int Village::get_Ressource( int id ) {
	return ressources_.get_Ressource(id);
}

std::vector<Villageois*> Village::get_villageois(){
	return villageois_;
}

std::vector<Batiment*> Village::get_batiments(){
	return batiments_;
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
// si d�ja present, ne fait rien
void Village::add_Villageois( Villageois* v ) {
	if ( !existe_Villageois( v->get_id() ) ) {
		villageois_.push_back(v);
	}
}


// modifie un villageois (decoration)
void Village::change_Villageois( Villageois* nv ) {
	size_t i = 0;
	while ( i<villageois_.size() and villageois_[i]->get_id() != nv->get_id() ) { ++i; }
	villageois_[i] = nv;
}


// ajoute un batiment
// si d�ja present, ne fait rien
void Village::add_Batiment( Batiment* b ) {
	if ( ( b != nullptr ) && !existe_Batiment( b->get_id() ) ) {
		batiments_.push_back(b);
	}
}


// supprime le villageois correspondant à id
// si absent, ne fait rien
void Village::remove_Villageois( int id ) {
	for( size_t i=0 ; i<villageois_.size() ; ++i ) {
		if ( villageois_[i]->get_id() == id ) {
			if ( villageois_[i]->get_Observable() != nullptr ) {
				villageois_[i]->get_Observable()->supprimerObs( villageois_[i] );
			}
			delete villageois_[i];
			villageois_.erase( villageois_.begin() + i );
		}
	}
}


// supprime le batiment correspondant à id
// si absent, ne fait rien
void Village::remove_Batiment( int id ) {
	for( size_t i=0 ; i<batiments_.size() ; ++i ) {
		if ( batiments_[i]->get_id() == id ) {
			for ( Observer* o : batiments_[i]->get_Observers() ) {
				o->set_Observable( nullptr );
			}
			delete batiments_[i];
			batiments_.erase( batiments_.begin() + i );
		}
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
	for ( Villageois* v : villageois_ ) {
		v->afficher();
	}
}


// affiche la liste des batiments
void Village::afficher_Batiments() {
	for ( Batiment* b : batiments_ ) {
		b->afficher();
	}
}
