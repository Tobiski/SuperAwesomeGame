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
//Draw(sf::RenderWindow& target)        - draws the tilemap to the screen, pretty much all ther is to say
//DebugRandomize()                      - debug function, fills the map with random tiles
//LoadMap(std::string level)            - loads a map from a spesified file
class Tilemap : public Vector2D<Tile>{
    public:
        Tilemap(int width, int height, int tileSize);
        ~Tilemap();

        void        Draw(sf::RenderWindow& target) const;
        void        DebugRandomize();
        void        LoadMap(std::string level);


    private:
        Tilemap();

        int         _tileSize;

        sf::Image*  _tilesheet;
};

#endif
