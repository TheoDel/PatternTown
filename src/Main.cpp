#include "SystemeJeu.h"
#include "Village.h"
#include "Observer.h"
#include "Villageois.h"
#include "VillageoisConcret.h"
#include "Competence.h"
#include "Bucheron.h"
#include "Fermier.h"
#include "Ouvrier.h"
#include "Observable.h"
#include "Batiment.h"
#include "Maison.h"
#include "Ressource.h"

#include <iostream>

using namespace std;



int main()
{

	Village village("Pattern City");





    //Tests village/villageois

	village.add_Batiment( new Maison ( "Maison_1", "taudis" ) );
	village.add_Villageois( new VillageoisConcret(1, "Toto", "villageois content" ) );
	village.add_Villageois( new VillageoisConcret(2, "Raoul", "villageois chiant" ) );
	//village.change_Villageois(  new Ouvrier( *village.get_Villageois(1) ) );

	village.faire_Construire( new Maison( "Maison2", "suite "), 1 );
	village.afficher_Batiments();
	cout << village.get_Villageois(1)->get_Energie();
/*
	village.afficher_Villageois();
	village.afficher_Batiments();

	village.change_Villageois(  new Bucheron( *village.get_Villageois(2) ) );
	village.change_Villageois(  new Bucheron( *village.get_Villageois(2) ) );
	//village.afficher_Villageois();

	//village.get_Villageois(2)->afficher();
	//cout << village.get_Villageois(2)->get_id();
	//village.get_Villageois(2)->get_Villageois()->afficher();
*/




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
	Villageois* v1 = new VillageoisConcret ( 1, "Tota", "Normal");
	//v1->change_Energie(-2);
	v1->afficher();
	//cout << v1->get_Energie() << endl;

	v1 = new Bucheron (*v1);
	v1 = new Ouvrier (*v1);
	//v1 = new Fermier (*v1);

	Batiment* b = v1->construire_Batiment( new Maison( "Maison","Chateau") );
	b->afficher();
*/
	/*v1->afficher();
	cout << v1->get_Energie() << endl;
	cout << v1->recolter_Bois() << endl;
	cout << v1->recolter_Nourriture() << endl;

	cout << v1->get_Energie() << endl;
	*/
	/*v1 = new Bucheron (*v1);
	v1->afficher();
	cout << v1->recolter_Bois() << endl;

	v1->set_Description("mollusque");
	v1->afficher();
	cout << v1->recolter_Bois() << endl;

	delete v1;
	*/





	//Tests Observer
/*
	village.add_Batiment( new Maison ( "Maison_1", "taudis" ) );
	village.add_Batiment( new Maison ( "Maison_2", "palace" ) );

	village.add_Villageois( new VillageoisConcret(1, "Toto",  "villageois content" ) );
	village.add_Villageois( new VillageoisConcret(2, "Raoul", "villageois chiant"  ) );
	village.add_Villageois( new VillageoisConcret(3, "Theo",  "villageois gentil"  ) );
	village.change_Villageois(  new Bucheron( *village.get_Villageois(2) ) );
	village.change_Villageois(  new Bucheron( *village.get_Villageois(2) ) );

	village.get_Villageois(2)->set_Observable( village.get_Batiment(2) );
	village.get_Villageois(1)->set_Observable( village.get_Batiment(2) );

	//village.remove_Villageois(2);
	//village.remove_Batiment(2);
	//village.afficher_Villageois();
	//village.afficher_Batiments();
	//village.remove_Batiment(2);
	//village.add_Batiment( new Maison ( "Maison_2", "palace" ) );
	//village.afficher_Batiments();

	village.get_Batiment(1)->set_Donnee("ouvert");
	village.get_Batiment(2)->set_Donnee("fermé");

	cout << village.get_Villageois(1)->get_Donnee() << endl;
	cout << village.get_Villageois(2)->get_Donnee() << endl;
	cout << village.get_Villageois(3)->get_Donnee() << endl << endl;

	village.get_Batiment(2)->set_Donnee("calque");
	//village.get_Batiment(2)->set_Donnee("fermé");

	cout << village.get_Villageois(1)->get_Donnee() << endl;
	cout << village.get_Villageois(2)->get_Donnee() << endl;
	cout << village.get_Villageois(3)->get_Donnee() << endl << endl;
*/




	//Tests SystemeJeu
/*
	SystemeJeu s("NYC");
	s.lancerJeu();
*/


}
