#ifndef STL_GrLibCtx
#define STL_GrLibCtx

#include <SFML/Graphics.hpp>

class GraphicsCtx
{
public:
    sf::RenderWindow window;
    sf::Event event;
    bool checkEvent;

    GraphicsCtx ();
};

#endif /* STL_GrLibCtx */