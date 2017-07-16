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

	/*vector <book> books;
	books.push_back(book("Omon Ra", 400, "fantastic", "Pelevin", 1992, 100));    //0
	books.push_back(book("War and Peace", 3000, "drama", "Tolstoy", 1869, 100)); //1
	books.push_back(book("Sonata", 210, "drama", "Tolstoy", 1889, 99));          //2
	books.push_back(book("Empire V", 568, "fantastic", "Pelevin", 2006, 100));   //3
	books.push_back(book("Bayazet", 568, "history", "Pikul", 1961, 100));        //4
	books.push_back(book("Moonzund", 568, "history", "Pikul", 1970, 100));       //5
	books.push_back(book("Cruisers", 568, "history", "Pikul", 1985, 100));       //6
	*/
	
	
	//ofstream in_library;
	//in_library.open("books.txt");
	ifstream out_library;
	out_library.open("library.txt");

	//in_library<<name;
	//in_library<<new_line;
	//in_library.close();


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


	vector <author> authors;
	authors.push_back(author("Tolstoy", "Russian", 1828)); //0
	authors.push_back(author("Pelevin", "Russian", 1962)); //1
	authors.push_back(author("Pikul", "Russian", 1928));   //2
	

	vector <reader> readers;
	readers.push_back(reader("Vasya", "Dnepr", 45)); //0
	readers.push_back(reader("Kolya", "Dnepr", 40)); //1
	readers.push_back(reader("Masha", "Dnepr", 23)); //2
	readers.push_back(reader("Tanya", "Dnepr", 44)); //3

	
	vector <order> orders;
	orders.push_back(order(readers[3], books[1])); //0
	orders.push_back(order(readers[1], books[0])); //1
	orders.push_back(order(readers[1], books[3])); //2
	orders.push_back(order(readers[0], books[0])); //3
	orders.push_back(order(readers[2], books[5])); //4
	orders.push_back(order(readers[0], books[2])); //5
	orders.push_back(order(readers[3], books[6])); //6



	//books[1].print_reader(orders);  //understand why doesnt work

	//readers[2].print_all_books(orders);  //WORK + 

	//orders = library::buy_book(readers[1], books[1], orders); 

	//authors[1].most_popular_book(orders); // WORK +

	//library::three_most_popular_books(orders); //WORK + 

	//library::three_most_fresh_books(books); // WORK +

	//string lul = books[1].convert_to_string();  //WORK +
	

	return 0;
}

