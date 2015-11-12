#include "EntityAdapter.h"

EntityAdapter::EntityAdapter(float positionX, float positionY, float angle, std::string entityName, b2Body& body) : m_body(body)
{
    //TODO change default loader
    m_texture = new sf::Texture();
    ResourcesManager::getInstance()->addTexture(m_texture);
    m_drawBoundingBox=false;

    std::string path = "data/entities/"+entityName+"/texture";

    if (!m_texture->loadFromFile(path))
        std::cout << "Unable to open : \"data/tile.png\" " << std::endl;

    m_sprite.setTexture(*m_texture);
    m_texture->setSmooth(false);
    m_sprite.setOrigin(m_sprite.getTextureRect().width/2.0, m_sprite.getTextureRect().height/2.0);

    m_body.SetTransform(b2Vec2(positionX, positionY), angle);
}

EntityAdapter::~EntityAdapter()
{
    //dtor
    //Texture delete by resources manager
    std::cout << __func__ << " called" <<std::endl;
}

void EntityAdapter::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    //Drawing bounding boxes
    if (m_drawBoundingBox)
    {
        sf::RectangleShape shape;
        sf::FloatRect rect = m_sprite.getGlobalBounds();
        shape.setPosition(sf::Vector2f(rect.left, rect.top));
        shape.setSize(sf::Vector2f(rect.width, rect.height));
        shape.setFillColor(sf::Color::Transparent);
        shape.setOutlineColor(sf::Color::Red);
        shape.setOutlineThickness(2);

        target.draw(shape);
    }

    target.draw(m_sprite);
}

void EntityAdapter::updatePos()
{
    b2Vec2 pos = m_body.GetPosition();
    m_sprite.setPosition(pos.x * PIXELS_PER_METER, -1*pos.y * PIXELS_PER_METER);

    float angle = m_body.GetAngle();
    m_sprite.setRotation(-1*angle*180/3.1415926535);
}

void EntityAdapter::applyImpulse(float x, float y)
{
    b2Vec2 vec;
    vec.x =x*100;
    vec.y = y*100.0;
    m_body.ApplyLinearImpulse(vec, m_body.GetWorldCenter(), true);
}
