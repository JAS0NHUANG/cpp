#include "Weapon.hpp"
#include <iostream>

Weapon::Weapon(std::string type){
	this->type = type;
	return ;
}

Weapon::~Weapon(void){
	/* debug
	std::cout << "\t(Debug)Weapon destroied!\n";
	*/
	return ;
}

void				Weapon::setType(std::string type){
	this->type = type;
	return ;
}

const std::string	&Weapon::getType(void) const{
	return (this->type);
}
