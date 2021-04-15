#include <bits/stdc++.h>
using namespace std;

const int N_MAX = 500005;
int n;
int k;
pair <int, int> parz[N_MAX];
pair <int, int> nparz[N_MAX];

int wynik;
int max_zostawic = INT_MIN;
int czy;

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <=  n; i++)
    {
        cin >> k;
        nparz[i].second=i;
        parz[i].second=i;
        if (i%2==0)
            parz[k].first++;
        else
            nparz[k].first++;
    }
    sort(nparz+1, nparz+n+1);
    sort(parz+1, parz+n+1);
    if (parz[n].second != nparz[n].second)
        max_zostawic = max(max_zostawic, parz[n].first+nparz[n].first);
    if (parz[n].second != nparz[n-1].second)
        max_zostawic = max(max_zostawic, parz[n].first+nparz[n-1].first);
    if (parz[n-1].second != nparz[n].second)
        max_zostawic = max(max_zostawic, parz[n-1].first+nparz[n].first);
    wynik = n-max_zostawic;
    cout << wynik << endl;

    return 0;
}

/*
6
1 2 3 1 4 2

6
1 1 1 1 1 2
*/










