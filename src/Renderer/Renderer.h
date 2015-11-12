#ifndef RENDERER_H
#define RENDERER_H

#include <iostream>
#include "EntityAdapter.h"
#include <list>

class Renderer
{
    public:
        Renderer(std::list<EntityAdapter> &entities);
        virtual ~Renderer();
        sf::RenderWindow &getRenderWindow();
        bool renderOneFrame();
    protected:
    private:
        sf::RenderWindow m_window;
        sf::View m_view;
        std::list<EntityAdapter> &m_entities;
};

#endif // RENDERER_H
