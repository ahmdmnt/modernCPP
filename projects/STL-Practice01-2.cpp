#include <iostream>
#include <deque>

class NumberStream {
	int streamSize;
	int sumValue {};
	std::deque<int> numStream;

public:
	NumberStream(int l_streamSize): streamSize(l_streamSize) {}

	int nextNumberAndComputeSum(int newNumber) {
		numStream.push_front(newNumber);
		while ( numStream.size()>streamSize ) {
			numStream.pop_back();
		}
		computeSum();

		return sumValue;
	}
	void computeSum() {
		std::deque<int> tempStream = numStream;
		sumValue = 0;
		while ( !(tempStream.empty()) ) {
			sumValue += tempStream.front();
			tempStream.pop_front();
		}
	}
	void printStream() {
		std::deque<int> tempStream = numStream;
		std::cout<< "Stream Values: ";
		while ( !(tempStream.empty()) ) {
			std::cout<< tempStream.front() << " ";
			tempStream.pop_front();
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
