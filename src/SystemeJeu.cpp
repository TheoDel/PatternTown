#include "SystemeJeu.h"
#include "village/Village.h"
#include "villageois/Observer.h"
#include "villageois/Villageois.h"
#include "villageois/VillageoisConcret.h"
#include "villageois/decorations/Competence.h"
#include "villageois/decorations/Bucheron.h"
#include "villageois/decorations/Fermier.h"
#include "villageois/decorations/Ouvrier.h"
#include "batiments/Observable.h"
#include "batiments/Batiment.h"
#include "batiments/Maison.h"
#include "village/Ressource.h"

#include <iostream>
#include <string>
#include <limits>

using namespace std;



SystemeJeu::SystemeJeu( string nomVillage ) : village_( nomVillage ), jour_(1), promotions_disponibles(1) {}


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
	village_.add_Villageois( new VillageoisConcret( "Toto", "villageois content" ) );
	village_.add_Villageois( new VillageoisConcret( "Raoul", "villageois chiant" ) );

	//Lance 3 tours de jeu
	for (int i = 1; i<=3; i++){
		lancerTour();
		++jour_;
	}
}





///////////////////////////////////////////////////////////////////////////////
// Lance un tour de jeu correspondant a une journee, permettant au joueur d'effectuer differentes actions
void SystemeJeu::lancerTour() {
	//On crédite le nombre de promotions disponibles pour ce tour
	promotions_disponibles = 1;

	cout << "\n\n*** Bienvenue à " << village_.get_Nom() << " ***\nNous sommes le jour " << jour_ << endl
	<< "1> Voir la liste des villageois \n"
	<< "2> Donner un ordre a un villageois \n"
	<< "3> Promouvoir un villageois \n"
	<< "4> Voir la quantité de ressources \n"
	<< "5> Voir la liste des batiments \n"
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
        else if (entreeUtilisateur == "5")	{	village_.afficher_Batiments(); }
        else if (entreeUtilisateur == "6")	{	sortieBoucleInstruction = true; }
    }

	//En fin de tour, le village effectue ses actions
	village_.jour_Suivant();
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
    			construire( villageoischoisi );
    			sortieBoucleInstruction =true;
    		}
       	}
}





///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////





//
void SystemeJeu::promouvoir() {
	if (promotions_disponibles<=0) {
		cout << " Vous ne pouvez plus donner de promotion aujourd'hui." << endl;
		return;
	}

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
   	cout << "  3> Promouvoir en ouvrier" << endl;

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
    			village_.change_Villageois( new Fermier( *village_.get_Villageois( villageoischoisi ) ) );
    			sortieBoucleInstruction = true;
    		}
    		else if (entreeUtilisateur == "3") {
    			village_.change_Villageois( new Ouvrier( *village_.get_Villageois( villageoischoisi ) ) );
    		    sortieBoucleInstruction = true;
    		    		}
       	}

    	//Diminue le nombre de promotions disponibles pour ce tour
    	--promotions_disponibles;
    	cout << "  La promotion a bien été donnée !"<< endl;
}






///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////




// constuire un batiment
void SystemeJeu::construire( int id ) {

	cout << "   choisissez le batiment à construire" << endl
		<< "   1> Maison \n";

	string entreeUtilisateur("");
	bool sortieBoucleInstruction(false);

	while (!sortieBoucleInstruction){
		cout << "   >";
		getline(cin, entreeUtilisateur);
		if ( entreeUtilisateur == "1" )	{
			sortieBoucleInstruction = true;
		}
	}

	string nom;
	cout << "   Entrez son nom\n   >";
	getline(cin, nom);

	string description;
	cout << "   Entrez sa description\n   >";
	getline(cin, description);

	if (entreeUtilisateur == "1")		{
		village_.faire_Construire( new Maison(nom,description), id );
	}
}









///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////





// retourne le village du systeme
Village* SystemeJeu::get_Village() {
	return &village_;
}
