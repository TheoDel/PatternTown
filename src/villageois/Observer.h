#ifndef OBSERVER_H
#define OBSERVER_H

class Observable;
#include <string>


// Interface Observer
class Observer {

	public :

		virtual ~Observer() {};

		virtual int get_id() = 0;	// pour Villageois !!
		virtual void set_Observable( Observable* obs ) = 0;
		virtual void actualiser( int newIndice ) = 0;

};

#endif
