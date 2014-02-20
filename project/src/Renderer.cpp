#include "Renderer.h"
#include <SFML/Graphics.hpp>
#include "GameObject.h"
Renderer::Renderer()
{
    m_componentName = "RendererComponent";
    m_tagName = "Render";
}

Renderer::~Renderer()
{
    //dtor
}


void Renderer::onLoad()
{
    rect.setSize(sf::Vector2f(50.f, 50.f));
    rect.setPosition(50,50);
}

void Renderer::onRender()
{
    gameObject->window->draw(rect);
}
