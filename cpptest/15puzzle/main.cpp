#include<iostream>
#include"include/tile.h"
#include"include/board.h"

namespace UserInput{
    char getUserInput(){
        std::cout << "Input a move: ";
        char input {};
        std::cin >> input;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return input;
    }
    
    bool isValid(char& input){
        if (input == 'q' ||
        input == 'w' || 
        input == 'a' || 
        input == 's' || 
        input == 'd' ){
            return true;
        }
        else{
            return false;
        }
    }

    void move(char& input, Board& board){
        switch (input)
        {
        case 'w':
            board.swapup();
            std::cout << board<< "\n\n";
            break;
        case 'a':
            board.swapleft();
            std::cout << board<< "\n\n";
            break;
        case 's':
            board.swapdown();
            std::cout << board<< "\n\n";
            break;
        case 'd':
            board.swapright();
            std::cout << board << "\n\n";
            break;
        }
    }
}

int main()
{
    Board board{};
    board.randomize(100);
    std::cout << board;
    while (true){
        char input = UserInput::getUserInput() ;
        if ( !UserInput::isValid (input) ){
            std::cout << "Please enter valid input 'wasd' to move or 'q' to quit\n";
        }
        if (input == 'q'){
            std::cout << "Bye!\n";
            break;
        }
        else{
            UserInput::move(input, board);
            if (board.isanswer()){
                std::cout << "YOU WIN!\n";
                break;
            }
        }
        
    }
    return 0;
}