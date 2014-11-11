#ifndef OBSERVABLE_H
#define OBSERVABLE_H

class Observer;
#include <string>
#include <vector>


// Classe abstraite Observable
class Observable {

	protected:

		std::vector<Observer*> observers_;
		std::string donnee_;


	public:

		// Constructeurs/Destructeurs
			Observable();
			virtual ~Observable() = 0;

		// Getters
			std::string get_Donnee();
			std::vector<Observer*> get_Observers();

		//Setters
			void set_Donnee( std::string donnee );

		void enregistrerObs( Observer* observer );
		void supprimerObs( Observer* observer );
		void notifierObs();

};

#endif
