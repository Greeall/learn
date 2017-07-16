#include "stdafx.h"
#include "library.h"
#include <iostream>
#include <stdio.h>
#include <Windows.h>
#include <vector>
#include "reader.h"
#include "order.h"
#include "book.h"


library::library (vector <book> books_k, vector <reader> readers_k, vector <order> orders_k)
{
	books = books_k;
	readers = readers_k;
	orders = orders_k;
}

string library::convert_to_string()
{
	string str;
	return str;
}

vector <order> library::buy_book(reader reader_b, book buying_book, vector <order> all_orders)
{	
	all_orders.push_back(order(reader_b, buying_book));
	return all_orders;
}

void library::three_most_popular_books(vector <order> all_orders)
{
	vector <int>::size_type size;
	size  = all_orders.size();

	int size_of_unique_names = 0;
	string *book_of_this_author = new string [size];
	int *count = new int [size];
	bool is_unique_name = true;

	

	for(int i = 0; i < size; i ++)
	{
			for(int j = 0; j <size_of_unique_names; j++)
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


	int max = 0, index_of_most_popular_book;

	for(int k = 0; k < 3; k++)
	{
		max = 0;
		for (int i = 0; i < size_of_unique_names; i++)
		{
			if(count[i] > max)
			{
				max = count[i];
				index_of_most_popular_book = i;
			}
		}

		count[index_of_most_popular_book] = 0;
		cout<<book_of_this_author[index_of_most_popular_book]<<endl;
	}

}

void library::three_most_fresh_books(vector <book> all_books)
{
	vector <int>::size_type size;
	size  = all_books.size();

	int max = 0;
	int index;


	for(int j = 0; j < 3; j ++)
	{
		max = 0;
		for(int i = 0; i < size; i++)
		{
			if(all_books[i].year > max)
			{
				max = all_books[i].year;
				index = i;
			}
		}
		cout<<all_books[index].name<<endl;
		all_books[index].year = -100000;
	}
}