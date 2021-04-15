#include <iostream>
using namespace std;

const int N_MAX = 1000005;
int n;
long double result;
long double a;
long double x = 2.58238;


int main()
{
    ios_base::sync_with_stdio(0);
    cout.precision(2);
    cin >> n;
    cin >> a;
    result = a;

    for (int i = 1; i < n; i++)
    {
        cin >> a;
        if (a < result)
            result = a;
    }

    cout << fixed << result << endl;




    return 0;
}

/*
7
3 4 2 2 2 5 8


*/


