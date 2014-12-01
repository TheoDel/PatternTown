/**
 *@file Batiment.hpp
 *@brief Fichier contenant la definition de la classe Batiment
 *@author Thomas Chevrel
 *@author Theo Delalande
 *@date 27 novembre 2014
 */

#ifndef BATIMENT_HPP
#define BATIMENT_HPP

#include "Observable.hpp"
#include "../villageois/Observer.hpp"

#include <unordered_map>
#include <string>


//--------------------------------------------------------
/**
 *@class Batiment
 *@brief Classe abstraite implementant l'interface Observable et représentant les batiments
 */

class Batiment : public Observable {

	private:

		// pour l'attribution automatique de l'identifiant
		static int NEXTID_; /**< Identifiant du prochain batiment créé */

	protected :

		int id_; /**< Identifiant du batiment */
		std::string nom_; /**< Nom du batiment */
		std::string description_; /**< Description breve du batiment */

		std::unordered_map< int, Observer* > observers_; /**< Liste des observateurs de ce batiment */
		int indiceSatisfaction_; /**< Indice de satisfaction du batiment */


	public :

		// Constructeurs/Destructeurs
		Batiment( std::string nom, std::string description );
		virtual ~Batiment() = 0;

		// Getters
		int get_id();
		std::string get_Nom();
		std::string get_Description();
		virtual unsigned get_HabitantsMax() = 0;

		//Setters
		void set_Description( std::string d );

		////////////////////////////////////////////////////////////
		// Méthodes liées aux pattern Observer
		int get_indiceSatisfaction();
		void set_indiceSatisfaction( int is );
		std::unordered_map<int,Observer*> get_Observers();
		void enregistrerObs( Observer* observer );	//@Implements
		void supprimerObs( Observer* observer );	//@Implements
		void notifierObs();							//@Implements
		////////////////////////////////////////////////////////////

		void afficher();

};

//--------------------------------------------------------
#endif /* BATIMENT_HPP */
