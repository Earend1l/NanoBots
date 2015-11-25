#ifndef Entity_H
#define Entity_H

#include <iostream>
#include <string>

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <Box2D/Box2D.h>
#include <ResourcesManager.h>

#define PIXELS_PER_METER 50


/*********************************************************************
**  This class combine the Game's entity, SMFL'drawable and Box2d body
**********************************************************************/
class Entity
{
    public:
        Entity(float positionX, float positionY, float angle, std::string entityName, b2Body* body);
        virtual ~Entity();
        void draw (sf::RenderTarget &target);
        sf::Vector2f getPosition();


        void applyImpulse(float x, float y);
        void onCollide(Entity& ent);
        void addActionOnCollide(std::string entityName, int actionID);
        void setColor(sf::Color color);
        float getAngle();
        sf::Vector2f getVelocity();

        std::string getName();

        //Update position using the b2body
            void updatePos();

    protected:
    private:
        bool m_drawBoundingBox;

        //Entity
            std::string m_name;
            std::unordered_map<std::string, int> m_actionsOnCollide;

        //SFML Adapter
            sf::Sprite m_sprite;
            sf::Texture &m_texture;

        //Box2D Adapter
        b2Body *m_body;
};

#endif // Entity_H
