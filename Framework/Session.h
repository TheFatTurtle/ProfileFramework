#pragma once
#include <stdint.h>
#include "Group.h"
struct Session {
   uint32_t allowedGroups;
   Group registeredGroups[32];
   unsigned char index;
   Session() {
      allowedGroups = 0;
      index = 0;
   }
};