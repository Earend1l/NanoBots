#ifndef RESOURCESMANAGER_H
#define RESOURCESMANAGER_H

#include <SFML/Graphics.hpp>
#include <unordered_map>

/**
    This class store shared resources like
    - Textures
**/
class ResourcesManager
{
    public:
        static ResourcesManager& getInstance();
        sf::Texture& getTexture(std::string entityName);
    protected:
    private:
        ResourcesManager();
        virtual ~ResourcesManager();
        std::unordered_map <std::string, sf::Texture> m_textures;

        static ResourcesManager instance;
};

#endif // RESOURCESMANAGER_H
