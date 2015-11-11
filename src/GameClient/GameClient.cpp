#include "GameClient.h"

GameClient::GameClient()
{
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
    std::cout << "GameClient : destructor called" << std::endl;
    delete m_physicEngine;
    delete m_renderer;
    delete m_playerController;
    delete m_eventManager;
}

void GameClient::start()
{
    /*EntityCreator* entityCreator = EntityCreator::getInstance();
    entityCreator->addEntity(9, 5, 0, "test");
    entityCreator->addEntity(0, 5, 0, "player");
    entityCreator->addEntity(1, 9, 0, "player");
    entityCreator->addEntity(-1, 12, 0, "player");
    entityCreator->addEntity(0, -3, 0, "test");
    entityCreator->addEntity(-2, -3, 0, "test");
    entityCreator->addEntity(2, -3, 0, "test");
    entityCreator->addEntity(4, -4, 0, "test");
    entityCreator->addEntity(6, -4, 0, "test");*/

    MapLoader* mapLoader = new MapLoader();
    mapLoader->loadMap("data/map.bmp");
    delete mapLoader;

    sf::Clock clock;

    while (running)
    {
        running = m_renderer->renderOneFrame();
        m_eventManager->processEvent(clock.getElapsedTime());
        m_physicEngine->update(clock.restart().asSeconds());
    }
}
