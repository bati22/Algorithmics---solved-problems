#include <iostream>
using namespace std;

const int N_MAX = 500005;
int n;
bool written[N_MAX];
int x;

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n;

    for (int i = 0; i < n-1; i++)
    {
        cin >> x;
        written[x] = true;
    }

    for (int i = 1; i <= n; i++)
    {
        if (!written[i])
        {
            cout << i << endl;
            break;
        }
    }


    return 0;
}
