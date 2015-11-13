#include "EntityAdapter.h"

EntityAdapter::EntityAdapter(float positionX, float positionY, float angle, std::string entityName, b2Body& body) :
                            m_body(body),
                            m_texture(ResourcesManager::getInstance().getTexture(entityName)),
                            m_drawBoundingBox(false)
{
    //Setting up the sprite
    m_sprite.setTexture(m_texture);
    m_sprite.setOrigin(m_sprite.getTextureRect().width/2.0, m_sprite.getTextureRect().height/2.0);

    //Moving the physical body to the right location
    m_body.SetTransform(b2Vec2(positionX, positionY), angle);
}

EntityAdapter::~EntityAdapter()
{
    //dtor
    std::cout << __func__ << " called" <<std::endl;
}

void EntityAdapter::draw(sf::RenderTarget &target)
{
    updatePos();

    //Should we draw the bounding box ?
    if (m_drawBoundingBox)
    {
        //Creating the shape
        sf::RectangleShape shape;
        sf::FloatRect rect = m_sprite.getGlobalBounds();
        shape.setPosition(sf::Vector2f(rect.left, rect.top));
        shape.setSize(sf::Vector2f(rect.width, rect.height));
        shape.setFillColor(sf::Color::Transparent);
        shape.setOutlineColor(sf::Color::Red);
        shape.setOutlineThickness(2);

        //Drawing bounding box
        target.draw(shape);
    }

    target.draw(m_sprite);
}

void EntityAdapter::updatePos()
{
    //Getting the position updated by the physic engine
    b2Vec2 pos = m_body.GetPosition();

    //Move the sprite to the new position
    m_sprite.setPosition(pos.x * PIXELS_PER_METER, -1*pos.y * PIXELS_PER_METER);

    //Getting the angle updated by the physic engine
    float angle = m_body.GetAngle();

    //Rotate the sprite to the new angle
    m_sprite.setRotation(-1*angle*180/3.1415926535);
}

void EntityAdapter::applyImpulse(float x, float y)
{
    //Converting into a b2Vec2
    b2Vec2 vec{x, y};
    m_body.ApplyLinearImpulse(vec, m_body.GetWorldCenter(), true);
}
