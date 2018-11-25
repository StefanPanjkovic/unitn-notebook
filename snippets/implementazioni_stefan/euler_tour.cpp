#include <bits/stdc++.h>

using namespace std;

typedef pair<int, bool> ib;
typedef vector<ib> vib;

int n, m;
vector<vib> grafo;
list<int> cyc;

void euler_tour(list<int>::iterator i, int u)
{
	for(auto it1 = grafo[u].begin(); it1 != grafo[u].end(); it1++)
	{
		if(it1->second)
		{
			it1->second = false;
			for(auto it2 = grafo[it1->first].begin(); it2 != grafo[it1->first].end(); it2++)
			{
				if((it2->first == u) && (it2->second))
				{
					it2->second = false;
					break;
				}
			}
			euler_tour(cyc.insert(i, u), it1->first);
		}
	}
}

int main(void)
{
	cin >> n >> m;
	grafo.assign(n, vib());
	for(int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		grafo[a].push_back(ib(b, true));
		grafo[b].push_back(ib(a, true));
	}
	
	euler_tour(cyc.begin(), 0);
	cyc.push_front(0);
	for(auto it = cyc.begin(); it != cyc.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	
	return 0;
}
