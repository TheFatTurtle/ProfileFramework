#pragma once
#include "Group.h"
#include <stdint.h>
#include <string>
struct ApplicationDescriptor {
	std::string name;
	uint32_t groupFlags;
	ApplicationDescriptor() {
		name = "";
		groupFlags = 0;
	}
};

