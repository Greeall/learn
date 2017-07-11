//#pragma once


#ifndef AUTHOR_H
#define AUTHOR_H

#include "stdafx.h"
#include <string>
using namespace std;


class author
{
public:
	string name;
	string country;
	int year_of_birth;

	author (string nam = "1", string con = "1",  int birth = 1);

	void most_popular_book();
	string convert_to_string();

	//~author(void);
};

#endif