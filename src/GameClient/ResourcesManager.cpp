#include "ResourcesManager.h"

ResourcesManager* ResourcesManager::instance = new ResourcesManager();

ResourcesManager::ResourcesManager()
{
    //ctor
}

ResourcesManager::~ResourcesManager()
{
    //dtor
    for (unsigned int i=0 ; i<m_textures.size() ; i++)
    {
        delete m_textures[i];
    }
}

ResourcesManager* ResourcesManager::getInstance()
{
    return instance;
}

void ResourcesManager::addTexture (sf::Texture* texture)
{
    m_textures.push_back(texture);
}
