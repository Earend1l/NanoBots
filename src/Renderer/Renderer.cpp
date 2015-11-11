#include "Renderer.h"

Renderer::Renderer(std::vector<EntityAdapter*> *entities)
{
    //ctor
    m_entities = entities;
    m_window = new sf::RenderWindow(sf::VideoMode(1024, 768), "NanoBots");
    m_window->setVerticalSyncEnabled(true);

    m_view.setCenter(0, 0);
    m_view.setSize(m_window->getSize().x*4, m_window->getSize().y*4);
    m_view.move(2000, 1000);
    m_window->setView(m_view);
}

Renderer::~Renderer()
{
    //dtor
    delete m_window;
}

sf::RenderWindow* Renderer::getRenderWindow()
{
    return m_window;
}

bool Renderer::renderOneFrame()
{
    if (!m_entities)
        std::cout << "Renderer : unable to get entities' list" << std::endl;

    m_window->clear(sf::Color::White);
    for (unsigned int i=0 ; i<m_entities->size() ; i++)
    {
        (*m_entities)[i]->updatePos();
        m_window->draw(*((*m_entities)[i]));
    }
    m_window->display();

    return m_window->isOpen();
}
