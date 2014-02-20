#ifndef POSITION_H
#define POSITION_H

#include <SFML/System/Vector2.hpp>
#include "Component.h"
class Position : public Component
{
    public:
        Position();
        virtual ~Position();
    protected:
        float mRotationAngle;
        sf::Vector2f mPosition;
        sf::Vector2f mDisplacementPosition; //Deslocation to change anchor of GameObject
    private:
};

#endif // POSITION_H
