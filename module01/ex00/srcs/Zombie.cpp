#include "Zombie.hpp"

Zombie::Zombie( std::string name ){
	this->name = name;
	std::cout << "Zombie " << this->name << "\t rised from the death~~~\n";
}

Zombie::~Zombie( void ){
	std::cout << "Zombie " << this->name << "\t destroid~~~\n";
}

void	Zombie::announce( void ){
	std::cout << this->name << ": BraiiiiiiinnnzzzZ...\n";
	return ;
}
