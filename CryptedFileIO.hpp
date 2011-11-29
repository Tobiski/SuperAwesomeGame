#pragma once
#ifndef CRYPTEDFILEIO_HPP
#define CRYPTEDFILEIO_HPP

#include <string>
#include <vector>
#include <fstream>

class CryptedFileIO{
    public:
                            CryptedFileIO(std::string filename, int password);
                            ~CryptedFileIO();

        bool                Write(bool doDecrypting);
        bool                Read(bool doEncrypting);
        void                Clear();
        int                 GetSize() const;
        void                Add(std::string string);
        char&               operator[](int ptr);


    private:
        int                 _password;
        std::string         _filename;
        std::vector<char>   _content;
        std::ifstream       _in;
        std::ofstream       _out;
};

#endif
