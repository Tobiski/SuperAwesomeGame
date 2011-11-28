#ifndef IMAGEMANAGER_HPP
#define IMAGEMANAGER_HPP

#include <SFML/Graphics.hpp>
#include <map>
#include <iostream>

class ImageManager
{
    public:
        static sf::Image& GetImage(std::string imageDir);

    private:
        ImageManager();
        ~ImageManager();
        static std::map<std::string, sf::Image> _imageContainer;
};

#endif
