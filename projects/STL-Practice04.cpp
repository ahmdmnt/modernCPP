#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

#define ENDL "\n"
std::map<std::string, std::string> mapFullname;

void displayDatabase();

int main() {
    char continueSignal = 'N';
    int fullnameSize {};
    do {
        std::cout<< "Enter Fullname Size: " << ENDL;
        std::cin>> fullnameSize;
        if( fullnameSize>0 ) {
            std::string nameInstance;
            std::string fullnameInstance;
            std::vector<std::string> fullnameList;
            for(int idx {0}; idx<fullnameSize; ++idx) {
                std::cin>> nameInstance;
                fullnameInstance+= nameInstance;
                fullnameList.push_back(fullnameInstance);
                if(idx < fullnameSize) {
                    fullnameInstance+= " ";
                }
            }

            for(auto& namePart: fullnameList) {
                mapFullname[namePart]= fullnameInstance;
            }
        }
        else {
            std::cout<< "Invalid Input: fullnameSize" << ENDL;
        }

        displayDatabase();

        std::cout<< "Do you want to continue [Y/n]: " << ENDL;
        std::cin>> continueSignal;
    } while (continueSignal == 'Y' || continueSignal == 'y');

    
    return 0;
}

void displayDatabase() {
    for(auto& element: mapFullname) {
        std::cout<< element.first << ":  " << element.second << std::endl;
    }
}

