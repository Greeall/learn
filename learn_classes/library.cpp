#include "stdafx.h"
#include "library.h"
#include <iostream>
#include <stdio.h>
#include <Windows.h>
#include <vector>
#include "reader.h"
#include "order.h"
#include "book.h"



library::library (book *books_k, reader *readers_k, order *orders_k)
{
	books = books_k;
	readers = readers_k;
	orders = orders_k;
}

string library::convert_to_string()
{
	string str ;
	return str;
}

void library::buy_book(reader reader_b, book buying_book, vector <order> all_orders)
{
	count_orders ++;
	all_orders.push_back(order(reader_b, buying_book));
}