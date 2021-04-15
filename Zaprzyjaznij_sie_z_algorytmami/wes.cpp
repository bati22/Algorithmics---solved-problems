#include <bits/stdc++.h>
using namespace std;

long long z;
long long n;
long long d;
long long a;
long long b;
long long wynik;

long long nwd(long long a, long long b)
{
    if (a%b==0)
        return b;
    return nwd(b, a%b);
}



int main()
{
    cin >> z;
    for (long long  i = 0; i < z; i++)
    {
        cin >> n >> d;
        a = max(n, d);
        b = min(n, d);
        wynik = n/nwd(a,b);
        cout << wynik << endl;
    }


    return 0;
}

