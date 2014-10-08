#ifndef DEF_VILLAGEOIS
#define DEF_VILLAGEOIS

#include <string>

class Villageois
{
    public:

	void update();
	int getId();

    private:

	int m_id
    int m_vie;
    int m_energie;
	int m_satisfaction;
};

#endif