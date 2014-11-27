/**
 *@file Village.h
 *@brief Fichier contenant la definition de la classe Village
 *@author Thomas Chevrel
 *@author Theo Delalande
 *@date 27 novembre 2014
 */

#ifndef VILLAGE_H
#define VILLAGE_H

#include "etats/EtatVillage.h"
#include "etats/EtatVillageNormal.h"
#include "etats/EtatVillageFamine.h"
#include "../villageois/Villageois.h"
#include "../batiments/Batiment.h"
#include "Ressource.h"

#include <unordered_map>
#include <string>


//--------------------------------------------------------
/**
 *@class Village
 *@brief Classe représentant le village
 */

class Village {

	private :

		std::string nom_; /**< Nom du village */
		std::unordered_map< int, Villageois* > villageois_; /**< Liste des villageois */
		std::unordered_map< int, Batiment*   > batiments_;  /**< Liste des batiments */
		Ressource ressources_;	/**< Ressources du village */

		EtatVillage* etatVillage_; /**< Etat courant du village */
		EtatVillageNormal* etatVillageNormal_; /**< Etat normal */
		EtatVillageFamine* etatVillageFamine_; /**< Etat famine */

	public :

		// Constructeurs/Destructeurs
		Village( std::string nom );
		~Village();

		// Testing
		bool existe_Batiment( int id );
		bool existe_Villageois( int id );

		// Getters
		std::string get_Nom();
		Villageois* get_Villageois( int id );
		Batiment* get_Batiment( int id );
		Ressource* get_Ressources();
		int get_Ressource( int id );
		int get_Population();
		int get_Constructions();

		// Setters
		void add_Villageois( Villageois* v );
		void change_Villageois( Villageois* v );
		void add_Batiment( Batiment* b );
		void change_Ressource( int id, int quantite );
		void remove_Villageois( int id );
		void remove_Batiment( int id );

		// Actions de jeu
		void faire_Recolter_Villageois(int idRessource, int idVillageois);
		void faire_Construire( Batiment* b, int idVillageois );
		void jour_Suivant();


		void afficher_Villageois();
		void afficher_Batiments();

};

//--------------------------------------------------------
#endif
