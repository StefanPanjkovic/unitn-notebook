#include <bits/stdc++.h>

using namespace std;

int n;
int matrice[20][20];
int memo[20][100000];
vector<int> soluz;

void trova_soluz(int pos, int mask)
{
	if(mask == (1<<n)-1)
	{
		soluz.push_back(0);
		return;
	}
	for(int i = 0; i < n; i++)
	{
		if(!(mask & (1<<i)))
		{
			if(memo[pos][mask] == matrice[pos][i] + memo[i][mask | (1<<i)])
			{
				soluz.push_back(i);
				trova_soluz(i, mask | (1<<i));
				break;
			}
		}
	}
}

int tsp(int pos, int mask)
{
	if(memo[pos][mask] != -1)
	{
		return memo[pos][mask];
	}
	if(mask == (1<<n)-1)
	{
		memo[pos][mask] = matrice[pos][0];
		return matrice[pos][0];
	}
	
	memo[pos][mask] = 1000000000;
	for(int i = 0; i < n; i++)
	{
		if(!(mask & (1<<i)))
		{
			int a = matrice[pos][i] + tsp(i, mask | (1<<i));
			memo[pos][mask] = min(memo[pos][mask], a);
		}
	}
	return memo[pos][mask];
}

int main(void)
{
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cin >> matrice[i][j];
		}
	}
	memset(memo, -1, sizeof(memo));
	
	int risultato = tsp(0, 1);
	soluz.push_back(0);
	trova_soluz(0, 1);
	
	cout << risultato << endl;
	for(int i = 0; i < soluz.size(); i++)
	{
		cout << soluz[i] << " ";
	}
	cout << endl;
	
	return 0;
}
