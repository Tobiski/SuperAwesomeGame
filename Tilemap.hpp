#pragma once
#ifndef TILEMAP_HPP
#define TILEMAP_HPP

#include <SFML/Graphics.hpp>

#include "Vector2D.hpp"

//Tile
//Members:
//Tile(int tileId)      - constructor to initialize the id;
//more to follow...
struct Tile{
    Tile(int tileId){id = tileId;}
    int id;
};

//Map
//Members:
//
//
class Tilemap : private Vector2D<Tile>{
    public:
        Tilemap(int width, int height, int tileSize);
        ~Tilemap();

        void        GetWidth() const;
        void        GetHeight() const;
        void        Draw(sf::RenderWindow& _target) const;
        void        DebugRandomize();


    private:
        Tilemap();

        int         _tileSize;

        sf::Image*  _tilesheet;
};

#endif
