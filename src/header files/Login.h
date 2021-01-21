#ifndef LOGIN_H
#define LOGIN_H

#include "Staff.h"

class Login
{
public:

	void InputName(string &Name, string &Password);

	int tryLogin(Staff &staff);

	int LoginPage(Staff &staff);
};



#endif
