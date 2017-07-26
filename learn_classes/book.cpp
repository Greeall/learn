#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <Windows.h>
#include "book.h"
#include "reader.h"
#include "order.h"
#include "library.h"
#include <string>

 book::book(string nam, int quantity_pages, string gen, string autor, int yea, int pr)
{
	name = nam;
	quantity_of_pages = quantity_pages;
	genre = gen;
	authors = autor;
	year = yea;
	price = pr;
}
  
string book::convert_to_string()
{
	string str ;

	str += name + " ";
	str += to_string(quantity_of_pages) + " ";
	str += genre + " ";
	str += authors + " ";
	str += to_string(year) + " ";
	str += to_string(price) + "\n";

	return str;
}


void book::print_reader(library my_lib)
{
	vector <int>::size_type size;
	size  = my_lib.orders.size();
	

	string *unique_readers = new string [size];
	int size_of_unique_readers = 0;
	bool is_unique_name = true;

	for(int i = 0; i < size; i++)
		if(my_lib.orders[i].book_obj.name == name)
		{
			
			for(int j = 0; j <= size_of_unique_readers + 1; j++)
			{
				if(my_lib.orders[i].reader_obj.name == unique_readers[j])
					is_unique_name = false;
			}

			if(is_unique_name)
			{
				cout<<my_lib.orders[i].reader_obj.convert_to_string()<<"\n";
				unique_readers[size_of_unique_readers] = my_lib.orders[i].reader_obj.name;
				size_of_unique_readers ++;
			}

			is_unique_name = true;
		}
				

}
