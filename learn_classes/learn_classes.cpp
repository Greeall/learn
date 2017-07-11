// learn_classes.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <Windows.h>
#include "library.h"
#include <vector>
using namespace std;

int library::count_orders(4);

int main()
{	
	book books[3] = 
	{	
		book("Omon Ra", 2034, "fantastic", "Pelevin", 1850, 40),
		book("War and Peace", 210, "drama", "Tolstoy", 1668, 88),
		book("Empire V", 568, "fantastic", "Pelevin", 2000, 61)
	};
	
	//cout<<books[2].convert_to_string();


	author authors("fdsf", "sfds", 534);

	reader one("Vasya", "Dnepr", 45);
	reader two("Kolya", "Dnepr", 40);

	vector <order> orders;
	orders.push_back(order(one, books[1]));
	orders.push_back(order(two, books[0]));
	orders.push_back(order(two, books[1]));
	orders.push_back(order(one, books[0]));


	

	//books[1].print_reader(orders);

	//one.print_all_books(orders);

	library::buy_book(one, books[1], orders);


	return 0;
}

