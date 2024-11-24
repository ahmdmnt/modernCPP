#include <iostream>
#include <tuple>
#include <map>


int main() {
    std::tuple<char, int, bool> t = std::make_tuple('C', 70, true);
    auto [n1, n2, n3] = t;

    auto [n1, n2, n3] = std::tuple('A', 100, true);


    std::map< int, char> myMap {
        {1, 'A'},
        {2, 'B'},
        {3, 'C'},
        {4, 'D'}
    };

    for( const auto& [key, value]: myMap ) {
        std::cout<< key << ": " << value << std::endl;
    }

    return 0;
}