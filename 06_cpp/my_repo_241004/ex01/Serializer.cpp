#include "Serializer.hpp"

/*  --- Orthodox Canonical Form Functions (Private)--- */
Serializer::Serializer( void ) {}

Serializer::Serializer( const Serializer &oth )
{
	*this = oth;
}

Serializer& Serializer::operator=( const Serializer &oth )
{
	(void) oth;
	return (*this);
}

Serializer::~Serializer( void ) {}

/* ------------------- PUBLIC MEMBER FUNCTIONS ------------------*/


/*
 * <stdint.h>  : uintptr_t
 *
 * Error if use :
 * <cstdint>  : std::uintptr_t   (C++11)
 *
 * https://stackoverflow.com/questions/1845482/what-is-the-uintptr-t-data-type
 *
 * https://blog.feabhas.com/2024/02/navigating-memory-in-c-a-guide-to-using-stduintptr_t-for-address-handling/
 *
 * std::uintptr_t is a versatile unsigned integer type designed to store the entire address range of any object in C++, ensuring portability and precision.
 * 	
 * https://www.reddit.com/r/cpp_questions/comments/wcxmqi/help_with_uintptr_t/?rdt=44419
 * If you want to interpret a particular value as either an unsigned integer or a pointer, this guarantees that it will be the correct size compiled under both 32 bit and 64 bit
 */

/*
 * reinterpret_cast
 * Used with pointers
 *
 * Use examples:
 * https://www.geeksforgeeks.org/reinterpret_cast-in-c-type-casting-operators/#main		
 * https://en.cppreference.com/w/cpp/language/reinterpret_cast
 */

uintptr_t	Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data*		Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}
