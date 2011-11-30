#include "Game.hpp"

#include <cstdlib>
#include <time.h>

#include "ImageManager.hpp"
#include "Miscellaneous.hpp"
#include "TileRegister.hpp"
#include "TileClass.hpp"
#include "Tilemap.hpp"
#include "Definitions.hpp"

Game::Game()
{
    srand(time(NULL));

    _windowVideoMode.Width          = 800;
    _windowVideoMode.Height         = 800;
    _windowVideoMode.BitsPerPixel   = 32;
    _windowTitle                    = "SuperAwesomeGame";
    _windowFullscreen               = false;

<<<<<<< HEAD
    //Little Demo on how the Tile Register Works
    //Registering the tile
    TileRegister::Register(0,  TileClass::New(TextureCoordinates(0, 0, 32, 32)));
    TileRegister::Register(1,  TileClass::New(TextureCoordinates(32, 0, 64, 32)));
    TileRegister::Register(2,  TileClass::New(TextureCoordinates(64, 0, 96, 32)));
    TileRegister::Register(3,  TileClass::New(TextureCoordinates(96, 0, 128, 32)));
    TileRegister::Register(4,  TileClass::New(TextureCoordinates(128, 0, 160, 32)));
    TileRegister::Register(5,  TileClass::New(TextureCoordinates(160, 0, 192, 32)));
    TileRegister::Register(6,  TileClass::New(TextureCoordinates(192, 0, 224, 32)));
    TileRegister::Register(7,  TileClass::New(TextureCoordinates(224, 0, 256, 32)));
    TileRegister::Register(8,  TileClass::New(TextureCoordinates(0, 32, 32, 64)));
    TileRegister::Register(9,  TileClass::New(TextureCoordinates(32, 32, 64, 64)));
    TileRegister::Register(10, TileClass::New(TextureCoordinates(64, 32, 96, 64)));
    TileRegister::Register(11, TileClass::New(TextureCoordinates(96, 32, 128, 64)));
    TileRegister::Register(12, TileClass::New(TextureCoordinates(128, 32, 160, 64)));
    TileRegister::Register(13, TileClass::New(TextureCoordinates(160, 32, 192, 64)));
    TileRegister::Register(14, TileClass::New(TextureCoordinates(192, 32, 224, 64)));
    TileRegister::Register(15, TileClass::New(TextureCoordinates(224, 32, 256, 64)));

    _tilemap                        = new Tilemap(25, 25, 32);
    _tilemap                        ->LoadMap("maps/map1.map"); //Debug code once again, delete as soon as we can load levels...
=======
    _tilemap                        = new Tilemap(25, 25, 32);
    _tilemap                        ->LoadMap("1.txt");

    //Little Demo on how the Tile Register Works
    //Registering the tile
    TileClass temp;
    temp.textureCoordinates = sf::Rect<int>(0, 0, 32, 32);
    TileRegister::Register('0', temp);
    temp.textureCoordinates = sf::Rect<int>(32, 0, 64, 32);
    TileRegister::Register('1', temp);
    temp.textureCoordinates = sf::Rect<int>(64, 0, 96, 32);
    TileRegister::Register('A', temp);
>>>>>>> 15d9e98ba110c76abcd957f7415aa9d736fb3aea

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
