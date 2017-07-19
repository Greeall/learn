// learn_classes.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <Windows.h>
#include "library.h"
#include <vector>
#include <string>
#include <fstream>
using namespace std;

int main()
{	
	
	ifstream out_library;
	out_library.open("library.txt");

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////
	////READING BOOKS IN LIBRARY//////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////

	int size; 
	out_library>>size;    // quantity books in library

	string reading[7][6]; // (make array dynamic in future)

	for(int i = 0; i < size; i++)			//reading books
		for(int j = 0; j < 6; j ++)
			out_library>>reading[i][j];
	

	vector <book> books;
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

	vector <reader> readers;
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

	vector <author> authors;
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

	vector <order> orders;
	int reader_index;
	int book_index;
	
	for(int i = 0; i < size; i++)         // convert information in strings to objects of order
	{
		reader_index = atoi(reading[i][0].c_str());
		book_index = atoi(reading[i][1].c_str());

		orders.push_back(order(readers[reader_index],books[book_index]));   
	}


	books[1].print_reader(orders);  //understand why doesnt work

	//readers[2].print_all_books(orders);  //WORK + 

	//orders = library::buy_book(readers[1], books[1], orders); 

	//authors[1].most_popular_book(orders); // WORK +

	//library::three_most_popular_books(orders); //WORK + 

	//library::three_most_fresh_books(books); // WORK +

	//string lul = books[1].convert_to_string();  //WORK +


	out_library.close();

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////
	////WRITING ALL LIBRARY IN FILE//////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////


	ofstream in_library;
	in_library.open("library.txt");

	vector <int>::size_type quantity_books, 
							quantity_readers,
							quantity_authors,
							quantity_orders;

	quantity_books    = books.size();
	quantity_readers  = readers.size();
	quantity_authors  = authors.size();
	quantity_orders   = orders.size();


	in_library<<quantity_books<<"\n";
	for(int i = 0; i < quantity_books; i++)
		in_library<<books[i].convert_to_string();

	in_library<<"\n"<<quantity_readers<<"\n";
	for(int i = 0; i < quantity_readers; i++)
		in_library<<readers[i].convert_to_string();

	in_library<<"\n"<<quantity_authors<<"\n";
	for(int i = 0; i < quantity_authors; i++)
		in_library<<authors[i].convert_to_string();

	in_library<<"\n"<<quantity_orders<<"\n";
	for(int i = 0; i < quantity_orders; i++)
		in_library<<orders[i].convert_to_string(readers, books)<<"\n";

	in_library.close();


	return 0;
}

