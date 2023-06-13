#include<iostream>
#include<string>

class Fruit
{
private:
	std::string m_name;
	std::string m_color;
public:
	Fruit(std::string name = "" , std::string color = "")
		:m_name { name }, m_color { color } 
		{}
	std::string getName(){
		return m_name;
	}
	std::string getColor(){
		return m_color;
	}
};

class Apple : public Fruit
{
private:
public:
	Apple(std::string color = "red" , std::string name  = "apple")
	:Fruit{ name ,color }
	{}

};

class Banana : public Fruit
{
private:

public:
	Banana(std::string name = "banana" , std::string color = "yellow")
	: Fruit{ name , color }
	{}
};

class GrannySmith : public Apple
{
private:
public:
	GrannySmith()
	:Apple { "green" , "GrannySmith" }
	{}
};


int main()
{
	Apple a{ "red" };
	Banana b;
	GrannySmith c;

	std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
	std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
	std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";

	return 0;
}