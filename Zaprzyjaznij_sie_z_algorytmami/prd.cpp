//Praca domowa
/*
Rozwi¹zanie
Muszê znaleŸæ sumê najwiêkszego przedzia³u, który nie zawiera liczb w[i] oraz w[n-1]. Suma tego przedzia³u ma byæ pomniejszona o najmniejsza liczbê z przedzia³u. Znajdujê podci¹gi o maksymalnej sumie z lewej i z prawej strony, a wyniki wpisuje do dwoch tablic. Wykonujê pêtlê od 1 do n-2 w³¹cznie i wynikiem bêdzie suma max podci¹gu po lewej (i-1) i max podciagu po prawej (i+1).



*/


#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N_MAX = 300005;
ll n;
ll w[N_MAX];
ll pref[N_MAX];
ll suf[N_MAX];
ll mpref;
ll msuf;
ll wynik;
ll suma;



int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (ll i = 0; i < n; i++)
        cin >> w[i];
    mpref = w[1];
    msuf = w[n-2];
    pref[1] = mpref;
    suf[n-2] = msuf;

    for (ll i = 2; i < n-1; i++)
    {
        mpref = max(w[i], mpref+w[i]);
        pref[i] = mpref;
    }

    for (ll i = n-3; i > 0; i--)
    {
        msuf = max(w[i], msuf+w[i]);
        suf[i] = msuf;
    }

    /*cout << "Prefisky: " << endl;
    for (int i = 0; i < n; i++)
        cout << pref[i] << " ";
    cout << endl;

    cout << "Sufiksy: " << endl;
    for (int i = 0; i < n; i++)
        cout << suf[i] << " ";
    cout << endl;*/

    for (ll i = 1; i < n-1; i++)
    {
        suma = pref[i-1] + suf[i+1];
        if (suma > wynik)
            wynik = suma;
        suma = pref[i-1];
        if (suma > wynik)
            wynik = suma;
        suma = suf[i+1];
        if (suma > wynik)
            wynik = suma;
        suma = 0;
        if (suma > wynik)
            wynik = suma;
    }
    cout << wynik << endl;


    return 0;
}

/*
9
5 -3 8 -1 7 -4 5 -6 2

7
3 2 6 -1 4 5 1

4
-1 -1 -1 -1
*/
