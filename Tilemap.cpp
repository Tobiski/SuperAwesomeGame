#include <fstream>

#include "Tilemap.hpp"

#include "ImageManager.hpp"
#include "TileRegister.hpp"
#include "TileClass.hpp"

Tilemap::Tilemap(int width, int height, int tileSize) :
Vector2D<Tile>(width, height, Tile(0))
{
    _tilesheet = &ImageManager::GetImage("data/images/tilesheet.png");
    _tileSize = tileSize;
}

Tilemap::~Tilemap(){
}

void Tilemap::Draw(sf::RenderWindow& target) const{
    static sf::Sprite tileSprite;
    tileSprite.SetImage(*_tilesheet);
    for(int i = 0; i < _height; i++){
        for (int j = 0; j < _width; j++){
            TileClass& currentTile = TileRegister::GetRegistered(_content[j + (i * _width)].id);
            tileSprite.SetSubRect(currentTile.textureCoordinates);
            tileSprite.SetPosition(j * _tileSize, i * _tileSize);
            target.Draw(tileSprite);
        }
    }
}

void Tilemap::DebugRandomize(){
    for(int i = 0; i < _height; i++){
        for (int j = 0; j < _width; j++){
            operator()(j, i).id = rand()%16;
        }
    }
}

<<<<<<< HEAD
bool Tilemap::LoadMap(std::string levelName){
    _in.open(levelName.c_str(), std::ios::binary);
    if(_in.is_open()){
        int currentTile;
        for(int i = 0; i < _height && _in.peek() >= 0; i++){
            for(int j = 0; j < _width && _in.peek() >= 0; j++){
                currentTile = _in.peek();
                std::cout << _in.peek() << std::endl;
                _in.seekg(_in.tellg() + 1);
                operator()(j, i).id = currentTile;
            }
        }
        _in.close();
    } else {
        std::cout << "WARNING: Failed to load level: '" << levelName << "'" << std::endl;
        return false;
    }
}
=======
void Tilemap::LoadMap(std::string level)
{
    // modify the currentLevel to hold whole path to the level file
    char currentLevel[18] = "data/levels/";
    int j = 12;
    char* p;
    p = &level[0];
    for(int i=0; i < level.size(); i++)
    {
        currentLevel[j] = p[i];
        j++;
    }

    // load level from pointed file
    std::ifstream levelfile;
    levelfile.open(currentLevel);
    char c;

    for(int i = 0; i < _height; i++)
    {
        for(int j = 0; j < _width; j++)
        {
            levelfile >> c;
            operator()(j, i).id = c;
        }
    }
}


>>>>>>> 15d9e98ba110c76abcd957f7415aa9d736fb3aea
