#include "GameObject.h"
#include <iostream>
using namespace std;

GameObject::GameObject()
{
    //ctor
}

GameObject::~GameObject()
{
    for(Component* element : mComponentList)
    {
        delete element;
    }
    mComponentList.clear();
}

void GameObject::onEnable()
{

}

void GameObject::onDisable()
{

}

void GameObject::Update()
{

}

void GameObject::Render()
{
    for(Component* c : mComponentList) {
        if(c->getTag("Render")) {
            //cout << "Objeto render chamado: " << c->getName() << endl;
            c->onRender();
        }
    }
}

void GameObject::addComponent(Component* component)
{
    /* TODO (Gust#1#): Add validation of dependencies and restrictions */
    component->gameObject = this;
    mComponentList.push_back(component);
    component->onLoad();
}


template<class T>
T* GameObject::getComponent()
{
    for(Component* element : mComponentList )
    {
        T* component = dynamic_cast<T*>(element);
        if(component != nullptr) return component;
    }
    return nullptr;
}

void GameObject::setActive(bool state)
{

}
