//#pragma once



#ifndef ORDER_H
#define ORDER_H


#include "stdafx.h"
#include <string>
#include "book.h"
#include "reader.h"
#include "author.h"
using namespace std;

class order
{
public:
	reader reader_obj;
	book book_obj;

	order();
	order (reader name_r, book name_b);


	//~order(void);
};

#endif