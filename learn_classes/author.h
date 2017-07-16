//#pragma once


#ifndef AUTHOR_H
#define AUTHOR_H

#include "stdafx.h"
#include <string>
#include "order.h"
#include <vector>
using namespace std;


class author
{
public:
	string name;
	string country;
	int year_of_birth;

	author (string nam = "1", string con = "1",  int birth = 1);

	string convert_to_string();
	void most_popular_book(vector <order> all_orders);

};

#endif