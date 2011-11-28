#include "Game.hpp"

#include "ImageManager.hpp"
#include "Miscellaneous.hpp"
#include "TileRegister.hpp"

Game::Game()
{
    _windowVideoMode.Width          = 800;
    _windowVideoMode.Height         = 800;
    _windowVideoMode.BitsPerPixel   = 32;
    _windowTitle                    = "SuperAwesomeGame";
    _windowFullscreen               = false;

    //Little Demo on how the Tile Register Works
    //Registering the tile
    TileClass temp;
    temp.textureCoordinates = sf::Rect<int>(32, 32, 64, 64);
    TileRegister::Register(1, temp); //register the TileClass we just made

    //Retrieving the registered TileClass
    TileClass& temp2 = TileRegister::GetRegistered(1);
    std::cout << "Texture Coords of Tile id 1:" << std::endl;
    std::cout << "Left: " << temp2.textureCoordinates.Left << std::endl;
    std::cout << "Top: " << temp2.textureCoordinates.Top << std::endl;
    std::cout << "Right: " << temp2.textureCoordinates.Right << std::endl;
    std::cout << "Bottom: " << temp2.textureCoordinates.Bottom << std::endl;

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
