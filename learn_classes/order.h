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

	string convert_to_string(vector <reader> all_readers, vector <book> all_books);
};

#endif