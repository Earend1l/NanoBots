#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "PlayerController.h"
#include "EntityAdapter.h" //TODO delete this line

class EventManager
{
    public:
        EventManager(sf::RenderWindow *window, PlayerController *playerController, std::vector<EntityAdapter*>* entities);
        virtual ~EventManager();

        void processEvent(float elapsedTime);
    protected:
    private:
        sf::RenderWindow *m_window;
        PlayerController *m_playerController;
        std::vector<EntityAdapter*>* m_entities;

};

#endif // EVENTMANAGER_H
