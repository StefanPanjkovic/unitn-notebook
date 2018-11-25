#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

int n, dim;
vector<ii> vettore;
int memo[100][1000];
vector<int> presi;

void trova_soluz(int pos, int peso_rimasto)
{
	if(pos == n)
	{
		return;
	}
	if(memo[pos][peso_rimasto] == memo[pos+1][peso_rimasto])
	{
		trova_soluz(pos+1, peso_rimasto);
		return;
	}
	presi.push_back(pos);
	trova_soluz(pos+1, peso_rimasto-vettore[pos].second);
}

int riempi(int pos, int peso_rimasto)
{
	if(pos == n)
	{
		memo[pos][peso_rimasto] = 0;
		return 0;
	}
	if(memo[pos][peso_rimasto] != -1)
	{
		return memo[pos][peso_rimasto];
	}
	
	memo[pos][peso_rimasto] = riempi(pos+1, peso_rimasto);
	if(vettore[pos].second <= peso_rimasto)
	{
		int a = vettore[pos].first + riempi(pos+1, peso_rimasto-vettore[pos].second);
		memo[pos][peso_rimasto] = max(memo[pos][peso_rimasto], a);
	}
	return memo[pos][peso_rimasto];
}

int main(void)
{
	cin >> n >> dim;
	for(int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		vettore.push_back(ii(a, b));
	}
	memset(memo, -1, sizeof(memo));
	
	int risultato = riempi(0, dim);
	trova_soluz(0, dim);
	cout << risultato << endl;
	for(int i = 0; i < presi.size(); i++)
	{
		cout << presi[i] << " ";
	}
	cout << endl;
	
	return 0;
}
