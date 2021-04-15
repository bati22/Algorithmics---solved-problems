#include <iostream>
#include <cmath>
using namespace std;

const long long N_MAX = 1000005;
long long  w[N_MAX];
long long  n;
long long  a;
bool czy = true;


int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (long long  i = 0; i < n; i++)
    {
        cin >> a;
        if (a <= n)
            w[a]++;
        else
            czy = false;
    }

    for (long long  i = 1 ; i <= n; i++)
    {
        if (w[i] != 1)
        {
            czy = false;
        }
    }

    if (czy)
        cout << "TAK" << endl;
    else
        cout << "NIE" << endl;





    return 0;
}

/*
5
1 4 3 2 5

5
1 4 3 3 5

*/
