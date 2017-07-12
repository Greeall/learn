//#pragma once



#ifndef READER_H
#define READER_H

#include "stdafx.h"
#include <string>
#include <vector>
using namespace std;

class order;

class reader
{
public:
	
	string name;
	string city;
	int age;

	reader (string name_r = "1", string city_r = "1", int age_r = 1);
	
	string convert_to_string();
	void print_all_books(vector <order> all_orders);
	
};

 #endif 