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

	Village village("Pattern City");

	village.add_Villageois( new VillageoisConcret(1, "Toto", "villageois content", &village) );
	village.add_Villageois( new VillageoisConcret(2, "Raoul", "villageois chiant", &village) );

	village.change_Villageois(  new Bucheron( *village.get_Villageois(2) ) );
	village.change_Villageois(  new Bucheron( *village.get_Villageois(2) ) );
	village.afficher_Villageois();
	
	village.get_Villageois(2)->afficher();
	cout << village.get_Villageois(2)->get_id();

	village.get_Villageois(2)->get_Villageois()->afficher();


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

	Villageois* v1 = new VillageoisConcret ( 1, "Tota", "Normal", &village );
	v1->change_Energie(-2);
	//v1->afficher();
	//cout << v1->get_Energie() << endl;

	v1 = new Bucheron (*v1);
	//v1->afficher();
	//cout << v1->get_Energie() << endl;

	v1 = new Bucheron (*v1);
	v1->afficher();
	cout << v1->recolter_Bois() << endl;

	v1->set_Description("mollusque");
	v1->afficher();
	cout << v1->recolter_Bois() << endl;

	delete v1;


	//Tests SystemeJeu

	SystemeJeu s("NYC");
	s.lancerJeu();



}
