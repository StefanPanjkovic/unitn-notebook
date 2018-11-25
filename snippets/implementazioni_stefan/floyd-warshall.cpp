#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int n, m;
	cin >> n >> m;
	
	int matrice[n][n];
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(i == j)
			{
				matrice[i][j] = 0;
			}
			else
			{
				matrice[i][j] = 1000000000;
			}
		}
	}
	for(int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		matrice[a][b] = c;
		matrice[b][a] = c;
	}
	
	for(int k = 0; k < n; k++)
	{
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
			{
				matrice[i][j] = min(matrice[i][j], matrice[i][k]+matrice[k][j]);
			}
		}
	}
	
	return 0;
}
