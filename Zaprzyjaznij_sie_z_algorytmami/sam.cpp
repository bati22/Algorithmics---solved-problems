#include <iostream>
using namespace std;

const int N_MAX = 1000005;
long long n;
bool s[N_MAX];
long long on_east[N_MAX];
long long east_counter;
long long result;



int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (long long i = 0; i < n; i++)
        cin >> s[i];

    for (long long i = 0; i < n; i++)
    {
        if (!s[i])
            east_counter++;
        on_east[i] = east_counter;
    }

    for (long long i = 0; i < n; i++)
        if (s[i])
            result += on_east[i];
    cout << result << endl;





    return 0;
}

/*
5
0 1 0 1 1


*/



