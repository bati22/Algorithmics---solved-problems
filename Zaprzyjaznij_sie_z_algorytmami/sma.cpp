// Smakolyki
/*
Rozwiazanie
Zaznaczam rodzaj jako true. Jesli c[i+1] == true lub i == n, licze ze wzoru i dodaje do wyniku: ( 1+(i-j+1) )*(i-j+1)/2; czyszcze tablice boolowska, a takze j = i + 1.

Dowod
Rozpisuje liczbe dodawan do wyniku, w zaleznosci od dlugosci gasienicy:
0: 0
1: 1; 1
2: 3; 1+2
3: 6; 1+2+3
4: 10; 1+2+3+4
Widac, ze mam do czynienia z suma ciagu arytmetycznego, wiec moge uzyc wzoru: S = (a1+an)*n/2. W przypadku tego zadania:
a1 = 1
a2 = (i-j+1)
n = (i-j+1)
Pelny wzor: ( 1+(i-j+1) )*(i-j+1)/2


*/


#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N_MAX = 300005;
ll n;
ll m;
bool rodzaj[N_MAX];
ll wynik;
ll c[N_MAX];
ll j = 1;




int main()
{
    cin >> n >> m;
    for (ll i = 1; i <= n; i++)
        cin >> c[i];

    for (ll i = 1; i <= n; i++)
    {
        while (rodzaj[c[i]] != false)
        {
            rodzaj[c[j]] = false;
            j++;
        }
        rodzaj[c[i]] = true;
        wynik += (i-j+1);
    }
    cout << wynik << endl;

    return 0;
}


