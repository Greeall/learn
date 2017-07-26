#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <Windows.h>
#include "author.h"
#include "library.h"


author::author(string nam, string con,  int birth)
{
	name = nam;
	country = con;
	year_of_birth = birth;
}


string author::convert_to_string()
{
	string str ;
	str += name + " ";
	str += country + " ";
	str += to_string(year_of_birth) + "\n";

	return str;
}


void author::most_popular_book(library my_lib)
{

	vector <int>::size_type size;
	size  = my_lib.orders.size();
	int size_of_unique_names = 0;

	
	string *book_of_this_author = new string [size];
	int *count = new int [size];
	int *index = new int [size];
	bool is_unique_name = true;

	for(int i = 0; i < size; i ++)
	{
		
		if(name == my_lib.orders[i].book_obj.authors)
		{
			for(int j = 0; j < size_of_unique_names ; j++)
			{
				if(my_lib.orders[i].book_obj.name == book_of_this_author[j])
				{
					is_unique_name = false;
					count[j]++;
				}
			}

			if(is_unique_name)
			{
				book_of_this_author[size_of_unique_names] = my_lib.orders[i].book_obj.name;
				count[size_of_unique_names] = 1;
				index[size_of_unique_names] = i;
				size_of_unique_names ++;
			}

			is_unique_name = true;
		}
	}

	int max = 0, index_of_most_popular_book;
	for (int i = 0; i < size_of_unique_names; i++)
		if(count[i] > max)
		{
			max = count[i];
			index_of_most_popular_book = index[i];
		}
		
	cout<<my_lib.books[index_of_most_popular_book].convert_to_string()<<endl;

		
	delete [] book_of_this_author;
	delete [] count; 
}
