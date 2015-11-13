#ifndef MAPLOADER_H
#define MAPLOADER_H

#include <SFML/Graphics.hpp>
#include "EntityManager.h"

class MapLoader
{
    public:
        MapLoader(EntityManager &entityManager);
        void loadMap(std::string nomFichier);
        virtual ~MapLoader();
    protected:
    private:
        EntityManager &m_entityManager;
};

#endif // MAPLOADER_H
