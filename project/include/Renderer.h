#ifndef RENDERER_H
#define RENDERER_H

#include "Component.h"

#include <SFML/Graphics/RectangleShape.hpp>

class Renderer : public Component
{
    public:
        Renderer();
        virtual ~Renderer();

        virtual void onLoad();
        virtual void onRender();

        sf::RectangleShape rect;
    protected:
    private:
};

#endif // RENDERER_H
