/**
 *@file Batiment.h
 *@brief Fichier contenant la definition de la classe Batiment
 *@author Thomas Chevrel
 *@author Theo Delalande
 *@date 27 novembre 2014
 */

#ifndef BATIMENT_H
#define BATIMENT_H

class Observer;
#include "Observable.h"
#include <string>
#include <vector>
#include <unordered_map>


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

		//Setters
		void set_Description( std::string d );

		////////////////////////////////////////////////////////////
		// Méthodes liées aux pattern Observer
		int get_indiceSatisfaction();
		void set_indiceSatisfaction( int is );
		std::unordered_map<int,Observer*> get_Observers();
		void enregistrerObs( Observer* observer );
		void supprimerObs( Observer* observer );
		void notifierObs();
		////////////////////////////////////////////////////////////

		void afficher();

};

//--------------------------------------------------------
#endif
