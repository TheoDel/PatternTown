/**
 *@file SystemeJeu.cpp
 *@brief Fichier contenant l'implementation de la classe SystemeJeu
 *@author Thomas Chevrel
 *@author Theo Delalande
 *@date 27 novembre 2014
 */

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
#include <string>
#include <limits>

using namespace std;



//--------------------------------------------------------
/**
 *@brief Constructeur de base
 *@param nomVillage Nom à donner au Village
 */
SystemeJeu::SystemeJeu( string nomVillage ) : village_( nomVillage ), jour_(1), promotions_disponibles(1) {}





//--------------------------------------------------------
/**
 *@brief Destructeur
 */
SystemeJeu::~SystemeJeu() {}





//--------------------------------------------------------
/**
 *@brief Méthode lançant la partie
 */
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





//--------------------------------------------------------
/**
 *@brief Lance un tour de jeu correspondant a une journee, permettant au joueur d'effectuer differentes actions
 */
void SystemeJeu::lancerTour() {
	
	//On crédite le nombre de promotions disponibles pour ce tour
	promotions_disponibles = 1;

	//Affichage du menu
	cout << "\n\n*** Bienvenue à " << village_.get_Nom() << " ***\nNous sommes le jour " << jour_ << endl
	<< "1> Voir la liste des villageois \n"
	<< "2> Donner un ordre a un villageois \n"
	<< "3> Promouvoir un villageois \n"
	<< "4> Voir la quantité de ressources \n"
	<< "5> Voir la liste des batiments \n"
	<< "6> Passer au jour suivant \n";
	
	//Selection
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





//--------------------------------------------------------
/**
 *@brief Interface pour donner un ordre a un villageois (mis dans une fonction a part pour lisibilite)
 */
void SystemeJeu::donnerOrdre() {

	//Choix du villageois par l'utilisateur
	cout << " Indiquez l'id du villageois a qui vous voulez donner ordre : \n >";
	int villageoischoisi(0);

	//Attente de la saisie d'un nombre
	//Tant que l'on ne saisie pas un nombre seul, on boucle
	while ( ! ( cin >> villageoischoisi and cin.get() == '\n' ) ) { 
		cin.clear(); cin.ignore( numeric_limits<streamsize>::max(), '\n' );
		cout << " >";
	}

	//Verification de l'existence d'un villageois
    if ( !village_.existe_Villageois( villageoischoisi ) ) {
    	cout << " Ce villageois n'existe pas."<< endl;
    	return;
    }

    Villageois* v = village_.get_Villageois( villageoischoisi );
    string descripv = v->get_Description();

    //Affichage de la liste des competences

    	// Si le villageois choisi est bucheron
   		if (descripv.find("bucheron") != string::npos) { cout << "  1> Couper du bois (pro)" << endl; }
   		// Si le villageois choisi n'est pas bucheron
    	else { cout << "  1> Couper du bois" << endl; }

    	// Si le villageois choisi est fermier
    	if (descripv.find("fermier") != string::npos) { cout << "  2> Recolter de la nourriture (pro)" << endl; }
    	// Si le villageois choisi n'est pas fermier
    	else { cout << "  2> Recolter de la nourriture" << endl; }

    	cout << "  3> Construire un batiment" << endl;
	
    //Selection de l'action à effectuer
    string entreeUtilisateur("");
    bool sortieBoucleInstruction(false);
    while (!sortieBoucleInstruction){
    	cout << "  >";
    	getline(cin, entreeUtilisateur);
    	if (entreeUtilisateur == "1") {
    		village_.faire_Recolter_Villageois(1,villageoischoisi);
    		sortieBoucleInstruction = true;
    	} else if (entreeUtilisateur == "2") {
    		village_.faire_Recolter_Villageois(2,villageoischoisi);
    		sortieBoucleInstruction = true;
    	} else if (entreeUtilisateur == "3") {
    		construire( villageoischoisi );
    		sortieBoucleInstruction =true;
    	}
    }
}





//--------------------------------------------------------
/**
 *@brief Interface pour promouvoir (ajouter une competence à) un villageois
 */
void SystemeJeu::promouvoir() {

	//On verifie qu'il reste des promotions disponibles
	if (promotions_disponibles<=0) {
		cout << " Vous ne pouvez plus donner de promotion aujourd'hui." << endl;
		return;
	}

	cout << " Indiquez l'id du villageois que vous voulez promouvoir : \n >";
	int villageoischoisi(0);

	//Attente de la saisie d'un nombre
	//Tant que l'on ne saisie pas un nombre seul, on boucle
	while ( ! ( cin >> villageoischoisi and cin.get() == '\n' ) ) {
		cin.clear(); cin.ignore( numeric_limits<streamsize>::max(), '\n' );
		cout << " >";
	}

	//On verifie que le villageois choisi est present dans le village
    if ( !village_.existe_Villageois( villageoischoisi ) ) {
    	cout << " Ce villageois n'existe pas."<< endl;
    	return;
    }

	cout << "  1> Promouvoir en bucheron" << endl;
   	cout << "  2> Promouvoir en fermier" << endl;
   	cout << "  3> Promouvoir en ouvrier" << endl;

	//Selection de l'action à effectuer
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





//--------------------------------------------------------
/**
 *@brief Interface pour construire (sous conditions) un batiment
 */
void SystemeJeu::construire( int id ) {

	cout << "   choisissez le batiment à construire" << endl
		 << "   1> Maison \n";

	//Selection de l'action à effectuer
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

	if (entreeUtilisateur == "1")	{ village_.faire_Construire( new Maison(nom,description), id );	}
}





//--------------------------------------------------------
/**
 *@brief Méthode qui retourne le village utilisé
 */
Village* SystemeJeu::get_Village() {
	return &village_;
}
