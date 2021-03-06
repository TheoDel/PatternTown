/**
 *@file Observable.hpp
 *@brief Fichier contenant la definition de l'interface Observable
 *@author Thomas Chevrel
 *@author Theo Delalande
 *@date 27 novembre 2014
 */

#ifndef OBSERVABLE_HPP
#define OBSERVABLE_HPP

class Observer;


//--------------------------------------------------------
/**
 *@class Observable
 *@brief Interface représentant le sujet observé dans le pattern Observer
 */

class Observable {

	public:

		virtual ~Observable() {};

		virtual void enregistrerObs( Observer* observer ) = 0;
		virtual void supprimerObs( Observer* observer ) = 0;
		virtual void notifierObs() = 0;

};

//--------------------------------------------------------
#endif /* OBSERVABLE_HPP */
