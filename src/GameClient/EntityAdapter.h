#ifndef EntityAdapter_H
#define EntityAdapter_H

#include <iostream>
#include <string>

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <Box2D/Box2D.h>
#include <Entities/Entity.h>
#include <ResourcesManager.h>

#define PIXELS_PER_METER 50


/*********************************************************************
**  This class combine the Game's entity, SMFL'drawable and Box2d body
**********************************************************************/
class EntityAdapter : public sf::Drawable
{
    public:
        EntityAdapter(float positionX, float positionY, float angle, std::string entityName, b2Body& body);
        virtual ~EntityAdapter();
        void draw (sf::RenderTarget &target, sf::RenderStates states) const;

        void applyImpulse(float x, float y);
        //Update position using the b2body
            void updatePos();
    protected:
    private:
        bool m_drawBoundingBox;

        //Entity
            Entity *m_Entity;

        //SFML Adapter
            sf::Sprite m_sprite;
            sf::Texture &m_texture;

        //Box2D Adapter
        b2Body &m_body;
};

#endif // EntityAdapter_H
