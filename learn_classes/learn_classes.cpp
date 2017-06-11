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
		int x;
		int y;

		square (int side1 = 1, int x1 =1, int y1 = 1)
		{
			a = side1;
			x = x1;
			y = y1;
		}

		double area(void)
		{
			return  a * a;
		}

		template <int N, int M>

		void paint(char (&canvas)[N][M])
		{
			for(int i = y; i < y + a; i++)
			{
				for(int j = x; j < x + a; j++)
				{
					if(i == y || j == x || i == y + a -1 || j == x + a - 1)
						if(canvas[i][j])
							canvas[i][j] = '*';
				}
			}
			
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
			

			for(int i = y; i < y + b; i++)
			{
				for(int j = x; j < x + a; j++)
				{
					if(j == x || i == y + b -1)
						canvas[i][j] = '*';  //рисуем катеты
				}
			}	

			
			/*double k = (float)b/(float)a;

			for(int i = y; i < y + b; i++)
			{
				int x_paint = (i-y)/k + x + 0.5;   //рисуем гипотенузу
				canvas[i][x_paint] = '*';
				
				}*/


			int error = 0;
			int deltaerr = b;


			if(a<b)
			{
				for(int i = y; i < y + b; i++)
				{
					deltaerr = a;
					canvas[i][x] = '*';
					error += deltaerr;

					if(2*error >= a)
					{
						x += 1;
						error -= b;
					}
				}
			}
			else
			{
				for (int i = x; i < x + a; i++)
				{
					if(x >= y + b)
						break;

					canvas[x][i] = '*';
					error += deltaerr;

					if(2*error >= a)
					{
						x += 1;
						error -= a;
					}
				}
			}
         
        
			
		}
	
			
};
class circle: public figure
{
	public:
		int r;
		int x;
		int y;

		circle (int radius = 1, int x1 = 1, int y1 = 1)
		{
			r = radius;
			x = x1;
			y = y1;
		}

		double area(void)
		{
			return 3.14 * r * r;
		}

		template <int N, int M>

		void paint(char (&canvas)[N][M])
		{
			int x1 = 0;
			int y1 = r;
			int delta = 1 - 2*r;
			int error = 0;

			while(y1>=0)
			{
				canvas[x + x1][y + y1] = '*';
				canvas[x + x1][y - y1] = '*';
				canvas[x - x1][y + y1] = '*';
				canvas[x - x1][y - y1] = '*';
				error = 2*(delta + y1) - 1;
				if((delta < 0) && (error <= 0))
				{
					delta += 2* ++x1 + 1;
					continue;
				}
				error = 2*(delta - x1) - 1;
				if((delta > 0) && (error > 0))
				{
					delta += 1 - 2* --y1;
					continue;
				}
				x1++;
				delta += 2*(x1 - y1);
				y1--;
			}
		}
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
	///figure* f[] = {
	//	&circle(3),
		//&rectangle(2,7),
	//	&square(9),
	//	&triangle(3, 4)
	//};

	char canvas[24][80];

	for(int i = 0; i < 24; i++)
		for(int j = 0; j < 80; j++)
			canvas[i][j] = ' ';

	square kvadrat(8,10,20); 
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

