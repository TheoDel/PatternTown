#ifndef ETATVILLAGE_H_
#define ETATVILLAGE_H_

class Village;

class EtatVillage {
	private :
		Village* village_;

	public :
		// Constructeurs/Destructeurs
		EtatVillage(Village* v);
		~EtatVillage();
};



#endif /* ETATVILLAGE_H_ */
