#ifndef SYSTEMEJEU_H_INCLUDED
#define SYSTEMEJEU_H_INCLUDED

#include "Village.h"

class SystemeJeu {

    private :

        Village village_;
        int jour_;

        void donnerOrdre();
    	void lancerTour();


    public :

		// Constructeurs/Destructeurs
        	SystemeJeu();
        	~SystemeJeu();

        // Getter
        	Village* get_Village();

       	void lancerJeu();

};

#endif
