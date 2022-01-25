#pragma once 
#include <string>
#include "Reader.h"
using namespace std;
struct Group {
	char* name;
	unsigned int uuid;
	unsigned char index;
	unsigned int appCount;
	char** appNames;
	Buffer* buffer;
	~Group() {
		if(buffer) delete buffer;
	};
};
