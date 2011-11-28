#include "Game.hpp"

#include <cstdlib>
#include <time.h>

#include "ImageManager.hpp"
#include "Miscellaneous.hpp"
#include "TileRegister.hpp"
#include "Tilemap.hpp"

Game::Game()
{
    srand(time(NULL));

    _windowVideoMode.Width          = 800;
    _windowVideoMode.Height         = 800;
    _windowVideoMode.BitsPerPixel   = 32;
    _windowTitle                    = "SuperAwesomeGame";
    _windowFullscreen               = false;

    _tilemap                        = new Tilemap(25, 25, 32);
    _tilemap                        ->DebugRandomize(); //Debug code once again, delete as soon as we can load levels...

    //Little Demo on how the Tile Register Works
    //Registering the tile
    TileClass temp;
    temp.textureCoordinates = sf::Rect<int>(0, 0, 32, 32);
    TileRegister::Register(0, temp);
    temp.textureCoordinates = sf::Rect<int>(32, 0, 64, 32);
    TileRegister::Register(1, temp);
    temp.textureCoordinates = sf::Rect<int>(64, 0, 96, 32);
    TileRegister::Register(2, temp);

    Framework::InitWindow(&_window, _windowVideoMode, _windowTitle, _windowFullscreen);

    MainLoop();
}

Game::~Game()
{
    delete _tilemap;
    _tilemap = NULL;
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

        else if(_event.Type == sf::Event::KeyPressed){
            if(_event.Key.Code == sf::Key::Escape){
                _window.Close();
            }
        }
    }
}

void Game::Update()
{

}

void Game::Render()
{
    _window.Clear();

    _tilemap->Draw(_window);

    _window.Display();
}
