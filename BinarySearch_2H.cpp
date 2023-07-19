#include<bits/stdc++.h>
using namespace std;
string x;
long long cnt[3] = {0},n[3],p[3];
long long r;
long long max(long long x, long long y)
{
	if(x>=y)
		return x;
	else
		return y;
}
bool good(long long mid)
{
	long long needb = max(0, mid*cnt[0] - n[0]);
	long long needs = max(0, mid*cnt[1] - n[1]);
	long long needc = max(0, mid*cnt[2] - n[2]);
	
	long long total = needb * p[0] + needs * p[1] + needc * p[2];
	return total <= r;
}
int main()
{
	cin >> x;
	for(int i=0; i<3; i++)
		cin >> n[i];
	for(int i=0; i<3; i++)
		cin >> p[i];
		
	cin >> r;
	
	for(int i=0; i<x.size(); i++)
		if(x[i] == 'B')
			cnt[0]++;
		else
			if(x[i] == 'S')
				cnt[1]++;
			else
				cnt[2]++;
				
	long long left = 0;
	long long right = 1e13;
	for(int i=0; i<200; i++)
	{
		long long m = (left + right)/2;
		if(good(m))
			left = m;
		else
			right = m;
	}
	cout << left << endl;
}
