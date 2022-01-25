#include <iostream>
#include "Framework/ProfileFramework.h"
#include <stdlib.h>
const char* dataPath = "./";
Session* currentSession;
int main(int, char**) {
    Session* currentSession = new Session();
    AddDefault(currentSession);
    ApplicationDescriptor *app = new ApplicationDescriptor();
    return true;
}
