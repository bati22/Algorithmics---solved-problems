#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N_MAX = 1000005;
ll n;
ll t[N_MAX];
ll krotnosc;
ll wartosc;
ll kandydat=LLONG_MIN;
ll lider=LLONG_MIN;
ll wystapienia;
ll wystapienia_prefix;
ll wystapienia_sufix;
ll wynik;

bool sprawdz(ll kandydat)
{
    for (ll i = 0; i < n; i++)
        if (t[i] == kandydat)
            wystapienia++;
    return wystapienia > n/2;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (ll i = 0; i < n; i++)
        cin >> t[i];

    for (ll i = 0; i < n; i++)
    {
        if (krotnosc == 0)
        {
            wartosc = t[i];
            krotnosc = 1;
        }
        else
        {
            if (t[i] != wartosc)
                krotnosc--;
            else
                krotnosc++;
        }
    }
    if (krotnosc > 0)
        kandydat = wartosc;
    if (sprawdz(kandydat))
        lider = kandydat;

    if (lider == LLONG_MIN)
        cout << 0 << endl;
    else
    {
        for (int i = 0; i < n; i++)
        {
            if (t[i] == lider)
                wystapienia_prefix++;
            wystapienia_sufix = wystapienia - wystapienia_prefix;
            if (  (wystapienia_prefix > (i+1)/2) && (wystapienia_sufix > (n-i-1)/2)  )
                wynik++;
        }
        cout << wynik << endl;
    }



    return 0;
}

/*
6
4 3 4 4 4 2
*/
