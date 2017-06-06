// learn_classes.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <Windows.h>
using namespace std;

class figure {
public:
	figure() {
	}
	virtual double area() = 0;
};



class rectangle: public figure
{
	public:
		int a;
		int b;
		int x;
		int y;

		rectangle (int side1 = 1, int side2 = 1, int dec_x = 1, int dec_y = 1)
		{
			a = side1;
			b = side2;
			x = dec_x;
			y = dec_y;
		}

		double area(void)
		{
			return a * b;
		}

		template <int N, int M>

		void paint(char (&canvas)[N][M])
		{
			for(int i = y; i < y + b; i++)
			{
				for(int j = x; j < x + a; j++)
				{
					if(i == y || j == x || i == y + b -1 || j == x + a - 1)
						canvas[i][j] = '*';
				}
			}
			
		}

};

class square: public figure
{
	public:
		int a;

		square (int side1 = 1)
		{
			a = side1;
		}

		double area(void)
		{
			return  a * a;
		}
};
class triangle: public figure
{
	public:
		int a;
		int b;
		int x;
		int y;


		triangle (int side1 = 1, int side2 = 1, int dec_x = 1, int dec_y = 1)
		{
			a = side1;
			b = side2;
			x = dec_x;
			y = dec_y;
		}

		double area(void)
		{
			return 0.5 * a * b;
		}

		template <int N, int M>

		void paint(char (&canvas)[N][M])
		{
			if(a > b)
			{
				int n = a/b;
				int shift = -n, buff;
				float procent = b*100/a;
				int modul;

				for(int i = y; i < y + b; i++)
				{
					for(int j = x; j < x + a; j++)
					{

						if(j == x || i == y + b -1)
							canvas[i][j] = '*';                //рисуем бока

						if(n >= 1)                             
						{
							if(procent < 100 && procent > 80)
								modul = a - b +  a*20/100;  
							else
								modul = 2;
							if(i%modul != 0)
							{
								buff = n;
								if((j > x + shift && (j <= x + shift + buff) && i!= y))
								{
									canvas[i][j] = '*';
								}
							}
							else
							{
								buff = n + 1;
								if((j > x + shift && (j <= x + shift + buff) && i!= y))
								{
									canvas[i][j] = '*';
								}
							}

						}
						else
						{
							buff = n;
							if((j > x + shift && (j <= x + shift + buff) && i!= y))
								canvas[i][j] = '*';
						}
					
					}
					shift += buff;
				}

			}
			if(a < b)
			{
				cout<<"aaa";
			}
		}



};
class circle: public figure
{
	public:
		int a;

		circle (int radius = 1)
		{
			a = radius;
		}

		double area(void)
		{
			return 3.14 * a * a;
		}

		/*static void set_radius(double r) {
			radius = r;
		}

		static double get_area() {
			return 3.14 * radius * radius;
		}*/
};


class learn{
public:
	static int counter;
	int a;

	learn (int number)
	{
		a = number;
	}

	int pow (void)
	{
		return a*a;
	}

	static int pow_counter(int number)
	{
		return number*number;
	}

	bool compare (learn *example)
	{
		return( this->pow() < example->pow() );
	}

};

int learn::counter = 5;

int main()
{	
	figure* f[] = {
		&circle(3),
		//&rectangle(2,7),
		&square(9),
		&triangle(3, 4)
	};

	triangle kvadrat(45,20,3,2); 
	

	char canvas[24][80];

	for(int i = 0; i < 24; i++)
		for(int j = 0; j < 80; j++)
			canvas[i][j] = ' ';

	kvadrat.paint(canvas);


	for(int i = 0; i < 24; i++)
	{
		for(int j = 0; j < 80; j++)
		{
			cout<<canvas[i][j];
		}
		cout<<endl;
	}

	


	return 0;
}

