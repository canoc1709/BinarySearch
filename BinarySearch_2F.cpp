#include<iostream>
using namespace std;

string t,p;
int a[200005];

bool good(int mid)
{
	int del[200005] = {0};
	for(int i=0; i<mid; i++)
		del[ a[i] - 1 ] = 1;

	int j = 0;
	for(int i = 0; i<t.size(); i++)
	{
		if(del[i] != 1 && t[i] == p[j])
			j++;	
	}
	return j == p.size();
}
int main()
{
	cin >> t >> p;
	int n = t.size();
	for(int i=0; i<n; i++)
		cin >> a[i];
	
	int l = 0; 
	int r = 200000;
	for(int i=0; i<100; i++)
	{
		int m = (l + r)/2;
		if(good(m))
			l = m;
		else
			r = m;
	}
	cout << l << endl;
	
}
