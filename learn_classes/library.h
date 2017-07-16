//#pragma once



#ifndef LIBRARY_H
#define LIBRARY_H

#include "stdafx.h"
#include "order.h"
#include <vector>
#include <string>
using namespace std;

class library
{
public:
	vector <book> books;
	vector <reader> readers;
	vector <order> orders;
	library(vector <book> books_k, vector <reader> readers_k, vector <order> orders_k);
	static vector <order> buy_book(reader reader_b, book buying_book, vector <order> all_orders);
	string convert_to_string();
	static void three_most_popular_books(vector <order> all_orders);
	static void three_most_fresh_books(vector <book> all_books);
	
};

#endif