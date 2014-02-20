#include "ShaderRenderer.h"
#include <iostream>
using namespace std;
#include "GameObject.h"
ShaderRenderer::ShaderRenderer()
{
    //ctor
}

ShaderRenderer::~ShaderRenderer()
{
    //dtor
}

void ShaderRenderer::onLoad()
{
    Renderer::onLoad();
    if (!sf::Shader::isAvailable())
    {
        cout << "Shaders not supported" << endl;
    }
    if (!shader.loadFromFile("data/shaders/wave.vert", "data/shaders/blur.frag"))
    {
        cout << "Can't load shader" << endl;
    }


    rect.setPosition(150,150);

    texture.loadFromFile("data/images/sfml.png");
    //shaderTexture.create(800,600);
    rect.setTexture(&texture);


    deltaTime = clock.getElapsedTime();

}
#include <math.h>
#define M_PI 3.14159265358979323846
void ShaderRenderer::onRender()
{
    static float degrees = 0;
    deltaTime = clock.getElapsedTime();
    clock.restart();
    deltaTimeWave = clockWave.getElapsedTime();

    degrees += deltaTime.asSeconds()*100;
    degrees = degrees > 360? degrees - 360 : degrees;

    shader.setParameter("wave_phase", deltaTimeWave.asSeconds());
    shader.setParameter("wave_amplitude", ampX*10, ampY*10);
    shader.setParameter("blur_radius", (blurRatio + blurRatio*cos(degrees*M_PI/180.f)) * 0.008f);

    //shaderTexture.clear(sf::Color::Transparent);
    //shaderTexture.draw(rect);
    //shaderTexture.display();
    gameObject->window->draw(rect, &shader);
    //gameObject->window->draw(sf::Sprite(shaderTexture.getTexture()), &shader);
}
