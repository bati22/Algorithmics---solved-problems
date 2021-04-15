#include <bits/stdc++.h>
using namespace std;

const int N_MAX = 1000005;
int k = 1000000;
int n;
int a[N_MAX];
int ile[N_MAX];
int wynik[N_MAX];

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        ile[a[i]]++;
    for (int i = 1; i <= k; i++)
    {
        if (ile)
        {
            for (int j = i; j <= k; j+=i)
            {
                wynik[j] += ile[i];
            }
        }
    }

    for (int i = 0; i < n; i++)
        cout << n-wynik[a[i]] << " ";
    cout << endl;



    return 0;
}
