#include <iostream>
#include "Village.h"
#include "VillageoisConcret.h"
#include "Bucheron.h"
#include "Competence.h"

using namespace std;

int main()
{

	cout << "test" << endl;

    //Tests village/villageois
	Village village;

	village.add_Villageois( new VillageoisConcret(1, "Toto", "villageois content", &village) );
	village.add_Villageois( new VillageoisConcret(2, "Raoul", "villageois chiant", &village) );

	//village.afficher_Villageois();
	cout << endl;

	Bucheron ba( village.get_Villageois(2) );
	village.change_Villageois(  &ba ) ;

	//village.change_Villageois(  village.get_Villageois(2)->get_Villageois() ) ;

	village.afficher_Villageois();
	village.get_Ressources()->afficher_Ressources();

	village.change_Ressource(1,village.get_Villageois(1)->recolter_Bois());
	village.change_Ressource(1,village.get_Villageois(2)->recolter_Bois());

	village.get_Ressources()->afficher_Ressources();

    //Tests decorator
    /*
	VillageoisConcret v1( 1, "Tota", "Normal", &village );
	Bucheron b1(&v1);
	Bucheron b2(&b1);
	Bucheron b3(&b2);

	v1.afficher();
	cout  << endl << v1.recolter_Bois();
	b1.afficher();
	cout  << endl << b1.recolter_Bois();
	b3.afficher();
	cout  << endl << b3.recolter_Bois();
	*/
}
