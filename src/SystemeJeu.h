#ifndef SYSTEMEJEU_H_INCLUDED
#define SYSTEMEJEU_H_INCLUDED

#include "Village.h"

class SystemeJeu {

    private :

        Village village_;
        int jour_;

    public :

        SystemeJeu();
		~SystemeJeu();

        void lancerJeu();
        void lancerTour();

		Village* get_Village();



};


#endif // SYSTEMEJEU_H_INCLUDED
