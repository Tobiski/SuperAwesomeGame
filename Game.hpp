#pragma once
#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>

class Tilemap;

class Game
{
    private:
        sf::RenderWindow    _window;
        sf::Event           _event;

        sf::VideoMode       _windowVideoMode;
        std::string         _windowTitle;
        bool                _windowFullscreen;

        Tilemap*            _tilemap;

    public:
        Game();
        ~Game();
        void                MainLoop();
        void                HandleInput();
        void                Update();
        void                Render();
};

#endif
