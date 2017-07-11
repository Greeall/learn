#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <Windows.h>
#include "reader.h"
#include "order.h"
#include "book.h"


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



void reader::print_all_books(order *all_orders)
{
	for(int i = 0; i < 4; i++)
	{
		if(name == all_orders[i].reader_obj.name)
		{
			cout<<all_orders[i].book_obj.name<<endl;
		}
	}
}
