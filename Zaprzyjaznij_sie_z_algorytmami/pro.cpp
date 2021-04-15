#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N_MAX = 1000020;
ll t[N_MAX];
ll w[N_MAX];
ll pref[N_MAX];
ll n;
ll i;
ll r;
ll wynik;
ll licznik;
ll indeks1;
ll indeks2;

ll znajdz_promien(ll r_min, ll r_max)
{


    r = (r_min+r_max)/2LL;
    indeks1 = max(1LL, i-r);
    indeks2 = min(n, i+r);
    ll suma1 = pref[indeks2] - pref[indeks1-1];
    r--;
    indeks1 = max(1LL, i-r);
    indeks2 = min(n, i+r);
    ll suma2 = pref[indeks2] - pref[indeks1-1];
    r++;
    /*cout << "i: " << i << endl;
    cout << "r: " << r << endl;
    cout << "suma1: " << suma1 << endl;
    cout << "suma2: " << suma2 << endl;
    cout << "indeks1: " << indeks1 << endl;
    cout << "indeks2: " << indeks2 << endl;
    cout << endl;*/
    if (suma1 < w[i])
    {
        znajdz_promien(r+1, r_max);
    }

    else
    {
        if (suma2 < w[i])
        {
            //cout << endl;
            //cout << endl;
            return r;
        }

        else
            znajdz_promien(r_min, r);
    }


}

int main()
{
    cin >> n;
    for (ll i = 1; i <= n; i++)
        cin >> t[i];
    for (ll i = 1; i <= n; i++)
        cin >> w[i];
    for (ll i = 1; i <= n; i++)
        pref[i] = pref[i-1]+t[i];

    /*cout << "Prefiksy: " << endl;
    for (ll i = 1; i <= n; i++)
        cout << pref[i] << " ";
    cout << endl;*/

    for (i = 1; i <= n; i++)
    {
        if (pref[n] < w[i])
            wynik = -1;
        else if (t[i] >= w[i])
            wynik = 0;
        else
            wynik = znajdz_promien(1, n);
        cout << wynik << " ";

    }


    return 0;
}



