/**
 *@file Village.hpp
 *@brief Fichier contenant la definition de la classe Village
 *@author Thomas Chevrel
 *@author Theo Delalande
 *@date 27 novembre 2014
 */

#ifndef VILLAGE_HPP
#define VILLAGE_HPP

#include "etats/EtatVillage.hpp"
#include "etats/EtatVillageNormal.hpp"
#include "etats/EtatVillageFamine.hpp"
#include "etats/EtatVillageFete.hpp"
#include "../villageois/Villageois.hpp"
#include "../villageois/VillageoisConcret.hpp"
#include "../batiments/Batiment.hpp"
#include "Ressource.hpp"

#include <unordered_map>
#include <string>
#include <vector>


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
		EtatVillageFete* EtatVillageFete_; /**< Etat fête */

		static const int ration_hebdo_=2; /**< Quantité de nourriture consommée par habitant par jour */
		static const int satisf_moy_pour_fete=30; /**< Satisfaction moyenne nécessaire pour déclencher l'état fête */
		static const int proba_nouveau_villageois=50; /**< Pourcentage de chances d'arrivé d'un nouveau villageois dans l'état fête*/
        static std::vector<std::string> liste_noms; /** Liste de noms aéatoires possibles pour les nouveaux villageois (à définir dans le .cpp) */

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

		static std::string donner_un_nom();

};

//--------------------------------------------------------
#endif /* VILLAGE_HPP */
