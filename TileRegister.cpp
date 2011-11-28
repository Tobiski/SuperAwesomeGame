#include "TileRegister.hpp"

#include <iostream>

std::map<int, TileClass>    TileRegister::_tiles;

void TileRegister::Register(int id, TileClass& tileClass){
    if(_tiles.count(id) > 0)
        std::cout << "WARNING: Overwriting Tile ID " << id << "!" << std::endl;

    _tiles[id] = tileClass;
}

TileClass& TileRegister::GetRegistered(int id){
    if(_tiles.count(id) < 1){
        std::cout << "WARNING: Call for unregistered Tile ID" << std::endl;
        TileClass temp;
        return temp;
    } else {
        return _tiles[id];
    }
}
