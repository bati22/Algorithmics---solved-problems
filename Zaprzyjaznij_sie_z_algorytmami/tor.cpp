#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N_MAX = 1000005;
ll n;
pair <ll, ll> domki[N_MAX];
ll odleglosc;
ll wynik;

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> domki[i].first >> domki[i].second;
    sort(domki, domki+n);
    odleglosc = domki[0].second;
    wynik = LLONG_MAX;
    for (int i = 1; i < n; i++)
    {
        odleglosc += (domki[i].first-domki[i-1].first);
        wynik = min(wynik, odleglosc+domki[i].second);
        odleglosc = min(odleglosc, domki[i].second);
    }
    cout << wynik << endl;



    return 0;
}

/*
3
1 1
2 2
3 3

7
2 1
2 8
8 3
3 1
1 3
2 2
2 3




*/

