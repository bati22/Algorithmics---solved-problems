#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll z;
ll a;
ll b;
bool wynik;

ll nwd(ll a, ll b)
{
    if (a%b==0)
        return b;
    return nwd(b, a%b);
}

int main()
{
    cin >> z;
    for (ll i = 0; i < z; i++)
    {
        cin >> a >> b;
        while (nwd(a,b) != 1)
            a /= nwd(a,b);
        wynik = (a==1);
        if (wynik)
            cout << "TAK" << endl;
        else
            cout << "NIE" << endl;
    }

    return 0;
}
