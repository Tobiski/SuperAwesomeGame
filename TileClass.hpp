#pragma once
#ifndef TILECLASS_HPP
#define TILECLASS_HPP

#include "Definitions.hpp"

//TileClass (seperated, was in TileRegister before
//The TileClass comes with TileRegister, it's the class that will be registered under a certain ID
//First you declare a TileClass in your code, fill it with information, and then register it using TileRegister.Register(int, TileClass);
//Later, you can retrieve the TileClass by it's id using TileRegister.GetRegistered()
//Members:
//textureCoordinates                                        - basically the subrect that holds the information about where the tile is on the tilesheet
//static TileClass& New(TextureCoordinates texCoords)       - static function to define a new TileClass. Attention, always returns a reference to the same object, it just modifies it.
//                                                            better cache the TileClass before requesting a new one
//more to follow...

struct TileClass{
    TextureCoordinates textureCoordinates;

    static TileClass& New(TextureCoordinates texCoords);
};

#endif
