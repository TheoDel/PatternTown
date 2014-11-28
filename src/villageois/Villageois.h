/**
 *@file Villageois.h
 *@brief Fichier contenant la definition de la classe Villageois
 *@author Thomas Chevrel
 *@author Theo Delalande
 *@date 27 novembre 2014
 */

#ifndef VILLAGEOIS_H
#define VILLAGEOIS_H

#include "Observer.h"
#include "../batiments/Observable.h"
#include "../batiments/Batiment.h"
#include <string>


//--------------------------------------------------------
/**
 *@class VillageoisConcret
 *@brief Classe abstraite représentant les villageois
 */

class Villageois : public Observer {

    private:

		// pour l'attribution automatique de id
		static int NEXTID_; /**< Identifiant du prochain villageois créé */

		// Attributs pour Observer
		Observable* observable_; /**< Sujet observé par le villageois */
		int indiceBatiment_; /**< Indice de satisfaction lié au batiment observé */

		// Attributs propres
		int id_; /**< Identifiant du villageois */
		std::string nom_; /**< Nom du villageois */
    	int energie_; /**< Niveau d'energie du villageois */
		int satisfaction_; /**< Niveau de satisfaction du villageois */


    protected:

		std::string description_; /**< Description breve du villageois */


    public:

		// Constructeurs/Destructeurs
		Villageois();
		Villageois( std::string nom, std::string description );
		virtual ~Villageois() = 0;

		// Getters
		virtual int get_id();
		virtual std::string get_Nom();
		virtual std::string get_Description();
		virtual int get_Energie();
		virtual int get_Satisfaction();
		virtual Villageois* get_Villageois();

		// Setters
		virtual void set_Description( std::string d );
		virtual void change_Energie( int val );
		virtual void change_Satisfaction( int val );

		// < Observer >
		virtual Observable* get_Observable();
		virtual int get_indiceBatiment();
		virtual void set_Observable( Observable* obs );
		void actualiser( int newIndice );

		// Actions de jeu
		virtual int recolter_Bois();
		virtual int recolter_Nourriture();
		virtual Batiment* construire_Batiment( Batiment* b );


		void afficher();

};

//--------------------------------------------------------
#endif
