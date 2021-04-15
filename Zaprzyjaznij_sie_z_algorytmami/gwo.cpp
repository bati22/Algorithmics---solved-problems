#include <iostream>
#include <algorithm>
using namespace std;

const long long N_MAX = 1000005;
long long w[N_MAX];
long long n;
long long k;
long long maksymalnie;
long long ile;
long long wynik;

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> w[i];
    sort(w, w+n);

    for (int i = 0; i < n - k - 1; i++)
    {
        if (w[i] == w[i+1])
            ile++;
        else
            ile = 0;
        maksymalnie = max(maksymalnie, ile);
    }
    wynik = min(n, maksymalnie+k+1);
    cout << wynik << endl;

    return 0;
}

/*
6 2
3 3 2 3 4 5


*/
