#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<vector<int> > grafo;
int matrice[300][300];

int max_flow, f, sorgente, pozzo;
vector<int> p;

void flusso(int nodo, int min_edge)
{
	if(nodo == sorgente)
	{
		f = min_edge;
	}
	else if(p[nodo] != -1)
	{
		flusso(p[nodo], min(min_edge, matrice[p[nodo]][nodo]));
		matrice[p[nodo]][nodo] -= f;
		matrice[nodo][p[nodo]] += f;
	}
}

int main(void)
{
	cin >> n >> m >> sorgente >> pozzo;
	grafo.assign(n, vector<int>());
	memset(matrice, 0, sizeof(matrice));
	for(int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		
		grafo[a].push_back(b);
		grafo[b].push_back(a);
		matrice[a][b] = c;
	}
	
	max_flow = 0;
	for(;;)
	{
		f = 0;
		bitset<300> visitato;
		visitato[sorgente] = true;
		queue<int> coda;
		coda.push(sorgente);
		p.assign(n, -1);
		
		while(!coda.empty())
		{
			int corrente = coda.front();
			coda.pop();
			if(corrente == pozzo)
			{
				break;
			}
			
			for(auto it = grafo[corrente].begin(); it != grafo[corrente].end(); it++)
			{
				if((matrice[corrente][*it] > 0) && (!visitato[*it]))
				{
					visitato[*it] = true;
					p[*it] = corrente;
					coda.push(*it);
				}
			}
		}
		
		flusso(pozzo, 1000000000);
		if(f == 0)
		{
			break;
		}
		max_flow += f;
	}
	cout << max_flow << endl;
	
	return 0;
}
