#include <iostream>

using namespace std;

template<class ... Int>
constexpr auto add_all(Int... args)
{
    return ( ... + args);
}

template<class Out, class ... Ts>
decltype(auto) println(Out & out, Ts && ... ts)
{
    return ( (out << ts << ','), ... ) << '\n';
}

template<class ... Int>
constexpr auto mask(Int... args)
{
    return ( ... | (1ULL<<args));
}


template<int Target, int First, int... Rest>
constexpr int find_index()
{
    if constexpr (Target == First)
        return 0;
    else if constexpr (!sizeof...(Rest))
        return -1;
    else
        return 1 + find_index<Target, Rest...>();
}

int main(void)
{
    constexpr auto result = add_all( 1, 1, 2, 3, 4);
    cout << result << endl; 

    println(cout, 1, 2, "3", 4.0);

    constexpr auto result2 = mask( 0, 2, 63);
    cout << hex << "0x" << result2 << endl; 

    constexpr auto find5 = find_index<5, 1, 2, 5>();
    cout << "\n find_index(5, 1, 2, 5) = " << find5 << endl;
    return 0;
}