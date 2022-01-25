#pragma once
#include "Session.h"
#include "ApplicationDescriptor.h"
#include "Group.h"
#include "Privilege.h"
inline void RegisterGroup(Session* session, Group* group, bool isAllowed = false) {
	if (isAllowed) session->allowedGroups |= 1 << session->index;	
	session->registeredGroups[session->index++] = *group;
}
inline bool isInGroup(Group* group, ApplicationDescriptor* app) {
	for (size_t i = 0; i < group->appCount; i++) if (group->appNames[i] == app->name) return true;
}
inline void checkAllGroups(Session* session, ApplicationDescriptor* app) {
	//So many one liners
	for (size_t i = 0; i < session->index; i++)	if (isInGroup(&session->registeredGroups[i], app )) app->groupFlags |= 1 << i;
}
inline void AddDefault(Session* session) {
	Group* defaultGroup = new Group();
	defaultGroup->uuid = 0;
	RegisterGroup(session, defaultGroup, true);
}
inline bool isAllowed(Session* session, ApplicationDescriptor* app) {
	return (session->allowedGroups & app->groupFlags);
}
inline void makeStartable(ApplicationDescriptor* app) {
	if(!app->groupFlags) app->groupFlags = 1;
}