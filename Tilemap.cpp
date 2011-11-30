#include <fstream>

#include "Tilemap.hpp"

#include "ImageManager.hpp"
#include "TileRegister.hpp"

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
            operator()(j, i).id = rand()%3;
        }
    }
}

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


