#include "SystemeJeu.h"
#include "Village.h"
#include "Observer.h"
#include "Villageois.h"
#include "VillageoisConcret.h"
#include "Competence.h"
#include "Bucheron.h"
#include "Observable.h"
#include "Batiment.h"
#include "Maison.h"
#include "Ressource.h"

#include <iostream>
#include <string>
#include <limits>

using namespace std;



SystemeJeu::SystemeJeu( string nomVillage ) : village_( nomVillage ), jour_(1) {}


SystemeJeu::~SystemeJeu() {}



///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////





///////////////////////////////////////////////////////////////////////////////
// Fonction a appeler dans le main pour lancer la partie
void SystemeJeu::lancerJeu() {

	//Création du jeu de données de départ
	village_.get_Ressources()->change_Ressource(1,5);
	village_.get_Ressources()->change_Ressource(2,20);
	village_.add_Batiment( new Maison ( "Maison_1", "taudis" ) );
	village_.add_Villageois( new VillageoisConcret(1, "Toto", "villageois content", village_.get_Batiment(1) ) );
	village_.add_Villageois( new VillageoisConcret(2, "Raoul", "villageois chiant", village_.get_Batiment(1) ) );

	//Lance 3 tours de jeu
	for (int i = 1; i<=3; i++){
		lancerTour();
		++jour_;
	}
}



///////////////////////////////////////////////////////////////////////////////
// Lance un tour de jeu correspondant a une journee, permettant au joueur d'effectuer differentes actions
void SystemeJeu::lancerTour() {

	cout << "\nBienvenue a " << village_.get_Nom() << " - jour " << jour_ << "\n"
	<< "1> Voir villageois \n"
	<< "2> Donner un ordre a un villageois \n"
	<< "3> Promouvoir un villageois \n"
	<< "4> Voir ressources \n"
	<< "5> Voir batiments \n"
	<< "6> Passer au jour suivant \n";

	string entreeUtilisateur("");
	bool sortieBoucleInstruction(false);

	while (!sortieBoucleInstruction){
		cout << ">";
		getline(cin, entreeUtilisateur);
		if (entreeUtilisateur == "1")		{	village_.afficher_Villageois(); }
		else if (entreeUtilisateur == "2")	{	donnerOrdre(); }
		else if (entreeUtilisateur == "3")	{	promouvoir(); }
        else if (entreeUtilisateur == "4")	{  	village_.get_Ressources()->afficher_Ressources(); }
        else if (entreeUtilisateur == "5")	{	cout << "[Affichage batiments] \n"; }
        else if (entreeUtilisateur == "6")	{	sortieBoucleInstruction = true; }
    }
}





///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////





//Interface pour donner un ordre a un villageois (mis dans une fonction a part pour lisibilite)
void SystemeJeu::donnerOrdre() {

	// Choix du villageois par l'utilisateur
	cout << " Indiquez l'id du villageois a qui vous voulez donner ordre : \n >";
	int villageoischoisi(0);

	// TODO on peut toujours entrez n'importe quel nombre
	while ( ! ( cin >> villageoischoisi and cin.get() == '\n' ) ) { // tant que l'on ne saisie pas un nombre seul
		cin.clear(); cin.ignore( numeric_limits<streamsize>::max(), '\n' );
		cout << " >";
	}

	// Verification de l'existence d'un villageois
    if ( !village_.existe_Villageois( villageoischoisi ) ) {
    	cout << " Ce villageois n'existe pas."<< endl;
    	return;
    }

    // AFFICHAGE DE LA LISTE DE CHOIX DES COMPETENCES
    Villageois* v = village_.get_Villageois( villageoischoisi );
    string descripv = v->get_Description();

    	// Si le villageois choisi est bucheron
    	if (descripv.find("bucheron") != string::npos)
    		cout << "  1> Couper du bois (pro)" << endl;
    	// Si le villageois choisi n'est pas bucheron
    	else
    		cout << "  1> Couper du bois" << endl;

    	// Si le villageois choisi est fermier
    	if (descripv.find("fermier") != string::npos)
    		cout << "  2> Recolter de la nourriture (pro)" << endl;
    	// Si le villageois choisi n'est pas fermier
    	else
    		cout << "  2> Recolter de la nourriture" << endl;

    	cout << "  3> Construire un batiment" << endl;

    string entreeUtilisateur("");
    bool sortieBoucleInstruction(false);

    	while (!sortieBoucleInstruction){
    		cout << "  >";
    		getline(cin, entreeUtilisateur); //(TODO ?) Saisie non securisee

    		if (entreeUtilisateur == "1") {
    			village_.faire_Recolter_Villageois(1,villageoischoisi);
    			sortieBoucleInstruction = true;
    		}
    		else if (entreeUtilisateur == "2") {
    			village_.faire_Recolter_Villageois(2,villageoischoisi);
    			sortieBoucleInstruction = true;
    		}
    		else if (entreeUtilisateur == "3") {
    			cout << "[Construction de bâtiment]";
    			sortieBoucleInstruction =true;
    		}
       	}
}





///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////





//
void SystemeJeu::promouvoir() {

	cout << " Indiquez l'id du villageois que vous voulez promouvoir : \n >";
	int villageoischoisi(0);

	while ( ! ( cin >> villageoischoisi and cin.get() == '\n' ) ) { // tant que l'on ne saisie pas un nombre seul
		cin.clear(); cin.ignore( numeric_limits<streamsize>::max(), '\n' );
		cout << " >";
	}

    if ( !village_.existe_Villageois( villageoischoisi ) ) {
    	cout << " Ce villageois n'existe pas."<< endl;
    	return;
    }

    //Villageois* v = village_.get_Villageois( villageoischoisi );
	cout << "  1> Promouvoir en bucheron" << endl;
   	cout << "  2> Promouvoir en fermier" << endl;

    string entreeUtilisateur("");
    bool sortieBoucleInstruction(false);

    	while (!sortieBoucleInstruction){
    		cout << "  >";
    		getline(cin, entreeUtilisateur);

    		if (entreeUtilisateur == "1") {
    			village_.change_Villageois( new Bucheron( *village_.get_Villageois( villageoischoisi ) ) );
    			sortieBoucleInstruction = true;
    		}
    		else if (entreeUtilisateur == "2") {
				cout << "Fermier" << endl;
    			sortieBoucleInstruction = true;
    		}
       	}
}






///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////





// retourne le village du systeme
Village* SystemeJeu::get_Village() {
	return &village_;
}
