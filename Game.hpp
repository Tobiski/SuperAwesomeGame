#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include "ImageManager.hpp"

class Game
{
    private:
        sf::RenderWindow _window;
        sf::Event _event;

        ImageManager _imageManager;
    public:
        Game();
        ~Game();
        void MainLoop();
        void HandleInput();
        void Update();
        void Render();
};

#endif
