#ifndef BOARD_H
#define BOARD_H

#include<iostream>
#include<vector>
#include <eigen3/Eigen/Dense>
#include"tile.h"
#include"Random.h"

Tile::Tile(int t):m_tile{t}{
}

class Board
{
private:
    static constexpr int m_size{ 4 };
    std::pair< int , int > m_zero_pose{3,3}; 
    Eigen::Matrix<Tile, 4, 4> m_board;

    void initBoard(){
        int count { 1 };
        for (int rows { 0 } ; rows < m_size ; rows ++){
            for (int cols { 0 } ; cols < m_size ; cols ++){
                m_board(rows , cols) = Tile { count };
                count++;
            }
        }
        m_board(m_size -1 , m_size -1) = Tile{ 0 };
    }

public:
    Board(){
        initBoard();
    };

    void swapdown(){
        if (m_zero_pose.first > 0){
            std::swap (m_board(m_zero_pose.first , m_zero_pose.second) , m_board(m_zero_pose.first -1, m_zero_pose.second));
            m_zero_pose.first -= 1;
        }
    }

    void swapup(){
        if (m_zero_pose.first < 3){
            std::swap (m_board(m_zero_pose.first , m_zero_pose.second) , m_board(m_zero_pose.first +1, m_zero_pose.second));
            m_zero_pose.first += 1;
        }
    }

    void swapright(){
        if (m_zero_pose.second > 0){
            std::swap (m_board(m_zero_pose.first , m_zero_pose.second) , m_board(m_zero_pose.first , m_zero_pose.second-1));
            m_zero_pose.second -= 1;
        }
    }

    void swapleft(){
        if (m_zero_pose.second < 3){
            std::swap (m_board(m_zero_pose.first , m_zero_pose.second) , m_board(m_zero_pose.first , m_zero_pose.second+1));
            m_zero_pose.second += 1;
        }
    }

    void randomize(int n){
        for (int i { 0 }; i < n ; i++){
            int r { Random::get(0,3) };
            switch (r)
            {
            case 0:
                swapup();
                break;
            case 1:
                swapleft();
                break;
            case 2:
                swapdown();
                break;
            case 3:
                swapright();
                break;
            }
        }
    }

    bool isanswer() const{
        int count{ 1 };
        for (int rows { 0 } ; rows < m_size ; rows ++){
            for (int cols { 0 } ; cols < m_size ; cols ++){
                if (m_board(rows , cols).getNum() !=  count )
                    return false;
                count++;
                if (count == 16)
                    return true;
            }
        }
    }

    friend std::ostream& operator<<(std::ostream& out , Board& b);

};

std::ostream& operator<<(std::ostream& out , Board& b){
    for (int rows { 0 } ; rows < 4 ; rows ++){
        for (int cols { 0 } ; cols < 4 ; cols ++){
            out << b.m_board(rows , cols);
        }
        out << "\n";
    }
    return out;
}

#endif