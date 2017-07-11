#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <Windows.h>
#include "author.h"


author::author(string nam, string con,  int birth)
{
	name = nam;
	country = con;
	year_of_birth = birth;
}


string author::convert_to_string()
{
	string str ;
	str += name + " ";
	str += country + " ";
	str += to_string(year_of_birth) + "\n";

	return str;
}


/*author::~author(void)
{
}*/
