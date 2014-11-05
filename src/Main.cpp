#include <iostream>
#include "SystemeJeu.h"
#include "Village.h"
#include "Villageois.h"
#include "VillageoisConcret.h"
#include "Bucheron.h"
#include "Competence.h"

using namespace std;

int main()
{

    //Tests village/villageois

	Village village;

	village.add_Villageois( new VillageoisConcret(1, "Toto", "villageois content", &village) );
	village.add_Villageois( new VillageoisConcret(2, "Raoul", "villageois chiant", &village) );

	Bucheron ba( village.get_Villageois(2) );
	village.change_Villageois(  &ba ) ;
	//Bucheron bb( village.get_Villageois(2) );
	//village.change_Villageois(  &bb ) ;
	//village.afficher_Villageois();





	//Tests gestion des ressources
	/*
	village.get_Ressources()->afficher_Ressources();
	village.get_Ressources()->change_Ressource(1,village.get_Villageois(1)->recolter_Bois());
	village.get_Ressources()->change_Ressource(1,village.get_Villageois(2)->recolter_Bois());
	village.get_Ressources()->afficher_Ressources();
	*/





    // Test gestion d'energie des villageois
	/*
	for (int i = 0; i<6; i++){
        village.get_Ressources()->change_Ressource(1,village.get_Villageois(1)->recolter_Bois());
        cout << village.get_Villageois(1)->get_Energie() << endl;
    }
	village.get_Ressources()->afficher_Ressources();
	*/





    //Tests decorator
	/*
	VillageoisConcret v1( 1, "Tota", "Normal", &village );
	Bucheron b1(&v1);
	Bucheron b2(&b1);
	Bucheron b3(&b2);

	v1.afficher();
	cout  << v1.recolter_Bois() << endl ;
	b1.afficher();
	cout  << b1.recolter_Bois() << endl ;
	b3.afficher();
	cout  << b3.recolter_Bois() << endl ;
	*/





	//Tests SystemeJeu

	SystemeJeu s;
	s.lancerJeu();

}
