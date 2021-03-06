#include "SystemeJeu.hpp"
#include "village/Village.hpp"
#include "villageois/Observer.hpp"
#include "villageois/Villageois.hpp"
#include "villageois/VillageoisConcret.hpp"
#include "villageois/decorations/Competence.hpp"
#include "villageois/decorations/Bucheron.hpp"
#include "villageois/decorations/Fermier.hpp"
#include "villageois/decorations/Ouvrier.hpp"
#include "batiments/Observable.hpp"
#include "batiments/Batiment.hpp"
#include "batiments/Maison.hpp"
#include "village/Ressource.hpp"

#include <iostream>

using namespace std;



int main() {


	SystemeJeu s("Trifouilly les trois oies");
	s.lancerJeu();




	//Village village("Pattern City");


	//------------------------------------------------------------------
    //Tests village/villageois
/*
	village.add_Batiment( new Maison ( "Maison_1", "taudis" ) );
	village.add_Batiment( new Maison ( "Maison_2", "taudis" ) );

	village.add_Villageois( new VillageoisConcret( "Toto", "villageois content" ) );
	village.add_Villageois( new VillageoisConcret( "Raoul", "villageois chiant" ) );
	village.add_Villageois( new VillageoisConcret( "fre", "villageois chiant" ) );
	village.change_Villageois(  new Ouvrier( *village.get_Villageois(1) ) );
	village.change_Villageois(  new Fermier( *village.get_Villageois(1) ) );


	village.faire_Construire( new Maison( "MaisonOuvrier", "suite "), 1 );
	village.faire_Construire( new Maison( "Maison1", "suite "), 3 );
	village.faire_Construire( new Maison( "Maison2", "suite "), 1 );


	cout << village.get_Villageois(1)->get_Energie() << endl;
	cout << village.get_Constructions() << endl;
	cout << village.get_Population() << endl;

	village.remove_Batiment(1);

	village.afficher_Batiments();

	village.afficher_Villageois();
*/
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






	//------------------------------------------------------------------
	//Tests gestion des ressources
/*
	village.get_Ressources()->afficher_Ressources();
	village.get_Ressources()->change_Ressource(1,village.get_Villageois(1)->recolter_Bois());
	village.get_Ressources()->change_Ressource(1,village.get_Villageois(2)->recolter_Bois());
	village.get_Ressources()->afficher_Ressources();
*/






	//------------------------------------------------------------------
    //Test gestion d'energie des villageois
/*
	for (int i = 0; i<6; i++){
        village.get_Ressources()->change_Ressource(1,village.get_Villageois(1)->recolter_Bois());
        cout << village.get_Villageois(1)->get_Energie() << endl;
    }
	village.get_Ressources()->afficher_Ressources();
*/






	//------------------------------------------------------------------
    //Tests decorator
/*
	Villageois* v1 = new VillageoisConcret ( "Tota", "Normal" );
	//v1->change_Energie(-2);
	v1->afficher();
	//cout << v1->get_Energie() << endl;

	v1 = new Bucheron (*v1);
	//v1 = new Ouvrier (*v1);
	v1 = new Fermier (*v1);
	v1->afficher();

	Batiment* b = v1->construire_Batiment( new Maison( "Maison","Chateau") );
	//b->afficher();
*/
/*
	v1->afficher();
	cout << v1->get_Energie() << endl;
	cout << v1->recolter_Bois() << endl;
	cout << v1->recolter_Nourriture() << endl;

	cout << v1->get_Energie() << endl;
*/
/*
	v1 = new Bucheron (*v1);
	v1->afficher();
	cout << v1->recolter_Bois() << endl;

	v1->set_Description("mollusque");
	v1->afficher();
	cout << v1->recolter_Bois() << endl;

	delete v1;
*/






	//------------------------------------------------------------------
	//Tests Observer
/*
	village.add_Batiment( new Maison ( "Maison_1", "taudis" ) ); // id=1
	village.add_Batiment( new Maison ( "Maison_2", "palace" ) ); // id=2

	village.add_Villageois( new VillageoisConcret( "Toto",  "villageois content" ) ); // id=1
	village.add_Villageois( new VillageoisConcret( "Raoul", "villageois chiant"  ) ); // id=2
	village.add_Villageois( new VillageoisConcret( "Theo",  "villageois gentil"  ) ); // id=3
	village.change_Villageois(  new Bucheron( *village.get_Villageois(2) ) );
	village.change_Villageois(  new Bucheron( *village.get_Villageois(2) ) );

	village.get_Batiment(1)->set_indiceSatisfaction(5);
	village.get_Batiment(2)->set_indiceSatisfaction(20);

	cout << village.get_Villageois(1)->get_indiceBatiment() << endl;
	cout << village.get_Villageois(2)->get_indiceBatiment() << endl;
	cout << village.get_Villageois(3)->get_indiceBatiment() << endl << endl;

	village.get_Villageois(2)->set_Observable( village.get_Batiment(2) );
	village.get_Villageois(1)->set_Observable( village.get_Batiment(2) );

	cout << village.get_Villageois(1)->get_indiceBatiment() << endl;
	cout << village.get_Villageois(2)->get_indiceBatiment() << endl;
	cout << village.get_Villageois(3)->get_indiceBatiment() << endl << endl;

	village.get_Batiment(2)->set_indiceSatisfaction(7);
	//village.get_Villageois(2)->set_Observable( nullptr );
	village.get_Villageois(3)->set_Observable( village.get_Batiment(1) );

	cout << village.get_Villageois(1)->get_indiceBatiment() << endl;
	cout << village.get_Villageois(2)->get_indiceBatiment() << endl;
	cout << village.get_Villageois(3)->get_indiceBatiment() << endl << endl;

	village.get_Batiment(2)->set_indiceSatisfaction(14);
	village.get_Batiment(2)->set_indiceSatisfaction(1);
	village.remove_Batiment(1);
	village.remove_Batiment(2);

	//village.remove_Villageois(1);
	village.afficher_Batiments();

	cout << village.get_Villageois(1)->get_indiceBatiment() << endl;
	cout << village.get_Villageois(2)->get_indiceBatiment() << endl;
	cout << village.get_Villageois(3)->get_indiceBatiment() << endl << endl;
*/

}
