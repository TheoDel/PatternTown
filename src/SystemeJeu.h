#ifndef SYSTEMEJEU_H_INCLUDED
#define SYSTEMEJEU_H_INCLUDED

#include "Village.h"

class SystemeJeu {

    private :

        Village village_;
        int jour_;

		// méthodes privées
    	void lancerTour();
        void donnerOrdre();
		void promouvoir();


    public :

		// Constructeurs/Destructeurs
        	SystemeJeu( std::string nomVillage );
        	~SystemeJeu();

        // Getter
        	Village* get_Village();

       	void lancerJeu();

};

#endif
