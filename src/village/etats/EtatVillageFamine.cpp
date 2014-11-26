#include "EtatVillageFamine.h"

#include "../Village.h"
#include "../../villageois/Villageois.h"
#include "../../batiments/Batiment.h"
#include "../Ressource.h"
#include <iostream>

using namespace std;

EtatVillageFamine::EtatVillageFamine(Village* v) :
	EtatVillage(v) {}

EtatVillageFamine::~EtatVillageFamine(){

}

void EtatVillageFamine::faire_Recolter_Villageois(int idRessource, int idVillageois){
	Villageois* v = village_->get_Villageois(idVillageois);
	if ( village_->existe_Villageois( v->get_id() ) ) {
		if		(idRessource == 1)	{ cout << "Le villageois refuse de travailler, il a trop faim !"; }
		else if (idRessource == 2)	{ village_->change_Ressource(2,v->recolter_Nourriture()); }
	}
}

void EtatVillageFamine::faire_Construire( Batiment* b, int idVillageois){
	cout << "Le villageois refuse de construire, il a trop faim !";
}
