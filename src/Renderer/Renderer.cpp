#include "Renderer.h"

Renderer::Renderer(std::vector<std::shared_ptr<EntityAdapter> > &entities) : m_entities(entities), m_window(sf::VideoMode(1024, 768), "NanoBots")
{
    //ctor
    m_window.setVerticalSyncEnabled(true);

    m_view.setCenter(0, 0);
    m_view.setSize(m_window.getSize().x*4, m_window.getSize().y*4);
    m_view.move(2000, 1000);
    m_window.setView(m_view);
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
