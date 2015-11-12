#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "PlayerController.h"
#include <list>
#include "EntityAdapter.h" //TODO delete this line

class EventManager
{
    public:
        EventManager(sf::RenderWindow &window, PlayerController &playerController, std::list<EntityAdapter>& entities);
        virtual ~EventManager();

        void processEvent(float elapsedTime);
    protected:
    private:
        sf::RenderWindow &m_window;
        PlayerController &m_playerController;
        std::list<EntityAdapter>& m_entities;

};

#endif // EVENTMANAGER_H
