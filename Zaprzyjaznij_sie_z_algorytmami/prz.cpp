#include <iostream>
using namespace std;

const int N_MAX = 1000005;
int n; // liczba liczników
int m; // liczba naciœniêæ przycisku
int counter[N_MAX];
int button;
int max_value;
int maksimum;


int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        cin >> button;

        if (button == n+1)
            maksimum = max_value;
        else
        {
            if (counter[button] < maksimum)
                counter[button] = maksimum;
            counter[button]++;
            if (counter[button] > max_value)
                max_value = counter[button];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (counter[i] < maksimum)
            counter[i] = maksimum;
    }

    for (int i = 1; i <= n; i++)
        cout << counter[i] << " ";
    cout << endl;


    return 0;
}

/*
5 7
3 4 4 6 1 4 4


*/

