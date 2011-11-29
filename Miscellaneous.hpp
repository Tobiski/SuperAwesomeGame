#pragma once
#ifndef MISCELLANEOUS_HPP
#define MISCELLANEOUS_HPP

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

typedef sf::Rect<int> TextureCoordinates;

namespace Framework{

    //CreateWindow
    //Arguments:
    //window                                        - A reference to the window that will be (re)initialised
    //windowVideoMode                               - Self explantory, sf::VideoMode for the window
    //windowTitle                                   - Title for the window
    //windowFullscreen                              - if true, window will run in fullscreen
    void InitWindow(sf::RenderWindow* window, sf::VideoMode windowVideoMode, std::string windowTitle, bool windowFullscreen);

};

#endif
