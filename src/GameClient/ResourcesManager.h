#ifndef RESOURCESMANAGER_H
#define RESOURCESMANAGER_H

#include <SFML/Graphics.hpp>
#include <vector>

/**
    This class store shared resources like
    - Textures
**/
class ResourcesManager
{
    public:
        void addTexture (sf::Texture* texture);
        static ResourcesManager* getInstance();
    protected:
    private:
        ResourcesManager();
        virtual ~ResourcesManager();
        std::vector<sf::Texture*> m_textures;

        static ResourcesManager *instance;
};

#endif // RESOURCESMANAGER_H
