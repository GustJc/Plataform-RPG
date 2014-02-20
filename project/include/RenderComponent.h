#ifndef RENDERCOMPONENT_H
#define RENDERCOMPONENT_H

#include <Component.h>


class RenderComponent : public Component
{
    public:
        RenderComponent();
        virtual ~RenderComponent();

        virtual void renderComponent() = 0;
    protected:
    private:
};

#endif // RENDERCOMPONENT_H
