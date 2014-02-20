#include <SFML/Graphics.hpp>

#include <iostream>
#include "GameObject.h"
#include "Component.h"
#include "Renderer.h"
#include "ShaderRenderer.h"
using namespace std;
int main(int argc, char* args[])
{

    sf::RenderWindow window(sf::VideoMode(800, 600), "Plataform Component Base", sf::Style::Close);
    window.setFramerateLimit(60);

    //Code
    Renderer* render = new Renderer();
    ShaderRenderer* shaderRender = new ShaderRenderer();
    ShaderRenderer* shaderRenderWave = new ShaderRenderer();
    GameObject a;
    GameObject b;
    GameObject c;
    a.addComponent(render);
    a.window = &window;

    b.addComponent(shaderRender);
    b.window = &window;


    shaderRender->ampX = 4; shaderRender->ampY = 4;
    shaderRender->blurRatio = 0;

    c.addComponent(shaderRenderWave);
    shaderRenderWave->rect.setPosition(350, 150);
    c.window = &window;
    //Code

    while(window.isOpen()) {

        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                window.close();
            }
        }

        window.clear();
        //Code
        a.Render();
        b.Render();
        c.Render();
        //Code
        window.display();
    }

    return 0;
}
