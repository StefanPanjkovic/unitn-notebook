#include <bits/stdc++.h>

using namespace std;

class FenwickTree
{
	private:
		vector<int> ft;
		
	public:
		FenwickTree(const vector<int> &_V)
		{
			int N = _V.size();
			ft.assign(N+1, 0);
			for(int i = 0; i < N; i++)
			{
				for(int j = i+1; j < ft.size(); j += (j&(-j)))
				{
					ft[j] += _V[i];
				}
			}
		}
		
		int rsq(int b)
		{
			int somma = 0;
			
			while(b > 0)
			{
				somma += ft[b];
				b -= (b & (-b));
			}
			
			return somma;
		}
		
		int rsq(int a, int b)
		{
			if(a == 1)
			{
				return rsq(b);
			}
			else
			{
				return rsq(b) - rsq(a-1);
			}
		}
		
		void update_point(int index, int valore)
		{
			while(index < ft.size())
			{
				ft[index] += valore;
				index += (index & (-index));
			}
		}
};

int main(void)
{
	int N;
	cin >> N;
	
	vector<int> vettore;
	for(int i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		
		vettore.push_back(a);
	}
	FenwickTree albero(vettore);
	
	int Q;
	cin >> Q;
	for(int i = 0; i < Q; i++)
	{
		char comando;
		int a, b;
		cin >> comando >> a >> b;
		
		if(comando == 'S')
		{
			int x = albero.rsq(a+1, b+1);
			cout << x << endl;
		}
		else
		{
			vettore[a] += b;
			albero.update_point(a+1, b);
		}
	}
	
	return 0;
}
