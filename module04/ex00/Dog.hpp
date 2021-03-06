#ifndef _DOG_HPP_
# define _DOG_HPP_

# include <string>

# include "Animal.hpp"

class	Dog : public Animal {
	public:
		Dog( void );
		~Dog( void );
		Dog( const Dog &toCopy );
		Dog	&operator=( const Dog &toAssign);

		// member function
		void	makeSound( void ) const;
};

#endif
