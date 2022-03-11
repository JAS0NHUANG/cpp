# Module00

## Namespace
Put some "things" inside a same "space".  

```
int	the_int = 0;
int	ft(void) { return 0;}


/* create a namespace, in whitch you can re-declare some variables */
namespace Xxx {
	int	the_int = 5;
	int	ft(void) { return 3;}
}

namespace Yyy {
	int	the_int = 5;
	int	ft(void) { return 3;}
}

/* namespace aliasing */
namespace Hello = XXX;
```

"::" - In PHP, the scope resolution operator is also called Paamayim Nekudotayim (wikipedia)

## stdio, iostream
`cin`, `cout` - read and write from stdio.
`<<`, `>>` - data flow.

`std::endl` - better portability then simple `\n`? (But I found some articles suggest to use `\n` rather then `endl`. So what's the GOOD answer?)  

`cin` problem: the user input will be split according to 'spaces'.

www.cplusplus.com


## OOP

### class and instance
Declaration: 
```
class Superclass
{
	public:
		/* constructor */
		Superclass(void);
		/* destructor */
		~Superclass(void);

}
```

Instancialization:
```
Superclass this_is_a_superclass;
/* the constructor will be called */
/* And the destructor will be called before exit of the scope. */
```

### attributes and functions(methods)
just declare them inside the class :D
and define them in a .cpp file.  
The function/method inside a class will ALWAYS have at least one argument "this" even the function is declare as `function(void)`.  

### 


	
	## encapsulation

	## class vs struct

	## accessors

## "this"

## list

## const






## ex00
- ostream:  
	`std::cout << "Print this\n";`  

## ex01
- istream:  
	`std::cin >> holder;`  
- string:  
	string.length();