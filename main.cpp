#include <iostream>
#include "Framework/ProfileFramework.h"
#include <stdlib.h>
const char* dataPath = "./";
Session* currentSession;
char* StringOne = "test.app.com";
int main(int, char**) {
    Session* currentSession = new Session();
    AddDefault(currentSession);
    ApplicationDescriptor *app = new ApplicationDescriptor();
    app->name = "test.app.com";
    app->groupFlags = 2;
    makeStartable(app);
    Group* group = new Group();
    group->appNames = new char*[32];
    group->appNames[0] = StringOne;
    RegisterGroup(currentSession, group);
    bool canStart = isAllowed(currentSession, app);
    bool canStartElevated;
    //Privilege escalation happens here
    {
        Privilege canOpenGroup2(currentSession, 2);
        canStartElevated = isAllowed(currentSession, app);
    }
    bool canStartAfter = isAllowed(currentSession, app);
    ReadFromFile("Todo");
    return true;
}
