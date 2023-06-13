#include"include/Creature.h"
#include"include/Player.h"
#include"include/Monster.h"
#include"include/Random.h"
#include<iostream>
#include <string>

void printInfo( Monster& c ){
	std::cout << "The " << c.getName() << " remaining " << c.getHealth() << " health.\n" ;
}

void printInfo( Player& p ){
	std::cout << p.getName() << " has " << p.getHealth() << " health and is carrying " << p.getGold() << " gold.\n";
}

char getUserInput(){
        char input {};
        std::cout << " \n(r)un or (f)ight? ";
        std::cin >> input;
        std::cout << '\n';
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return input;
    }

Player enterPlayer(){
    std::cout << "Enter your name:";
    std::string name { };
    std::cin >> name;
    std::cout << "Welcome, " << name << '\n';
    return Player{ name };
}

char playerInput(){
    char temp{ getUserInput()};
    while ( (temp != 'r') && (temp != 'f') ){
        std::cout << "Please enter valid command" << '\n';
        temp = getUserInput() ;
    }
    return temp;
}

bool isRunAway(char d){
    int temp { Random::get(0,2) };
    if (temp % 2 == 0){
        std::cout << "Escape Successful\n";
        return true;
    }
    else {
        return false;
    }
}

void attackPlayer(Monster& m , Player& p){
    p.reduceHealth( m.getDpa() );
    std::cout << p.getName() << " remaining " << p.getHealth() << " health...\n";
}

void attackMonster(Monster& m , Player& p){
    m.reduceHealth( p.getDpa() );
}

void game(){
    Player player1 { enterPlayer() };
    printInfo(player1);
    Monster monster {};
    while (!player1.isDead() && player1.getGold() < 100){
        //create a monster randomly;
        printInfo(monster);
        //player decision
        char decision { playerInput() };
        //if runaway
        if (decision == 'r'){
            if (isRunAway(decision)){
                monster = Monster{};
                continue;
                }
            else{
                    std::cout << "\nEscape Failed!";
                    attackPlayer(monster , player1);
                    continue;
                }
        }
        //attack
        if (decision == 'f'){
            attackMonster(monster , player1);
            if (monster.isDead()){
                player1.addGold( monster.getGold() );
                std::cout << monster.getName() << " is dead!! LV up\n";
                player1.levelUp();
                printInfo(player1);
                monster = Monster {};
                continue;
            }
            attackPlayer(monster , player1);
        }
    }
    
    if (player1.isDead())
        std::cout << " You Lose " << '\n';
    else {
        std::cout << " You Win " << '\n';
    }
}

int main()
{
    game();
	return 0;
}