#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;

long double C;
bool good(long double m)
{
	return pow(m,2) + pow(m,0.5) >= C;	
}
int main()
{
	cin >> C;
	//find a number x such that x^2 + x^(1/2) = C;
	
	long double l = 0;
	long double r = 1e5;
	
	for(int i=0; i<150; i++)
	{
		long double m = (l + r)/2;
		if(good(m))
			r = m;
		else
			l = m;
	}
	cout << setprecision(15) << fixed << r << endl;
}
// 
