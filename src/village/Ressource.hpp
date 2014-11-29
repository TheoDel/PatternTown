/**
 *@file Ressource.hpp
 *@brief Fichier contenant la definition de la classe Ressource
 *@author Thomas Chevrel
 *@author Theo Delalande
 *@date 27 novembre 2014
 */

#ifndef RESSOURCE_HPP
#define RESSOURCE_HPP


//--------------------------------------------------------
/**
 *@class Ressource
 *@brief Classe représentant les differentes ressources du jeu
 */

class Ressource {

	private :

		int stock_Bois_; /**< Quantité de bois en stock */
		int stock_Nourriture_; /*< Quantité de nourriture en stock  */


	public :

		//Constructeurs/Destructeurs
		Ressource();
		~Ressource();

		//Getters
		int get_Ressource( int id );

		//Setter/Modifiers
		void change_Ressource ( int id, int quantite );
		void set_Ressource ( int id, int quantite );


		void afficher_Ressources();

};

//--------------------------------------------------------
#endif /* RESSOURCE_HPP */
