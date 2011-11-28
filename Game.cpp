#include "Game.hpp"

#include "ImageManager.hpp"
#include "Miscellaneous.hpp"
#include "ImageManager.hpp"

Game::Game()
{
    _windowVideoMode.Width          = 800;
    _windowVideoMode.Height         = 800;
    _windowVideoMode.BitsPerPixel   = 32;
    _windowTitle                    = "SuperAwesomeGame";
    _windowFullscreen               = false;

    Framework::InitWindow(&_window, _windowVideoMode, _windowTitle, false);

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
        //Test code, delete if not needed anymore anymore
        sf::Sprite mySprite;
        mySprite.SetImage(ImageManager::GetImage("test.png"));
        mySprite.SetPosition(0.f, 0.f);
        _window.Draw(mySprite);
    _window.Display();
}
