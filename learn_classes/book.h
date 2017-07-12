//#pragma once


#ifndef BOOK_H
#define BOOK_H


#include "stdafx.h"
#include <vector>
#include <string>

using namespace std;

class order;
class reader;
class author;

class book
{
public:
	string name;
	int quantity_of_pages;
	string genre;
	string authors;
	int year;
	int price;

	book(string nam = "1", int quantity_pages = 1, string gen = "1", string autor = "1", int yea = 1, int pr = 1);
	
	string convert_to_string();
	void print_reader(vector <order> all_orders);

	//~book(void);

};

#endif 