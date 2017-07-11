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

	static int count_orders;
	book *books;
	reader *readers;
	order *orders;
	library(book *books_k, reader *readers_k, order *orders_k);
	static void buy_book(reader reader_b, book buying_book, vector <order> all_orders);
	string convert_to_string();
	
};

#endif