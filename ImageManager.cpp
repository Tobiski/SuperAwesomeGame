#include "ImageManager.hpp"

std::map<std::string, sf::Image> ImageManager::_imageContainer;

ImageManager::ImageManager()
{

}

ImageManager::~ImageManager()
{

}

sf::Image& ImageManager::GetImage(std::string imageDir)
{
    if(_imageContainer.count(imageDir) < 1)
{
        sf::Image temp;
        temp.LoadFromFile(imageDir);
        _imageContainer.insert(std::pair<std::string, sf::Image>(imageDir, temp));
    }
    return _imageContainer[imageDir];
}
