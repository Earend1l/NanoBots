#ifndef RENDERER_H
#define RENDERER_H

#include <iostream>
#include "EntityAdapter.h"
#include <vector>

class Renderer
{
    public:
        Renderer(std::vector<EntityAdapter> *entities);
        virtual ~Renderer();

        void renderOneFrame();
    protected:
    private:
        sf::RenderWindow* m_window;
        sf::View m_view;
        std::vector<EntityAdapter> *m_entities;
};

#endif // RENDERER_H
