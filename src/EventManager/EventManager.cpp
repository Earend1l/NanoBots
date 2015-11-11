#include "EventManager.h"

EventManager::EventManager(sf::RenderWindow *window, PlayerController *playerController, std::vector<EntityAdapter*>* entities)
{
    m_window = window;
    m_playerController = playerController;
    m_entities = entities; //TODO delete this shit
}

EventManager::~EventManager()
{
    //dtor
}

void EventManager::processEvent(sf::Time elapsedTime)
{
    sf::Event event;

    // while there are pending events...
    while (m_window->pollEvent(event))
    {
        // check the type of the event...
        switch (event.type)
        {
            // window closed
            case sf::Event::Closed:
                m_window->close();
                break;

            // key pressed
            case sf::Event::KeyPressed:
                break;

            // we don't process other types of events
            default:
                break;
        }
    }

    (*m_entities)[0]->applyImpulse(sf::Keyboard::isKeyPressed(sf::Keyboard::D)*elapsedTime.asSeconds()
                                      -sf::Keyboard::isKeyPressed(sf::Keyboard::Q)*elapsedTime.asSeconds(),
                                  (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)*elapsedTime.asSeconds()
                                      -sf::Keyboard::isKeyPressed(sf::Keyboard::S)*elapsedTime.asSeconds()));
}
