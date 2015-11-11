#include "MapLoader.h"

MapLoader::MapLoader()
{
    #ifdef DEBUG
        std::cout << __func__ << " called" << std::endl;
    #endif
}

void MapLoader::loadMap(std::string nomFichier)
{
    #ifdef DEBUG
        std::cout << __func__ << " called" << std::endl;
    #endif

    EntityCreator *entityCreator = EntityCreator::getInstance();
    sf::Color matterColor = sf::Color::Black;
    sf::Color energyColor = sf::Color::White;
    sf::Color playerColor = sf::Color::Green;
    sf::Image img;
    if (img.loadFromFile(nomFichier))
    {
        for (int x=0 ; x < img.getSize().x ; x++)
        {
            for (int y=0 ; y < img.getSize().y ; y++)
            {
                if (img.getPixel(x, y) == matterColor)
                {
                    entityCreator->addEntity(x, -1*y, 0, "matter");
                }
                else if (img.getPixel(x, y) == energyColor)
                {
                    entityCreator->addEntity(x, -1*y, 0, "energy");
                }
                else if (img.getPixel(x, y) == playerColor)
                {
                    entityCreator->addEntity(x, -1*y, 0, "player");
                }
            }
        }

    }
    else
    {
        std::cout << "Couldn't load " << nomFichier << std::endl;
    }
}

MapLoader::~MapLoader()
{
    //dtor
}

