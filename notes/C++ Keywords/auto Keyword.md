
```cpp
#include <iostream>


int main() {
	
	auto var1 = 10;
	auto var2 = 5.4;
	
	for(auto iter: {1, 2, 3, 4}) {    // by Value
		std::cout<< iter << " ";
	}
	std::cout<< std::endl;

	for(auto iter: "Ahmed") {    // by Value
		std::cout<< iter << " ";
	}
	std::cout<< std::endl;

	int arr[] {1, 2, 3, 4};
	for(const auto& iter: arr) {    // by Reference
		std::cout<< iter << " ";
	}
	std::cout<< std::endl;

	return 0;
}
```
