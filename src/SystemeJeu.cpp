#include <iostream>
#include <string>
#include "SystemeJeu.h"
#include "Village.h"
#include "VillageoisConcret.h"

using namespace std;

SystemeJeu::SystemeJeu() : jour_(1) {}

SystemeJeu::~SystemeJeu() {
    delete &village_;
}

// Fonction à appeler dans le main pour lancer la partie
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

// Lance un tour de jeu correspondant à une journée, permettant au joueur d'effectuer différentes actions
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
        getline(cin, entreeUtilisateur); //(TODO ?) Saisie non sécurisée

        if (entreeUtilisateur == "1")
            village_.afficher_Villageois();
        else if (entreeUtilisateur == "2")
            cout << "[Donner ordre villageois] \n";
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

// retourne le village du systeme
Village* SystemeJeu::get_Village() {
	return &village_;
}
