#ifndef DEF_VILLAGEOIS
#define DEF_VILLAGEOIS

#include <string>

class Villageois
{
    public:

	void update();
	int get_id();
	int get_vie();

    private:

	int m_id;
    	int m_vie;
    	int m_energie;
	int m_satisfaction;
};

#endif

