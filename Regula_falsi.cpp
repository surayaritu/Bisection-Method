

#include<bits/stdc++.h>
using namespace std;
#define MAX_ITER 1000000


double func(double x)
{
	return x*x*x - x - 11;
}

void regulaFalsi(double a, double b)
{
	if (func(a) * func(b) >= 0)
	{
		cout << "You have not assumed right a and b\n";
		return;
	}

	double c = a; // Initialize result
	c = (a*func(b) - b*func(a))/ (func(b) - func(a));
    cout<<"a         b      f(a)        f(b)      c         f(c)"<<endl;
    cout<<a<<"         "<<b<<"      "<<func(a)<<"          "<<func(b)<<"      "<<c<<"      "<<func(c)<<endl;
	for (int i=0; i < MAX_ITER; i++)
	{
		// Find the point that touches x axis

		// Check if the above found point is root
		if (fabs(func(c))<0.001)
			break;

		// Decide the side to repeat the steps
		else if (func(c)*func(a) < 0)
			b = c;
		else
			a = c;
        c = (a*func(b) - b*func(a))/ (func(b) - func(a));
        cout<<a<<"   "<<b<<"   "<<func(a)<<"      "<<func(b)<<"      "<<c<<"      "<<func(c)<<endl;
	}
	cout << "The value of root is : " << c;
}

int main()
{
	// Initial values assumed
	double a =2, b = 3;
	regulaFalsi(a, b);
	return 0;
}
