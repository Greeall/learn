#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <Windows.h>
#include "author.h"


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


void author::most_popular_book(vector <order> all_orders)
{

	vector <int>::size_type size;
	size  = all_orders.size();
	int size_of_unique_names = 0;

	
	string *book_of_this_author = new string [size];
	int *count = new int [size];
	bool is_unique_name = true;

	for(int i = 0; i < size; i ++)
	{
		
		if(name == all_orders[i].book_obj.authors)
		{
			for(int j = 0; j < size_of_unique_names ; j++)
			{
				if(all_orders[i].book_obj.name == book_of_this_author[j])
				{
					is_unique_name = false;
					count[j]++;
				}
			}

			if(is_unique_name)
			{
				book_of_this_author[size_of_unique_names] = all_orders[i].book_obj.name;
				count[size_of_unique_names] = 1;
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
			index_of_most_popular_book = i;
		}
		
	cout<<book_of_this_author[index_of_most_popular_book]<<endl;
		
	delete [] book_of_this_author;
	delete [] count; 
}
