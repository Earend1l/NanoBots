#include "ResourcesManager.h"

ResourcesManager ResourcesManager::instance;

ResourcesManager::ResourcesManager()
{
    //ctor
}

ResourcesManager::~ResourcesManager()
{
}

ResourcesManager& ResourcesManager::getInstance()
{
    return instance;
}

sf::Texture& ResourcesManager::getTexture(std::string entityName)
{
    auto it = m_textures.find(entityName);

    if (it == m_textures.end())
    {
        std::string path = "data/entities/"+entityName+"/texture";
        m_textures.insert(std::make_pair<std::string,sf::Texture>("eggs",sf::Texture()));
        m_textures[entityName].loadFromFile(path);
    }

    return m_textures[entityName];
}
