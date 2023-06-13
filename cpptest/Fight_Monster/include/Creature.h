#ifndef CREATURE_H
#define CREATURE_H

#include<string>

class Creature
{
protected:
    std::string m_name;
    char m_symbol;
    int m_health;
    int m_dpa;
    int m_gold;

public:
    Creature( std::string name = "default" , char symbol = '?'
        , int health = 0 , int dpa = 0 , int gold = 0 )
        :m_name {name} , m_symbol {symbol} , m_health {health}, m_dpa {dpa} , m_gold{gold}
        {}
    std::string& getName(){ return m_name; }
    const char& getSymbol(){ return m_symbol; }
    const int& getHealth(){ return m_health; }
    const int& getDpa(){ return m_dpa; }
    const int& getGold(){ return m_gold; }

    void reduceHealth( int hit ){
        m_health -= hit;
    }
    bool isDead (){
        return true ? m_health <= 0 : m_health > 0;
    }
    void addGold( int money ){
        m_gold += money;
    }
};


#endif 