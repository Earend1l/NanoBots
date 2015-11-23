#include "Renderer.h"

Renderer::Renderer(std::vector<std::shared_ptr<Entity> > &entities) : m_entities(entities), m_window(sf::VideoMode(1200, 800), "NanoBots")
{
    //ctorm_window(sf::VideoMode::getFullscreenModes()[0]
    m_window.setVerticalSyncEnabled(true);
}

Renderer::~Renderer()
{
    //dtor
}

sf::RenderWindow& Renderer::getRenderWindow()
{
    return m_window;
}

bool Renderer::renderOneFrame()
{
    m_window.clear(sf::Color::Black);

    for (auto ent : m_entities)
    {
        ent->draw(m_window);
    }

    m_window.display();

    return m_window.isOpen();
}
