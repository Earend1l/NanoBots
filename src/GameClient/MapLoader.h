#ifndef MAPLOADER_H
#define MAPLOADER_H

#include <SFML/Graphics.hpp>
#include "EntityCreator.h"

class MapLoader
{
    public:
        MapLoader(EntityCreator &entityCreator);
        void loadMap(std::string nomFichier);
        virtual ~MapLoader();
    protected:
    private:
        EntityCreator &m_entityCreator;
};

#endif // MAPLOADER_H
