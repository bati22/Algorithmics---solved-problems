#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N_MAX = 3000005;
ll n;
ll w[N_MAX];
ll maksimum;
ll wynik;

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (ll i = 0; i < n; i++)
        cin >> w[i];
    for (ll i = 0; i < n; i++)
    {
        maksimum = max(maksimum, w[i]);
        wynik = max(wynik, maksimum-w[i]);
    }
    cout << wynik << endl;




    return 0;
}

/*
5
6 7 5 4 2
*/













