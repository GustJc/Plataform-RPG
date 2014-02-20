#include "Component.h"

Component::Component()
{
    //ctor
}

Component::~Component()
{
    //dtor
}

std::string Component::getName()
{
    return m_componentName;
}

std::string Component::getTagName()
{
    return m_tagName;
}


void Component::onEnable()
{

}

void Component::onDisable()
{

}

void Component::onLoad()
{

}


void Component::onUpdate()
{

}

void Component::onRender()
{

}



bool Component::getTag(std::string tagName)
{
    return m_tagName.compare(tagName) == 0 ? true : false;
}
