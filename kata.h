//Kata.h
//Blake Caldwell
//March 10, 2020
//completes the string calculator kata

#include <string>
#include <sstream>


int stringCalc(std::string input) {
	std::istringstream ins(input);
	int intReturn = 0;
	char operation = ' ';
	int secondInt = 0;
	char operationTwo = ' ';
	int thirdInt = 0;

	ins >> std::noskipws >> intReturn >> operation >> secondInt >> operationTwo >> thirdInt;

	if (operationTwo == ',' || operationTwo == '\n')
		secondInt += thirdInt;

	if (operation == ',' || operation == '\n')
		intReturn += secondInt;

	return intReturn;
}