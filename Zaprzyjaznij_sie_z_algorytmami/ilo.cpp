#include <iostream>
#include <algorithm>
using namespace std;

const long long N_MAX = 100000;
long long z; // liczba zestawow
long long n; // liczba elementow ciagu
long long a[N_MAX];
long long iloczyn;

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> z;
    for (long long i = 0; i < z; i++)
    {
        cin >> n;
        for (long long j = 0; j < n; j++)
            cin >> a[j];
        sort (a+0, a+n);
        iloczyn = a[n-1]*a[n-2]*a[n-3];
        if (iloczyn < a[0]*a[1] *a[n-1])
            iloczyn = a[0]*a[1] *a[n-1];
        cout << iloczyn << endl;
    }






    return 0;
}

/*
2
5
1 4 3 2 5
4
-2 1 1 5


*/
