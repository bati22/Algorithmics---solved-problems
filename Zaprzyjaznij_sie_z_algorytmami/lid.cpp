#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N_MAX = 500005;
ll n;
ll a[N_MAX];
ll pref[N_MAX];
ll lider;
ll kandydat;
ll krotnosc;
ll wartosc;

bool sprawdz(ll kandydat)
{
    ll ile = 0;
    for (ll i = 0; i < n; i++)
        if (pref[i] == kandydat)
            ile++;
    return ile > n/2;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    for (ll i = 0; i < n; i++)
    {
        if (krotnosc == 0)
        {
            krotnosc = 1;
            wartosc = a[i];
        }

        else
        {
            if (wartosc != a[i])
                krotnosc--;
            else
                krotnosc++;
        }
        if (krotnosc>0)
            pref[i] = wartosc;
        else
            pref[i]=LLONG_MAX;
    }

    sort(pref, pref+n);
    kandydat = pref[n/2];
    lider = LLONG_MAX;
    if (sprawdz(kandydat))
        lider = kandydat;
    if (lider == LLONG_MAX)
        cout << "NIE" << endl;
    else
        cout << lider << endl;

    return 0;
}

/*
9
3 4 5 3 3 1 3 3 3
*/











