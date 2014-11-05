#include "SystemeJeu.h"
#include "Village.h"
#include "VillageoisConcret.h"

#include <iostream>
#include <string>
#include <limits>

using namespace std;



SystemeJeu::SystemeJeu() : jour_(1) {}


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
	village_.add_Villageois( new VillageoisConcret(1, "Toto", "villageois content", &village_) );
	village_.add_Villageois( new VillageoisConcret(2, "Raoul", "villageois chiant", &village_) );

	//Lance 3 tours de jeu
	for (int i = 1; i<=3; i++){
		lancerTour();
		++jour_;
	}
}



///////////////////////////////////////////////////////////////////////////////
// Lance un tour de jeu correspondant a une journee, permettant au joueur d'effectuer differentes actions
void SystemeJeu::lancerTour() {

	cout << "\nVillage - jour " << jour_ << "\n"
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
		getline(cin, entreeUtilisateur); //(TODO ?) Saisie non securisee

		//(TODO ?) plutot un switch case � la place des if-then-else ?

		if (entreeUtilisateur == "1")
			village_.afficher_Villageois();
        else if (entreeUtilisateur == "2")
        	donnerOrdre();
        else if (entreeUtilisateur == "3")
        	cout << "[Promotion de villageois] \n";
        else if (entreeUtilisateur == "4")
        	village_.get_Ressources()->afficher_Ressources();
        else if (entreeUtilisateur == "5")
        	cout << "[Affichage batiments] \n";
        else if (entreeUtilisateur == "6")
        	sortieBoucleInstruction = true;
        else
            ;
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
    			village_.get_Ressources()->change_Ressource(1,village_.get_Villageois(villageoischoisi)->recolter_Bois());
    			sortieBoucleInstruction = true;
    		}
    		else if (entreeUtilisateur == "2") {
    			village_.get_Ressources()->change_Ressource(2,village_.get_Villageois(villageoischoisi)->recolter_Nourriture());
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



// retourne le village du systeme
Village* SystemeJeu::get_Village() {
	return &village_;
}
