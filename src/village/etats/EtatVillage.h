#ifndef ETATVILLAGE_H_
#define ETATVILLAGE_H_

#include "../../villageois/Villageois.h"
#include "../../batiments/Batiment.h"
class Village;

class EtatVillage {
	protected :
		Village* village_;

	public :
		// Constructeurs/Destructeurs
		EtatVillage(Village* v);
		virtual ~EtatVillage()=0;

		// Actions de jeu
		virtual void faire_Recolter_Villageois(int idRessource, int idVillageois);
		virtual void faire_Construire( Batiment* b, int idVillageois );
};



#endif /* ETATVILLAGE_H_ */
