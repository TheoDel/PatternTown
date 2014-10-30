#ifndef RESSOURCE_H
#define RESSOURCE_H

class Ressource {

	private :

		int stock_Bois_;
		int stock_Nourriture_;


	public :

		Ressource();
		~Ressource();

		int get_Ressource( int id );
		void change_Ressource ( int id, int quantite );

		void afficher_Ressources();

};

#endif
