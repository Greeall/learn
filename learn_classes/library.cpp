#include "stdafx.h"
#include "library.h"
#include <iostream>
#include <stdio.h>
#include <Windows.h>
#include <vector>
#include "reader.h"
#include "order.h"
#include "library.h"
#include "book.h"
#include <fstream>
#include <string>

using namespace std;

library::library (string way)
{
	ifstream out_library;
	out_library.open(way);

	int size; 
	out_library>>size;

	string reading[100][100]; // (make array dynamic in future)

	for(int i = 0; i < size; i++)			//reading books
		for(int j = 0; j < 6; j ++)
			out_library>>reading[i][j];

	string name_b, genre_b, author_b;
	int quantity_of_pages_b, year_b, price_b;


	for(int i = 0; i < size; i++)         // convert information in strings to objects of book
	{
		name_b = reading[i][0];
		quantity_of_pages_b =  atoi(reading[i][1].c_str());
		genre_b = reading[i][2];
		author_b = reading[i][3];
		year_b = atoi(reading[i][4].c_str());
		price_b = atoi(reading[i][5].c_str());

		books.push_back(book(name_b,quantity_of_pages_b,genre_b,author_b,year_b,price_b));   
	}

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////
	////READING ALL LIBRARY'S READERS////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////

	out_library>>size;						//quantity readers

	for(int i = 0; i < size; i++)			//reading readers
		for(int j = 0; j < 3; j ++)
			out_library>>reading[i][j];

	string name_r, city_r;
	int age_r;


	for(int i = 0; i < size; i++)         // convert information in strings to objects of reader
	{
		name_r = reading[i][0];
		city_r = reading[i][1];
		age_r = atoi(reading[i][2].c_str());

		readers.push_back(reader(name_r,city_r,age_r));   
	}

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////
	////READING AUTHORS OF BOOKS/////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////

	out_library>>size;						//quantity authors

	for(int i = 0; i < size; i++)			//reading authors
		for(int j = 0; j < 3; j ++)
			out_library>>reading[i][j];

	string name_a, country_a;
	int year_of_birth_a;

	for(int i = 0; i < size; i++)         // convert information in strings to objects of author
	{
		name_a = reading[i][0];
		country_a = reading[i][1];
		year_of_birth_a = atoi(reading[i][2].c_str());

		authors.push_back(author(name_a,country_a,year_of_birth_a));   
	}

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////
	////READING LIBRARY'S ORDERS/////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	out_library>>size;						//quantity orders

	for(int i = 0; i < size; i++)			//reading orders
		for(int j = 0; j < 2; j ++)
			out_library>>reading[i][j];

	int reader_index;
	int book_index;
	
	for(int i = 0; i < size; i++)         // convert information in strings to objects of order
	{
		reader_index = atoi(reading[i][0].c_str());
		book_index = atoi(reading[i][1].c_str());

		orders.push_back(order(readers[reader_index],books[book_index]));   
	}

	out_library.close();
}

string library::convert_to_string()
{
	string str;
	return str;
}

vector <order> library::buy_book(reader reader_b, book buying_book)
{	
	orders.push_back(order(reader_b, buying_book));
	cout<<"New order was creating: \n "<<reader_b.convert_to_string()<<" bought \n "
		<<buying_book.convert_to_string()<<endl;
	return orders;
	
}

void library::three_most_popular_books(library my_lib)
{
	cout<<"There are most popular books: "<<endl<<endl;

	vector <int>::size_type size;
	size  = my_lib.orders.size();

	int size_of_unique_names = 0;					  //quantity of unique (not repeating) books
	string *book_of_this_author = new string [size];  //array for unique books
	int *count = new int [size];					  //array for counter reapeting books
	int *index = new int [size];					  //array for saving index reapeting books
	bool is_unique_name = true;						  //variable for determining unique books

	

	for(int i = 0; i < size; i ++)
	{
			for(int j = 0; j <size_of_unique_names; j++)
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
				index[size_of_unique_names] = i;
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
				index_of_most_popular_book = index[i];
			}
		}

		count[index_of_most_popular_book] = 0;
		cout<<"\t"<<my_lib.books[index_of_most_popular_book].convert_to_string()<<endl;
	}

}

void library::three_most_fresh_books(library my_lib)
{

	cout<<"There are most fresh books: "<<endl<<endl;

	vector <int>::size_type size;
	size  = my_lib.books.size();

	int max = 0;
	int index;


	for(int j = 0; j < 3; j ++)
	{
		max = 0;
		for(int i = 0; i < size; i++)
		{
			if(my_lib.books[i].year > max)
			{
				max = my_lib.books[i].year;
				index = i;
			}
		}
		cout<<"\t"<<my_lib.books[index].convert_to_string()<<endl;
		my_lib.books[index].year = -100000;
	}
}

void library::save_to_file(string way, library my_lib)
{


	/////////////////////////////////////////////////////////////////////////////////////////////////////////////
	////WRITING ALL LIBRARY IN FILE//////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////

	ofstream in_library;
	in_library.open(way);

	vector <int>::size_type quantity_books, 
							quantity_readers,
							quantity_authors,
							quantity_orders;

	quantity_books    = my_lib.books.size();
	quantity_readers  = my_lib.readers.size();
	quantity_authors  = my_lib.authors.size();
	quantity_orders   = my_lib.orders.size();


	in_library<<quantity_books<<"\n";
	for(int i = 0; i < quantity_books; i++)
		in_library<<my_lib.books[i].convert_to_string();

	in_library<<"\n"<<quantity_readers<<"\n";
	for(int i = 0; i < quantity_readers; i++)
		in_library<<my_lib.readers[i].convert_to_string();

	in_library<<"\n"<<quantity_authors<<"\n";
	for(int i = 0; i < quantity_authors; i++)
		in_library<<my_lib.authors[i].convert_to_string();

	in_library<<"\n"<<quantity_orders<<"\n";
	for(int i = 0; i < quantity_orders; i++)
		in_library<<my_lib.orders[i].convert_to_string(my_lib.readers, my_lib.books)<<"\n";

	in_library.close();
}

library::~library()
{
}