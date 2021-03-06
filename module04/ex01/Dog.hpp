#ifndef _DOG_HPP_
# define _DOG_HPP_

# include <string>

# include "Animal.hpp"
# include "Brain.hpp"

class	Dog : public Animal {
	public:
		Dog( void );
		Dog( std::string name );
		~Dog( void );
		Dog( const Dog &toCopy );
		Dog	&operator=( const Dog &toAssign);

		// member function
		void	makeSound( void ) const;
		void	printIdeas( void ) const;
		void	addIdea(std::string idea);

	private:
		std::string name;
		Brain*	dogBrain;
};

#endif
