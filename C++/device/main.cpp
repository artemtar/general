#include <iostream>
#include <array>
#include "device.h"

using std::cout;
using std::cin;
using std::endl;

int main()
{

	// Make 6 devices using all four different device types at least once
	std::array<Device, 6> dev{{{"clunker", Device::Type::phone, {1, 3, 2010}},
							   {"jewel", Device::Type::watch, {12, 5, 2017}},
							   {"doorstop", Device::Type::laptop, {21, 7, 2016}},
							   {"swish", Device::Type::tablet, {5, 11, 2009}},
							   {"red", Device::Type::phone, {9, 6, 2017}},
							   {"light", Device::Type::laptop, {3, 3, 2015}}}};

	// Pushing the six devices onto the charge stack
	cout << "=================================" << endl;
	cout << "Pushing the devices on the stack: " << endl;
	cout << "=================================" << endl;
	ChargeStack cs;

	for (auto &d : dev)
	{
		cs.push(d);
	}
	cout << "=================================" << endl;
	cout << "Printing the queue: " << endl;
	cout << "=================================" << endl;

	cs.print(cout);
	cout << "=================================" << endl;
	cout << "Removing the last three devices: " << endl;
	cout << "=================================" << endl;
	for (int i = 0; i < 3; ++i)
	{
		cs.pop();
	}
	cout << "=================================" << endl;
	cout << "Printing the queue again: " << endl;
	cout << "=================================" << endl;
	cs.print(cout);
	// Make a new queue by copying the queue
	cout << "=================================" << endl;
	cout << "Making a new stack by copy: " << endl;
	cout << "=================================" << endl;
	ChargeStack cs2{cs};
	cout << "===============================================" << endl;
	cout << "Moving the remaining devices to the new Stack: " << endl;
	cout << "===============================================" << endl;
	//moving the remaining three
	for (int i = 0; i < 3; ++i)
	{
		cs2.push(cs.pop());
	}
	cout << "=================================" << endl;
	cout << "Printing the new stack: " << endl;
	cout << "=================================" << endl;
	cs2.print(cout);
	cout << "=================================" << endl;
	return 0;
}
