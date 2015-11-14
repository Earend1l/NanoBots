#ifndef RENDERER_H
#define RENDERER_H

#include <iostream>
#include "Entity.h"
#include <vector>

class Renderer
{
    public:
        Renderer(std::vector<std::shared_ptr<Entity> > &entities);
        virtual ~Renderer();
        sf::RenderWindow &getRenderWindow();
        bool renderOneFrame();
    protected:
    private:
        sf::RenderWindow m_window;
        std::vector<std::shared_ptr<Entity> > &m_entities;
};

#endif // RENDERER_H
