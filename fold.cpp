#include <iostream>
#include <utility>
#include <ostream>
#include <tuple>

#define COUT std::cout
#define ENDL std::endl

#define expect( exp ) do { if ( !(exp) ) COUT << "expect failed: " #exp << ENDL;  } while(0)

using namespace std;

template< typename... Ts>
constexpr inline bool and_all(Ts && ... ts) 
{
    return ( ... && ts ); // ts is last operand. i.e. (t1 && t2) && t3
}

template<typename F, typename... Ts>
void invoke(F && f, Ts &&... ts )
{
    return ( (f)(&f, std::forward<Ts>(ts)), ... );
}

template <unsigned... Is> 
struct Seq {};

template<unsigned N, unsigned... Is>
struct gen: gen<N - 1, N-1, Is...> 
{};

template<unsigned... Is>
struct gen<0, Is...>: Seq<Is...>
{};

template<template <class> class Tuple, typename... Ts, unsigned... Is>
void printImpl( ostream & os, Tuple<Ts...> const & tup, Seq<Is...> )
{
    ( (os << Is << " : [" << get<Is>(tup) << "]\n"), ... );
}

template<template <class> class Tuple, typename... Ts>
ostream & print( ostream & os, Tuple<Ts...> const & tup)
{
    printImpl(os, tup, gen<sizeof...(Ts)>());
    return os;
}

int main(void)
{
    COUT << ( and_all( 1, 2, 4 ) ? 'T' : 'F') << ENDL;

    auto f = [](auto self , auto && t) {
        COUT << "\nf: 0x" << self <<" v:[" << t << "]";
    };

    invoke(f, "int " , 1 , " double ", 2.1);

    COUT << ENDL;

    print( COUT, tuple{"int:", 1, "double:", 2.1}) << ENDL;

    return 0;
}