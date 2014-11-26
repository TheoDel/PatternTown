#include "EtatVillage.h"

#include "../Village.h"
#include "../Ressource.h"
#include <iostream>

using namespace std;

EtatVillage::EtatVillage(Village* v){
	village_ = v;
}

EtatVillage::~EtatVillage(){}

void EtatVillage::faire_Recolter_Villageois(int idRessource, int idVillageois){
	Villageois* v = village_->get_Villageois(idVillageois);
	if ( village_->existe_Villageois( v->get_id() ) ) {
		if		(idRessource == 1)	{ village_->change_Ressource(1,v->recolter_Bois()); }
		else if (idRessource == 2)	{ village_->change_Ressource(2,v->recolter_Nourriture()); }
	}
}

void EtatVillage::faire_Construire( Batiment* b, int idVillageois){
	if ( village_->existe_Villageois(idVillageois) ) {
		village_->add_Batiment( village_->get_Villageois(idVillageois)->construire_Batiment(b) );
	}
}
