//============================================================================
// Name        : Catching.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <exception>
using namespace std;

void goesWrong() {
	bool error1Detected = true;
	bool error2Detected = false;

	if (error1Detected) {
		throw bad_alloc();
	}

	if (error2Detected) {
		throw exception();
	}
}

// Always try to catch subclasses before parent classes. Bad_alloc is a subclass of exception (inherits from)
// bad_alloc is a form of exception, but exception does not fit in bad_alloc. 
// Exception has many subclasses which can be found on the exception std page when you google it. 

int main() {

	try {
		goesWrong();
	} catch (bad_alloc &e) {
		cout << "Catching bad_alloc: " << e.what() << endl;
	} catch (exception &e) {
		cout << "Catching exception: " << e.what() << endl;
	}

	return 0;
}
