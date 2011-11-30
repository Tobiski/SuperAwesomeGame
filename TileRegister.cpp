#include "TileRegister.hpp"

#include <iostream>

std::map<char, TileClass>    TileRegister::_tiles;

void TileRegister::Register(char id, TileClass& tileClass){
    if(_tiles.count(id) > 0)
        std::cout << "WARNING: Overwriting Tile ID " << id << "!" << std::endl;

    _tiles[id] = tileClass;
}

TileClass& TileRegister::GetRegistered(char id){
    if(_tiles.count(id) < 1){ std::cout << "WARNING: Call for unregistered Tile ID" << std::endl; } //Warning in case the ID doesn't exist yet

    return _tiles[id];
}
