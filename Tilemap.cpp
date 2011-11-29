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


