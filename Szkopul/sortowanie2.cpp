#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N_MAX = 50123;
ll n;
ll pomoc[N_MAX], tab[N_MAX];

void mergee(ll poczatek, ll srodek, ll koniec)
{
    for (ll i = poczatek; i <= koniec; i++)
        pomoc[i] = tab[i];
    ll a = poczatek, b = srodek+1, i = poczatek;
    while(a <= srodek && b <= koniec)
    {
        if(pomoc[a] <= pomoc[b])
        {
            tab[i] = pomoc[a];
            a++;
        }
        else
        {
            tab[i] = pomoc[b];
            b++;
        }
        i++;
    }

    while(a <= srodek)
    {
        tab[i] = pomoc[a];
        a++;
        i++;
    }

    while(b <= koniec)
    {
        tab[i] = pomoc[b];
        b++;
        i++;
    }
}

void mergesort(ll poczatek, ll koniec)
{
    if(poczatek == koniec)
        return;
    ll srodek = (poczatek+koniec)/2;
    mergesort(poczatek, srodek);
    mergesort(srodek+1, koniec);
    mergee(poczatek, srodek, koniec);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (ll i = 1; i <= n; i++)
        cin >> tab[i];
    mergesort(1, n);

    for (ll i = 1; i <= n; i++)
        cout << tab[i] << " ";
    cout << '\n';


    return 0;
}

/*
4
3 2 5 2

*/
