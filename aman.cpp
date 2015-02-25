
/* This is the unit test file which takes a file and send to my interpretor to check whether my functionality of interpretor is 
properly implemented or not
*/


#include <iostream>
#include <string>
#include <fstream>
#include "interpret.h"
using namespace std;

int main()
{
	string sn;
	std::cout << "enter the name of the file\n";
	cin >> sn;
	interpretor(sn);
}