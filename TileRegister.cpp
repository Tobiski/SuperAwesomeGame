#include "TileRegister.hpp"

#include <iostream>

<<<<<<< HEAD
#include "TileClass.hpp"

std::map<int, TileClass>    TileRegister::_tiles;
=======
std::map<char, TileClass>    TileRegister::_tiles;
>>>>>>> 15d9e98ba110c76abcd957f7415aa9d736fb3aea

void TileRegister::Register(char id, TileClass& tileClass){
    if(_tiles.count(id) > 0)
        std::cout << "WARNING: Overwriting Tile ID " << id << "!" << std::endl;

    _tiles[id] = tileClass;
}

<<<<<<< HEAD
TileClass& TileRegister::GetRegistered(int id){
    if(_tiles.count(id) < 1){ std::cout << "WARNING: Call for unregistered Tile ID " << id << std::endl; } //Warning in case the ID doesn't exist yet
=======
TileClass& TileRegister::GetRegistered(char id){
    if(_tiles.count(id) < 1){ std::cout << "WARNING: Call for unregistered Tile ID" << std::endl; } //Warning in case the ID doesn't exist yet
>>>>>>> 15d9e98ba110c76abcd957f7415aa9d736fb3aea

    return _tiles[id];
}
