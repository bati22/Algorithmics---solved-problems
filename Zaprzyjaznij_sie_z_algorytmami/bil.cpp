#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N_MAX = 100005;
ll z;
ll n;
ll t[N_MAX];
ll prefiks;
ll mpref;
ll sufiks;
ll msuf;
ll wynik;



int main()
{
    ios_base::sync_with_stdio(0);
    cin >> z;
    for (int j = 0; j < z; j++)
    {
        cin >> n;
        mpref = 0;
        msuf = 0;
        prefiks = 0;
        sufiks = 0;
        for (int i = 0; i < n-1; i++)
            cin >> t[i];
        for (int i = 0; i < n-1; i++)
        {
            prefiks += t[i];
            mpref = max(mpref, prefiks);
        }

        for (int i = n-2; i >= 0; i--)
        {
            sufiks += t[i];
            msuf = max(msuf, sufiks);
        }
        wynik = mpref+msuf;
        cout << wynik << endl;
    }


    return 0;
}

/*
2
5
3 5 5 2
3
-1 -1

*/













