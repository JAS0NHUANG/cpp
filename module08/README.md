## STL(Standard Template Library)

### Containers
`Holder object`
Used to store a collection of objects/data/elements...
Implemented as `class templates`

`std::vector()`, `std::list()`, `std::stack()`(no iterators)

### algorithms
`std::sort()`, `std::find()`

## `shortestSpan()`
1. make a copy of the original vector.
1. use `sort()` (in algorithm library) to sort the vector. (the `sort()` method modifies the copied vector and returns NULL).
2. use `std::adjacent_diff(to find out the difference of value between each "adjacent" element and store it inside a "diff" vector.
3. use `std::min_element()` to find out the minimum value.

### iterator
iterator is just a pointer pointed to an element inside the container.
ex: "cntnr.begin()" points to the first element of the container "cntnr", and "cntnr.end()" will point to the last element.
we can also do arethmetic operation on iterators.

- Better use "const_iterator" whenever there is no changes intended to make on the element value. 

## some `std::vector` member functions
- `reserve()` 

## about `std::stack`
https://en.cppreference.com/w/cpp/container/stack
to make an iterator on stack, we need to acces the underlying container (default container is `deque`)_ via the protected member object `std::stack::c`.

## Some good suggestions

read some REAL LIFE CODES!!
https://www.youtube.com/watch?v=F9eDv-YIOQ0
