#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll p;
ll i;
ll d1;
ll d2;
ll wynik = LONG_MAX;
ll ob;



int main()
{
    ios_base::sync_with_stdio(0);
    cin >> p;

    wynik = 2 * (p+1);
    for (i = 2; i*i <= p; i++)
    {
        if (p%i==0)
        {
            d1 = i;
            d2 = p/d1;
            ob = (d1+d2)*2;
            wynik = min(ob, wynik);
        }
    }
    cout << wynik << endl;


    return 0;
}

/*


*/

















