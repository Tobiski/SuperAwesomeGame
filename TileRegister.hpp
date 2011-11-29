#pragma once
#ifndef TILEREGISTER_HPP
#define TILEREGISTER_HPP

#include <SFML/Graphics.hpp>
#include <map>

struct TileClass;

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
