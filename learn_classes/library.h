//#pragma once



#ifndef LIBRARY_H
#define LIBRARY_H

#include "stdafx.h"
#include "order.h"
#include <vector>
#include <string>
using namespace std;

class library;

class library
{
public:
	vector <book> books;
	vector <reader> readers;
	vector <order> orders;
	vector <author> authors;
	library (string way);
	vector <order> buy_book(reader reader_b, book buying_book);
	string convert_to_string();
	static void three_most_popular_books(library my_lib);
	static void three_most_fresh_books(library my_lib);
	static library read_library_from_file(string way);
	static void save_to_file(string way, library my_lib);
	~library();

	
};

#endif