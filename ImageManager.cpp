#include "ImageManager.hpp"

ImageManager::ImageManager()
{
    sf::Image temp;
    std::string tempName = "test.png";
    temp.LoadFromFile(tempName);
    _imageContainer.insert(std::pair<std::string, sf::Image>(tempName, temp));
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
