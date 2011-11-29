#include "TileClass.hpp"

#include <iostream>

TileClass& TileClass::New(TextureCoordinates texCoords){
    static TileClass temp;
    temp.textureCoordinates = texCoords;
    return temp;
}
