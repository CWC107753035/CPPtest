#include<iostream>
#include<string>
#include<string_view>
#include<vector>
#include<array>

#include"include/Random.h"


class Monster
{
public:
    enum class Type{
        dragon, 
        goblin, 
        ogre, 
        orc, 
        skeleton, 
        troll, 
        vampire, 
        zombie,
        max_monster_types
    };

    Monster(Type monster = Type::goblin , std::string name = "default"
        , std::string roar = "default", int hitpoints = 10);
    ~Monster();

private:
    Type m_monster {};
    std::string m_name {};
    std::string m_roar {};
    int m_hitPoints {};

public:
    std::string_view getTypeString() const
	{
		switch (m_monster)
		{
		case Type::dragon: return "dragon";
		case Type::goblin: return "goblin";
		case Type::ogre: return "ogre";
		case Type::orc: return "orc";
		case Type::skeleton: return "skeleton";
		case Type::troll: return "troll";
		case Type::vampire: return "vampire";
		case Type::zombie: return "zombie";
		default: return "goblin";
		}
	}

    void print(){
        std::cout << m_name << " the " << getTypeString() << " has " 
            << m_hitPoints << " hit points and says " << m_roar << '\n';
    }

};

Monster::Monster(Type type, std::string name, std::string roar, int hitpoints )
    :m_monster {type}, m_name {name}, m_roar {roar}, m_hitPoints {hitpoints}
{
}

Monster::~Monster()
{
}

namespace MonsterGenerator
{
    Monster::Type random_type {Random::get(0 , static_cast<int>(Monster::Type::max_monster_types)-1 )};
    int hitPoints{ Random::get(1, 100) };
    static constexpr std::array s_names {"John", "Blast", "DD", "Killer", "Sweat", "Ace"};
    static constexpr std::array s_roar {"*RAH*", "*rrrrrrh*", "*oh..*", "*...*", "*uhh*", "*WHAM*"};

    Monster generateMonster(){
        Monster skeleton{ 
           random_type, 
            s_names[ Random::get(0, static_cast<int>(s_names.size() - 1)) ], 
            s_roar[ Random::get(0, static_cast<int>(s_roar.size() - 1)) ], 
            hitPoints };
        return skeleton;
    }

}

int main()
{
	Monster m = MonsterGenerator::generateMonster();
	m.print();
	return 0;
}