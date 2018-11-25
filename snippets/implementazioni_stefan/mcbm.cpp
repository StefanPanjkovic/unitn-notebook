#include <bits/stdc++.h>

using namespace std;

int n, m, num;
vector<vector<int> > grafo;
vector<int> match;
vector<bool> visitato;

int augment(int nodo)
{
	if(visitato[nodo])
	{
		return 0;
	}
	visitato[nodo] = true;
	for(auto it = grafo[nodo].begin(); it != grafo[nodo].end(); it++)
	{
		if(match[*it]==-1 || augment(match[*it]))
		{
			match[*it] = nodo;
			return 1;
		}
	}
	return 0;
}

int main(void)
{
	cin >> n >> m >> num;
	grafo.assign(n, vector<int>());
	for(int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		grafo[a].push_back(b);
		grafo[b].push_back(a);
	}
	match.assign(n, -1);
	
	int mcbm = 0;
	for(int i = 0; i < num; i++)
	{
		visitato.assign(num, false);
		mcbm += augment(i);
	}
	cout << mcbm << endl;
	
	return 0;
}
