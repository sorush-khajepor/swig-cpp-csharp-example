#include <iostream>
#include "animal.h"

Animal::Animal(std::string _name)
{
	name = _name;
}

void Animal::Walk()
{
	std::cout << name << " is walking..." << '\n';
}

std::string& Animal::GetName()
{
	return name;
}
