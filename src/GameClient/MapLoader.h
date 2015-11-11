#ifndef MAPLOADER_H
#define MAPLOADER_H

#include <SFML/Graphics.hpp>
#include "EntityCreator.h"

class MapLoader
{
    public:
        MapLoader();
        void loadMap(std::string nomFichier);
        virtual ~MapLoader();
    protected:
    private:
};

#endif // MAPLOADER_H
