/**
 *@file Observer.hpp
 *@brief Fichier contenant la definition de l'interface Observer
 *@author Thomas Chevrel
 *@author Theo Delalande
 *@date 27 novembre 2014
 */

#ifndef OBSERVER_HPP
#define OBSERVER_HPP

class Observable;

#include <string>


//--------------------------------------------------------
/**
 *@class Observer
 *@brief Interface représentant l'observateur dans le pattern Observer
 */

class Observer {

	public :

		virtual ~Observer() {};

		virtual int get_id() = 0;	//requis pour Villageois !!
		virtual void set_Observable( Observable* obs ) = 0;
		virtual void actualiser( int newIndice ) = 0;

};

//--------------------------------------------------------
#endif /* OBSERVER_HPP */
