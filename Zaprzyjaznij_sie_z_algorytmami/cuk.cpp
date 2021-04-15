#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N_MAX = 1000005;
ll n;
ll c[N_MAX];
ll minimum;
bool zamien[N_MAX];
ll poprzedni;
ll wynik;


int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (ll i = 0; i < n; i++)
        cin >> c[i];
    minimum = c[n-1]+1;
    for (ll i = n-1; i >= 0; i--)
    {
        if (c[i] < minimum)
        {
            minimum = c[i];
            zamien[i] = true;
        }
    }

    poprzedni = -1;
    for (int i = 0; i < n; i++)
    {
        if (zamien[i])
        {
            wynik += (i-poprzedni)*c[i];
            poprzedni = i;
        }
    }

    cout << wynik << endl;



    return 0;
}

/*
4
5 2 4 3
*/



