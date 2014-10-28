#include <iostream>
#include "Village.h"
#include "VillageoisConcret.h"
#include "Bucheron.h"
#include "Competence.h"

using namespace std;

int main()
{

	cout << "test" << endl;

	Village village;

	village.add_Villageois( new VillageoisConcret(1, "Toto", "villageois content", &village) );
	village.add_Villageois( new VillageoisConcret(2, "Raoul", "villageois chiant", &village) );

	//village.afficher_Villageois();
	cout << endl;

	//Bucheron b( village.get_Villageois(2) );
	//village.change_Villageois( &b ) ;
	Bucheron ba( village.get_Villageois(2) );
	village.change_Villageois(  &ba ) ;

	//village.change_Villageois(  village.get_Villageois(2)->get_Villageois() ) ;

	//village.afficher_Villageois();
	cout <<endl;


	cout << village.get_Villageois(2)->get_Description() << endl;








	VillageoisConcret v1( 1, "Tota", "Normal", &village );
	Bucheron b1(&v1);
	Bucheron b2(&b1);
	Bucheron b3(&b2);

	v1.afficher();
	b1.afficher();
	b3.afficher();





}
