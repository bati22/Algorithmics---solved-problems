#include <bits/stdc++.h>
using namespace std;

const int N_MAX = 1000005;
int n, w;
int a[N_MAX];
int j;
int wynik;
int sznurek;

int main()
{
    cin >> n >> w;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
    {
        sznurek += a[i];
        if (sznurek >= w)
        {
            wynik++;
            sznurek = 0;
        }
    }

    cout << wynik << endl;

    return 0;
}


