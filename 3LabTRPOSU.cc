#include <iostream>
#include <math.h>
using namespace std;

class X;
class Y{
	friend void print(X*, Y*);
	friend void run(X*, Y*);
	
	public:
		Y(double Z) {
			z = Z;
		}
		~Y() {
			cout << "destructor Y" << endl;
		}
		
	private:
		double z;
};

class X{
	friend void print(X*, Y*);
	friend void run(X*, Y*);

	public:
		X(double X, double Y) {
			x = X;
			y = Y;
		}
		~X() {
			cout << "destructor X" << endl;
		}
	private:
		double x, y, h;
};

void run(X* funX, Y* funY){
	double firstTerm = (pow(funX->x,funX->y+1)+exp(funX->y-1))*
		(1+abs(funX->y-funX->x))/(1+funX->x*abs(funX->y-tan(funY->z)));
	double secondTerm = (pow(abs(funX->y-funX->x),2)/2)-
		(pow(abs(funX->y-funX->x),3)/3);
	funX->h = firstTerm + secondTerm;
}

void print(X* funX, Y* funY){
	cout << "Arguments: \nx=" << funX->x << "\ny=" << funX->y << "\nz=" << funY->z << endl;
	cout << "Result=" << funX->h << endl;
}


int main()
{
	X *funX = new X(2.444, 0.00869);
	Y *funY = new Y(-130);
	run(funX, funY);
	print(funX, funY);
	delete funX;
	delete funY;
	return 0;
}