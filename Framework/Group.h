#pragma once 
#include <string>
using namespace std;
struct Group {
	char* name;
	unsigned int uuid;
	unsigned char index;
	unsigned int appCount;
	char** appNames;
};
