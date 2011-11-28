#pragma once
#ifndef VECTOR2D_HPP
#define VECTOR2D_HPP

#include <vector>
#include <iostream>


//Vector2D<T>
//A 2D vector that holdy objects of any type (templated)
//Members:
//Vector2D(int width, int height, T initValue)  - x and y of vector, value that all objects will be set to on initialisation
//GetWidth()                                    - returns width of vector (x)
//GetHeight()                                   - returns height of vector (y)
//operator(x, y)                                - returns a reference to the object at (x/y)


template<class T>
class Vector2D{
    public:
                            Vector2D(int width, int height, T initValue);
                            ~Vector2D();
            T&              operator()(int width, int height);
            int             GetWidth() const;
            int             GetHeight() const;

    protected:
                            Vector2D();
            std::vector<T>  _content;
            int             _width;
            int             _height;
};

template<class T>
Vector2D<T>::Vector2D(int width, int height, T initValue){
    _width = width;
    _height = height;
    _content.assign(width * height, initValue);
}

template<class T>
Vector2D<T>::~Vector2D(){
}

template<class T>
T& Vector2D<T>::operator()(int width, int height){
    return _content[width + (height * _width)];
}

template<class T>
int Vector2D<T>::GetWidth() const{
    return _width;
}

template<class T>
int Vector2D<T>::GetHeight() const{
    return _height;
}

#endif
