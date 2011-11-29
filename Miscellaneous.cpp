#include "Miscellaneous.hpp"

void Framework::InitWindow(sf::RenderWindow* window, sf::VideoMode windowVideoMode, std::string windowTitle, bool windowFullscreen){
    if(window->IsOpened()){
        window->Close();
    }
    window->Create(windowVideoMode, windowTitle, windowFullscreen ? sf::Style::Fullscreen : sf::Style::Close);
    window->SetFramerateLimit(60);
}
