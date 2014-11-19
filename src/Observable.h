#ifndef OBSERVABLE_H
#define OBSERVABLE_H

class Observer;


// Interface Observable
class Observable {

	public:

		virtual ~Observable() {};

		virtual void enregistrerObs( Observer* observer ) = 0;
		virtual void supprimerObs( Observer* observer ) = 0;
		virtual void notifierObs() = 0;

};

#endif
