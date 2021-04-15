#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N_MAX = 500005;
ll n;
ll t[N_MAX];
bool flagi[N_MAX];
vector <ll> dzielniki;
ll d1;
ll d2;
bool czy;
ll licznik;
ll wynik;


int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (ll i= 0; i < n; i++)
        cin >> t[i];
    for (ll i = 1; i < n-1; i++)
        if (t[i] > t[i-1] && t[i] > t[i+1])
            flagi[i] = true;
    for (ll i=1; i*i <= n; i++)
        if (n%i==0)
        {
            dzielniki.push_back(n/i);
            dzielniki.push_back(i);
        }
    /*
    cout << "Flagi: " << endl;
    for (int i = 0; i < n; i++)
        if (flagi[i])
            cout << i << " ";
    cout << endl;
    cout << endl;


    cout << "Dzielniki: " << endl;
    for (ll i = 0; i < dzielniki.size(); i++)
        cout << dzielniki[i] << " ";
    cout << endl;
    cout << endl;
    */

    for (ll i = 0; i < dzielniki.size(); i++)
    {
        d1 = dzielniki[i];
        d2 = n/dzielniki[i];
        czy = true;
        for (ll j = 0; j < n; j+=d2)
        {
            licznik = 0;
            for (ll k = j; k < j+d2; k++)
                if (flagi[k])
                    licznik++;
            if (licznik == 0)
                czy = false;
        }
        if (czy)
            wynik = max(wynik, d1);
        //cout << "       wynik = " << wynik;
         //cout << endl;
    }
    //cout << "Wynik: " << endl;
    cout << wynik << endl;

    return 0;
}

/*
12
1 5 3 4 3 4 1 2 3 4 6 2

*/


















