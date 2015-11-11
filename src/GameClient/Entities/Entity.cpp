#include "Entity.h"

Entity::Entity(int energy, int matter)
{
    m_energy = energy;
    m_matter = matter;
}

std::string Entity::getType()
{
    return m_type;
}

Entity::~Entity()
{
    //dtor
}
