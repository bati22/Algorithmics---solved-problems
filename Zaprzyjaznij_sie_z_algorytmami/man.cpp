#include <bits/stdc++.h>
using namespace std;

long long n;
long long wynik;

int main()
{
    cin >> n;
    if (n > 2)
        wynik = (n-1)*n+1;
    else
    {
        if (n == 2)
            wynik = 4;
        else
            wynik = 2;
    }
    cout << wynik << endl;


    return 0;
}
