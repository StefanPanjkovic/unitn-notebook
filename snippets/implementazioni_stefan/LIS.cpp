#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

int main(void)
{
    int n;
    cin >> n;
    
    int numeri[n];
    vector<ii> vettore;
    int precedente[n];
    for(int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        numeri[i] = a;
        
        int pos = -1;
        int sx = 0;
        int dx = vettore.size()-1;
        while(sx <= dx)
        {
            int m = (sx+dx)/2;
            if(vettore[m].first >= a)
            {
                if(sx == dx)
                {
                    pos = m;
                    break;
                }
                else
                {
                    dx = m;
                }
            }
            else
            {
                sx = m + 1;
            }
        }
        
        if(pos == -1)
        {
            if(vettore.empty())
            {
                precedente[i] = -1;
            }
            else
            {
                precedente[i] = vettore.back().second;
            }
            vettore.push_back(ii(a, i));
        }
        else
        {
            if(pos == 0)
            {
                precedente[i] = -1;
            }
            else
            {
                precedente[i] = vettore[pos-1].second;
            }
            vettore[pos] = ii(a, i);
        }
    }
    
    cout << vettore.size() << endl;
    int posizione = vettore.back().second;
    stack<int> pila;
    while(posizione != -1)
    {
        pila.push(numeri[posizione]);
        posizione = precedente[posizione];
    }
    while(!pila.empty())
    {
        cout << pila.top() << " ";
        pila.pop();
    }
    cout << endl;
    
    return 0;
}
