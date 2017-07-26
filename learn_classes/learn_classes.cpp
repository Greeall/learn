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
	vector <book> books; 
	vector <order> orders; 
	vector <reader> readers;
	vector <author> authors; 

	library my_lib("library.txt");

	books = my_lib.books;
	readers = my_lib.readers;
	authors = my_lib.authors;




	//books[1].print_reader(my_lib);  

	//readers[2].print_all_books(my_lib);  

	//my_lib.buy_book(my_lib.readers[2], my_lib.books[3]); 

	//authors[1].most_popular_book(my_lib);  

	//library::three_most_popular_books(my_lib); 

	//library::three_most_fresh_books(my_lib); 



	my_lib.books = books;
	my_lib.readers = readers;
	my_lib.authors = authors;

	//library::save_to_file("library.txt", my_lib);
	



	


	return 0;
}

