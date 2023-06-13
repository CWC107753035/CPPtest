#ifndef MONSTER_H
#define MONSTER_H

#include"Creature.h"
#include"Random.h"
#include<iostream>

class Monster : public Creature
{
public:
    enum class Type{
        dragon, 
        goblin, 
        orc, 
        skeleton, 
        troll, 
        vampire, 
        zombie,
        max_monster_types
    };

private:
    Type m_monster;

public:
    Creature setup(Type& monster){
		switch (monster)
		{
            case Type::dragon: 
                return Creature { "dragon" , 'D' , 20 , 5 , 100 };
                
            case Type::goblin: 
                return Creature { "goblin" , 'G' , 4 , 2 , 15 };
                
            case Type::orc: 
                return Creature { "orc" , 'O' , 10 , 4 , 30 };
                
            case Type::skeleton: 
                return Creature { "skeleton" , 'S' , 2 , 4 , 10 };
                
            case Type::troll: 
                return Creature { "troll" , 'T' , 12 , 5 , 35 };
                
            case Type::vampire: 
                return Creature { "vampire" , 'V' , 15 , 4 , 40 };
                
            case Type::zombie:
                return Creature { "zombie" , 'Z' , 2 , 1 , 10 };
            default:
                return Creature {};
		}
    }

    Creature setup(){
        int temp { Random::get(0 , static_cast<int>(Type::max_monster_types)-1 ) };
        Type monster { static_cast<Type>(temp) };
        m_monster = monster;
		switch (monster)
		{
            case Type::dragon: 
                return Creature { "dragon" , 'D' , 20 , 5 , 100 };
                
            case Type::goblin: 
                return Creature { "goblin" , 'G' , 4 , 2 , 15 };
                
            case Type::orc: 
                return Creature { "orc" , 'O' , 10 , 4 , 30 };
                
            case Type::skeleton: 
                return Creature { "skeleton" , 'S' , 2 , 4 , 10 };
                
            case Type::troll: 
                return Creature { "troll" , 'T' , 12 , 5 , 35 };
                
            case Type::vampire: 
                return Creature { "vampire" , 'V' , 15 , 4 , 40 };
                
            case Type::zombie:
                return Creature { "zombie" , 'Z' , 2 , 1 , 10 };
            default:
                return Creature {};
		}
    }

    Monster( Type mon )
    : Creature { setup( mon ) } , m_monster { mon }
    {
    	std::cout << "The " << Creature::getName() << " has " << Creature::getHealth() << " health and is carrying " << Creature::getGold() << " gold.\n";
    }

    Monster(  )
    : Creature { setup() } , m_monster { }
    {
        std::cout << "The " << Creature::getName() << " has " << Creature::getHealth() << " health and is carrying " << Creature::getGold() << " gold.\n";
    }
};

#endif