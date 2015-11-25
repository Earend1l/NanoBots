#include "EventManager.h"

EventManager::EventManager(sf::RenderWindow &window, PlayerController &playerController) :
                            m_window(window), m_playerController(playerController)
{
    m_view = m_window.getDefaultView();
    m_view.zoom(2.5);
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
                switch (event.key.code)
                {
                    case sf::Keyboard::Escape:
                        m_window.close();
                        break;

                    default:
                        break;
                }
                break;

            case sf::Event::MouseWheelMoved:
                m_view.zoom(1 - 0.1*event.mouseWheel.delta);
                break;

            case sf::Event::MouseButtonPressed:
                switch (event.mouseButton.button)
                {
                    case sf::Mouse::Right:
                        m_playerController.primaryAction(getGameMousePosition(event.mouseButton.x, event.mouseButton.y));
                        break;

                    default:
                        break;
                }
                break;

            // we don't process other types of events
            default:
                break;
        }
    }

    m_playerController.move((sf::Keyboard::isKeyPressed(sf::Keyboard::D)-sf::Keyboard::isKeyPressed(sf::Keyboard::Q))*elapsedTime,
                            ((sf::Keyboard::isKeyPressed(sf::Keyboard::Z)-sf::Keyboard::isKeyPressed(sf::Keyboard::S))*elapsedTime));

    updateView(elapsedTime);
}

void EventManager::updateView(float elapsedTime)
{
    float dx = m_playerController.getPosition().x * PIXELS_PER_METER - m_view.getCenter().x;
    float dy = -1.0* m_playerController.getPosition().y * PIXELS_PER_METER - m_view.getCenter().y;

    if (abs(dx)>m_view.getSize().x/10)
    {
        m_view.move(3000.f * dx * elapsedTime / m_view.getSize().x, 0);
    }
    if (abs(dy)>m_view.getSize().y/10)
    {
        m_view.move(0, 3000.f * dy *elapsedTime / m_view.getSize().y);
    }


    m_window.setView(m_view);
}

sf::Vector2f EventManager::getGameMousePosition(float x, float y)
{
    return sf::Vector2f((x*(m_view.getSize().x / m_window.getSize().x)+m_view.getCenter().x-m_view.getSize().x/2)/PIXELS_PER_METER,
                        -1*(y*(m_view.getSize().y / m_window.getSize().y)+m_view.getCenter().y-m_view.getSize().y/2)/PIXELS_PER_METER);
}
