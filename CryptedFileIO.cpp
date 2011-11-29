#include "CryptedFileIO.hpp"

#include <iostream>
#include <cstdlib>

CryptedFileIO::CryptedFileIO(std::string filename, int password){
    _filename = filename;
    _password = password;
}

CryptedFileIO::~CryptedFileIO(){
}

bool CryptedFileIO::Read(bool doDecrypting){
    _in.open(_filename.c_str(), std::ios::binary);
    if(_in.is_open()){
        srand(_password);
        while(_in.good()){
            _content.push_back(doDecrypting ? _in.peek() - rand()%256 : _in.peek());
            _in.seekg(_in.tellg()+1);
        }
        _in.close();
        return true;
    }
    else{
        std::cout << "WARNING: Couldn't open file '" << _filename << "'" << std::endl;
        return false;
    }
}

bool CryptedFileIO::Write(bool doEncrypting){
    _out.open(_filename.c_str(), std::ios::binary);
    if(_out.is_open()){
        srand(_password);
        for(int i = 0; i < _content.size()-1; i++){
            _out.put(doEncrypting ? _content[i] + rand()%256 : _content[i]);
        }
        _out.close();
        return true;
    }
    else{
        std::cout << "WARNING: Couldn't open file '" << _filename << "'" << std::endl;
        return false;
    }
}

void CryptedFileIO::Clear(){
    _content.clear();
}

int CryptedFileIO::GetSize() const{
    return _content.size();
}

void CryptedFileIO::Add(std::string string){
    for(int i = 0; i < string.size(); i++){
        _content.push_back(string[i]);
    }
}

char& CryptedFileIO::operator[](int ptr){
    if(ptr < _content.size()){
        return _content[ptr];
    }
    else{
        static char errorChar = 0;
        std::cout << "Index out of bounds: " << ptr << std::endl;
        return errorChar;
    }
}
