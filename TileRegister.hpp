#pragma once
#ifndef TILEREGISTER_HPP
#define TILEREGISTER_HPP

#include <SFML/Graphics.hpp>
#include <map>

//The TileClass comes with TileRegister, it's the class that will be registered under a certain ID
//First you declare a TileClass in your code, fill it with information, and then register it using TileRegister.Register(int, TileClass);
//Later, you can retrieve the TileClass by it's id using TileRegister.GetRegistered()
//Members:
//textureCoordinates            - basically the subrect that holds the information about where the tile is on the tilesheet
//more to follow...
struct TileClass{
    sf::Rect<int> textureCoordinates;
};

//TileRegister
//Members:
//Register(int id, TileClass& tileClass)            - Register a predefined TileClass by ID, so it can later be retrieved by ID.
//GetRegistered(int id)                             - Retrieve a registered TileClass by ID
class TileRegister
{
    public:
        static void                         Register(int id, TileClass& tileClass);
        static TileClass&                   GetRegistered(int id);

    private:
        static std::map<int, TileClass>    _tiles;
};

#endif
