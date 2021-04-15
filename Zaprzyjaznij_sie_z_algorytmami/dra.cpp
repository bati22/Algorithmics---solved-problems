#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N_MAX = 1000005;

ll t[N_MAX];
ll z;
ll s;
ll p;
ll p_2;
ll wynik;
ll potega = pow(2LL, 30);


int main()
{
    t[0] = 1;
    t[1] = 1;
    for (ll i = 2; i<= 1000000; i++)
        t[i] = (t[i-1] + t[i-2])%potega;
    /*cout << "Ciag: " << endl;
    for (int i = 1; i<= 100; i++)
        cout << t[i] << " ";
    cout << endl;*/


    cin >> z;
    for (ll i = 0; i < z; i++)
    {
        cin >> s >> p;
        p_2 = pow(2LL, p);
        wynik = t[s]%p_2;
        cout << wynik << endl;

    }


    return 0;
}

