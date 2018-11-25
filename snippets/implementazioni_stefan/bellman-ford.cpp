#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;

int main(void)
{
	int n, m;
	cin >> n >> m;
	
	vector<vii> grafo(n, vii());
	for(int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		grafo[a].push_back(ii(b, c));
	}
	
	vector<int> distanza(n, 1000000000);
	distanza[0] = 0;
	for(int k = 0; k < n-1; k++)
	{
		for(int u = 0; u < n; u++)
		{
			for(auto it = grafo[u].begin(); it != grafo[u].end(); it++)
			{
				distanza[it->first] = min(distanza[it->first], distanza[u]+(it->second));
			}
		}
	}
	
	bool has_negative_cycle = false;
	for(int u = 0; u < n; u++)
	{
		for(auto it = grafo[u].begin(); it != grafo[u].end(); it++)
		{
			if(distanza[u] + (it->second) < distanza[it->first])
			{
				has_negative_cycle = true;
				break;
			}
		}
		if(has_negative_cycle)
		{
			break;
		}
	}
	
	return 0;
}
