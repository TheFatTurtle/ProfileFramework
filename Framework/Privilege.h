#pragma once 
#include "Session.h"
//Represents a privilege granted to the session and removed when struct is destroyed
struct Privilege {
	Session* session;
	uint32_t granted;
	Privilege(Session* session, uint32_t granted) {
		this->session = session;
		this->granted = granted;
		session->allowedGroups |= granted;
	}
	~Privilege() {
		//Need a reverse or operator for this
		session->allowedGroups = !((!session->allowedGroups) | this->granted);
	}
};