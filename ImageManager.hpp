#ifndef IMAGEMANAGER_HPP
#define IMAGEMANAGER_HPP

#include <SFML/Graphics.hpp>
#include <map>
#include <iostream>

class ImageManager
{
    public:
        ImageManager();
        ~ImageManager();
        sf::Image& GetImage(std::string imageDir);
    private:
        std::map<std::string, sf::Image> _imageContainer;
};

#endif
