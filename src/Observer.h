#ifndef OBSERVER_H
#define OBSERVER_H

class Observable;
#include <string>


// Classe abstraite Observer
class Observer {

	protected:

		Observable* observable_;
		std::string donnee_;


	public :

		// Constructeurs/Destructeurs
			Observer();
			Observer( Observable* o );
			virtual ~Observer() = 0;

		// Getters
			virtual int get_id() = 0;	// non implementer ici !!
			virtual Observable* get_Observable();
			virtual std::string get_Donnee();

		//Setters
			virtual void set_Observable( Observable* obs );

		virtual void actualiser( std::string donnee );

};

#endif
