#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include "ImageManager.hpp"

Game::Game()
{
    _window.Create(sf::VideoMode(800, 800, 32), "SuperAwesomeGame");

    MainLoop();
}

Game::~Game()
{

}

void Game::MainLoop()
{
    while(_window.IsOpened())
    {
        HandleInput();
        Update();
        Render();
    }
}

void Game::HandleInput()
{
    while(_window.GetEvent(_event))
    {
        if(_event.Type == sf::Event::Closed)
        {
            _window.Close();
        }
    }
}

void Game::Update()
{

}

void Game::Render()
{
    _window.Clear();

    _window.Display();
}
