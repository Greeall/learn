#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <Windows.h>
#include "order.h"


order::order (reader name_r, book name_b)
{
	reader_obj = name_r;
	book_obj = name_b;
}

string order::convert_to_string(vector <reader> all_readers, vector <book> all_books)
{
	string str;
	int index_of_reader, index_of_book;

	vector <int>::size_type quantity_books, 
							quantity_readers;

	quantity_books = all_books.size();
	quantity_readers = all_readers.size();

	for(int i = 0; i < quantity_readers; i++)
		if(reader_obj.name == all_readers[i].name)
			index_of_reader = i;

	for(int i = 0; i < quantity_books; i++)
		if(book_obj.name == all_books[i].name)
			index_of_book = i;

	str += to_string(index_of_reader) + " ";
	str += to_string(index_of_book) + " ";

	return str;
}


