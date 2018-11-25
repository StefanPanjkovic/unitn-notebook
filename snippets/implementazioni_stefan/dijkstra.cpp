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
		grafo[b].push_back(ii(a, c));
	}
	
	vector<int> distanza(n, 1000000000);
	distanza[0] = 0;
	priority_queue<ii, vector<ii>, greater<ii> > pq;
	pq.push(ii(0, 0));
	while(!pq.empty())
	{
		ii u = pq.top();
		pq.pop();
		if(u.first > distanza[u.second])
		{
			continue;
		}
		for(auto it = grafo[u.second].begin(); it != grafo[u.second].end(); it++)
		{
			if(distanza[u.second] + (it->second) < distanza[it->first])
			{
				distanza[it->first] = distanza[u.second] + (it->second);
				pq.push(ii(distanza[it->first], (it->first)));
			}
		}
	}
	
	return 0;
}
