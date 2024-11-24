#include <iostream>
#include <vector>
#include <string>

#define E_NOT_OK -1

void vectorPrint(std::vector<int>& refVector);
int vectorSum(std::vector<int>& refVector);
int maxSum_OfThreeStacks(std::vector<int>& vec1, std::vector<int>& vec2, std::vector<int>& vec3);

int main() {
	std::vector vector1 {1, 2, 3, 4};
	std::vector vector2 {1, 2, 2, 1, 2, 5, 2};
	std::vector vector3 {0, 3, 1, 1, 1, 5, 1};

	int sumValue {maxSum_OfThreeStacks(vector1, vector2, vector3)};

	if(sumValue != E_NOT_OK) {
		std::cout<< "sumValue= " << sumValue << std::endl; 
	}
	else {
		std::cout<< "Sum can't be found" << std::endl;
	}

	return 0;
}

void vectorPrint(std::vector<int>& refVector) {
	std::cout<< "Vector: ";
	for(auto number: refVector){
		std::cout<< number << " ";
	}
	std::cout<< std::endl;
}

int vectorSum(std::vector<int>& refVector) {
	int sumResult {};
	for(auto number: refVector){
		sumResult += number;
	}
	return sumResult;
}

int maxSum_OfThreeStacks(std::vector<int>& vec1, std::vector<int>& vec2, std::vector<int>& vec3) {
	int sumVec1 {vectorSum(vec1)};
	int sumVec2 {vectorSum(vec2)};
	int sumVec3 {vectorSum(vec3)};

	/* While the Vectors are not empty */
	while( !(vec1.empty()) and !(vec2.empty()) and !(vec3.empty()) ) {
		/* If All Sum are equal .. Just return the Sum Value */
		if( sumVec1==sumVec2 and sumVec2==sumVec3 ) {
			vectorPrint(vec1);vectorPrint(vec2);vectorPrint(vec3);

			/* Max Sum for 3 Stacks is found */
			return sumVec1;
		}

		/* Get Highest Sum of All Stacks and Try to Pop top Element */
		if( sumVec1>=sumVec2 and sumVec1>=sumVec3 ) {
			sumVec1 -= vec1.back();
			vec1.pop_back();
	 	}
		else if( sumVec2>=sumVec1 and sumVec2>=sumVec3 ) {
			sumVec2 -= vec2.back();
			vec2.pop_back();
		}
		else if( sumVec3>=sumVec1 and sumVec3>=sumVec2 ) {
			sumVec3 -= vec3.back();
			vec3.pop_back();
		}
		else {
			/* Do Nothing */
		}
	}
	return -1;
}
