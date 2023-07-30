#include<bits/stdc++.h>
using namespace std;
#define maxn 100005
#define ll long long
vector<ll> adj[maxn];
vector<ll> wt[maxn];
vector<ll> d(maxn);
vector<double> D(maxn);
ll visited[maxn] = {0};
ll m,n;
ll MIN = 1e5;
ll MAX = -1e5;
vector<ll> Path;
void inp()
{
	cin >> m >> n;
	for(int i=0; i<n; i++)
	{
		ll x,y;
		double z;
		cin >> x >> y >> z;
		adj[x].push_back(y);
		wt[x].push_back(z);
	}
	
}
topoSort(ll u, stack<ll> &st)
{
	visited[u] = 1;
	for(int i=0; i<adj[u].size(); i++)
		if(visited[ adj[u][i] ] != 1)
			topoSort( adj[u][i] , st);
	st.push(u);
}
void SetDistance(stack<ll> st)
{
	for(int i=1; i<=m; i++)
		d[i] = 1e5;
	d[1] = 0;
	while(!st.empty())
	{
		ll u = st.top();
		st.pop();
		for(int i=0; i < adj[u].size(); i++)
		{
			ll v = adj[u][i];
			double w = wt[u][i];
			if(d[u] + w < d[v])
				d[v] = d[u] + w;
 		}
	}
}
bool good(double mid, stack<ll> st)
{
	ll parent[maxn];
	vector<double> dtbc(maxn); //luu trung binh cong
//	ll cnt[maxn]; // luu so canh cua duong di
//	cnt[1] = 0;
	for(int i=1; i<=m; i++)
		dtbc[i] = 1e5;
	dtbc[1] = 0;
	while(!st.empty())
	{
		ll u = st.top();
		st.pop();
		for(int i=0; i<adj[u].size(); i++)
		{
			ll v = adj[u][i];
			ll w = wt[u][i];
			if(	dtbc[u] + w - mid < dtbc[v] )
			{
				dtbc[v] = dtbc[u] + w - mid;
				parent[v] = u;
			}
		}
	}
	if(dtbc[m] <= 0)
	{
		Path.clear();
		D.clear();
		ll t = m;
		while(t != 1)
		{
			Path.push_back(t);
			t = parent[t];
		}
		Path.push_back(1);
		reverse(Path.begin(), Path.end());
		
		for(int i=1; i<=m; i++)
			D[i] = dtbc[i];
		
		return true;
	}
	else
		return false;
}
int main()
{
	stack<ll> st;
	inp();
	topoSort(1,st); // tim thu tu topo
	SetDistance(st); // tim khoang cach ngan nhat binh thuong
	double l = -1;
	double r = 101;
	for(int i=0; i<150; i++)
	{
		double mid = (l + r)/2;
		if(good(mid,st))
			r = mid;
		else
			l = mid;
	}
//	cout << r << endl;
	cout << Path.size() - 1 << endl;
	for(int i=0; i<Path.size(); i++)
		cout << Path[i] << " ";
//	cout << endl;
//	for(int i=1; i<=m; i++)
//		cout << D[i] << " ";
	
	
	
}
