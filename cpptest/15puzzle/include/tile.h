#ifndef TILE_H
#define TILE_H

#include<iostream>

class Tile
{
private:
    int m_tile;
public:
    explicit Tile(int tile = 0);
    friend std::ostream& operator<<(std::ostream& out , Tile& t); 

    bool isEmpty() const {
        return m_tile == 0 ? true : false;
    }

    int getNum() const{
        return m_tile;
    }
};

std::ostream& operator<<(std::ostream& stream , Tile& tile){
    if (tile.m_tile > 9) // if two digit number
        stream << " " << tile.m_tile << " ";
    else if (tile.m_tile > 0) // if one digit number
        stream << "  " << tile.m_tile << " ";
    else if (tile.m_tile == 0) // if empty spot
        stream << "    ";
    return stream;
}

#endif