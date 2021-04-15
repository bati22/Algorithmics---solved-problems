#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N_MAX = 1000123;
bitset <N_MAX> t;
bool value;
ll n;
ll pref_1[N_MAX];
ll pref_0[N_MAX];
ll ilosc_1, ilosc_0;
ll result = LLONG_MAX;

int main() // 1 - prawy, 0 - lewy: 1 0 - tego szukam
{
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (ll i = 1; i <= n; i++)
    {
        cin >> value;
        if(value)
            t.flip(i);
    }

   /* cout << "Bitset: " << '\n';
    for (ll i = 1; i <= n; i++)
        cout << t[i] << " ";
    cout << '\n';
    cout << '\n';*/


    for(ll i = 1; i <= n; i++)
    {
        if(t[i])
        {
            ilosc_1++;
            pref_1[i] = 1;
        }

        else
        {
            ilosc_0++;
            pref_0[i] = 1;
        }

        pref_1[i] += pref_1[i-1];
        pref_0[i] += pref_0[i-1];
    }

    for (ll i = 1; i <= n-1; i++)
    {
        if(t[i]==1 && t[i+1]==0)
        {
            result = min(result, pref_0[i]+ilosc_1-pref_1[i]);
        }
    }

    result = min(result, ilosc_0);
    result = min(result, ilosc_1);

    cout << result << '\n';

    return 0;
}

/*
5
1 0 0 1 1
Wynik: 2



*/
