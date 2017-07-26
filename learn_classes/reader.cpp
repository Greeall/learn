#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <Windows.h>
#include "reader.h"
#include "order.h"
#include "book.h"
#include "library.h"


reader::reader (string name_r, string city_r, int age_r)
{
	name = name_r;
	city = city_r;
	age = age_r;
}

string reader::convert_to_string()
{
	string str ;
	str += name + " ";
	str += city + " ";
	str += to_string(age) + "\n";

	return str;
}



void reader::print_all_books(library my_lib)
{
	vector <int>::size_type size;
	size  = my_lib.orders.size();

	for(int i = 0; i < size; i++)
	{
		if(name == my_lib.orders[i].reader_obj.name)
		{
			cout<<my_lib.orders[i].book_obj.convert_to_string()<<endl;
		}
	}
}
