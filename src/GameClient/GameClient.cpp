#include "GameClient.h"

GameClient::GameClient()
{
    #ifdef DEBUG
        std::cout << __func__ << " called" << std::endl;
    #endif

    m_physicEngine = new PhysicEngine();
    m_renderer = new Renderer(&m_entities);
    m_playerController = new PlayerController();
    EntityCreator::getInstance()->init(&m_entities, m_physicEngine);

    m_entities.reserve(3000);
    EntityCreator::getInstance()->addEntity(1, 1, 0,  "player");
    m_eventManager = new EventManager(m_renderer->getRenderWindow(), m_playerController, &m_entities);

}

GameClient::~GameClient()
{
    std::cout << __func__ << " called" <<std::endl;
    delete m_physicEngine;
    delete m_renderer;
    delete m_playerController;
    delete m_eventManager;

    for (int i=0 ; i<m_entities.size() ; i++)
    {
        delete (m_entities[i]);
    }
}

void GameClient::start()
{
    MapLoader mapLoader;
    mapLoader.loadMap("data/map.bmp");

    sf::Clock clock;
    clock.restart();
    float time = 0;
    while (running)
    {
        m_physicEngine->update(time);
        running = m_renderer->renderOneFrame();
        m_eventManager->processEvent(time);
        time = clock.restart().asSeconds();
    }
}
