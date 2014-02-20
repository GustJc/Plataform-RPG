#ifndef SHADERRENDERER_H
#define SHADERRENDERER_H

#include "Renderer.h"

#include <SFML/Graphics.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/System/Clock.hpp>
class ShaderRenderer : public Renderer
{
    public:
        ShaderRenderer();
        virtual ~ShaderRenderer();

        virtual void onLoad();
        virtual void onRender();

        sf::Shader shader;
        long double ampX = 0;
        long double ampY = 0;
        long double blurRatio = 5;
        //sf::RenderTexture shaderTexture;
    protected:
        sf::Texture texture;
        sf::Time deltaTime;
        sf::Time deltaTimeWave;
        sf::Clock clock;
        sf::Clock clockWave;
    private:
};

#endif // SHADERRENDERER_H
