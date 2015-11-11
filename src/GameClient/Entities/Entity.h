#ifndef ENTITY_H
#define ENTITY_H

#include <string>

class Entity
{
    public:
        Entity(int energy, int matter);
        virtual ~Entity();
        virtual void onCollide(Entity *Ent2) =0;
        std::string getType();
    protected:
        int m_energy;
        int m_matter;
        std::string m_type;
    private:
};

#endif // ENTITY_H
