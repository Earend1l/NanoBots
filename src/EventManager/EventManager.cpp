#include "EventManager.h"

EventManager::EventManager(sf::RenderWindow &window, PlayerController &playerController) :
                            m_window(window), m_playerController(playerController)
{

}

EventManager::~EventManager()
{
    //dtor
}

void EventManager::processEvent(float elapsedTime)
{
    sf::Event event;

    // while there are pending events...
    while (m_window.pollEvent(event))
    {
        // check the type of the event...
        switch (event.type)
        {
            // window closed
            case sf::Event::Closed:
                m_window.close();
                break;

            // key pressed
            case sf::Event::KeyPressed:
                break;

            // we don't process other types of events
            default:
                break;
        }
    }

    m_playerController.move((sf::Keyboard::isKeyPressed(sf::Keyboard::D)-sf::Keyboard::isKeyPressed(sf::Keyboard::Q))*elapsedTime,
                            ((sf::Keyboard::isKeyPressed(sf::Keyboard::Z)-sf::Keyboard::isKeyPressed(sf::Keyboard::S))*elapsedTime));
}
