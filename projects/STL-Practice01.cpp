#include <iostream>
#include <queue>

class NumberStream {
	int streamSize;
	int sumValue {};
	std::queue<int> numStream;

public:
	NumberStream(int l_size): streamSize(l_size) {}

	int nextNumberAndComputeSum(int newNumber) {
		sumValue += newNumber;
		numStream.push(newNumber);

		if( numStream.size()>4 ) { 
			sumValue -= numStream.front();
			numStream.pop();
		}
		
		return sumValue;
	}

	void printStream() {
		std::queue<int> tempStream = numStream;
		std::cout<< "Stream Values: ";
		while ( !(tempStream.empty()) ) {
			std::cout<< tempStream.front() << " ";
			tempStream.pop();
		}
		std::cout<< std::endl;
	}
};

int main() {
	NumberStream inputNumberStream(4);

	int numVariable;
	while( std::cin>>numVariable ) {
		std::cout<< "Sum= " << inputNumberStream.nextNumberAndComputeSum(numVariable) << std::endl;
		inputNumberStream.printStream() ;
	}

	return 0;
}
