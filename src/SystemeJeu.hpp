/**
 *@file SystemeJeu.hpp
 *@brief Fichier contenant la definition de la classe SystemeJeu
 *@author Thomas Chevrel
 *@author Theo Delalande
 *@date 27 novembre 2014
 */

#ifndef SYSTEMEJEU_HPP
#define SYSTEMEJEU_HPP

#include "village/Village.hpp"


//--------------------------------------------------------
/**
 *@class SystemeJeu
 *@brief Classe représentant l'environnement de jeu
 */

class SystemeJeu {

    private :

        Village village_;			/**< Village dans lequel se deroule le jeu */
        int jour_;					/**< Jour courant */
        int promotions_disponibles; /**< Nombre d'ajout de compétences restantes pour les villageois */

		// Méthodes privées
    	void lancerTour();
        void donnerOrdre();
		void promouvoir();
		void construire( int id );
		void ameliorerBatiment( int id );
		void attribuerBatiment();


    public :

		// Constructeurs/Destructeurs
        SystemeJeu( std::string nomVillage );
        ~SystemeJeu();

        // Getter
        Village* get_Village();

       	void lancerJeu();

};

//--------------------------------------------------------
#endif /* SYSTEMEJEU_HPP */
