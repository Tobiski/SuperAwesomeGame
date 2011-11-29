#pragma once
#ifndef TILECLASS_HPP
#define TILECLASS_HPP

#include "Definitions.hpp"

struct TileClass{
    TextureCoordinates textureCoordinates;

    static TileClass& New(TextureCoordinates texCoords);
};

#endif
