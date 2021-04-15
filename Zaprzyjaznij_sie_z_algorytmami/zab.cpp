#include <iostream>
using namespace std;

long long x;
long long s;
long long y;
long long dystans;
long long jumps;

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> x >> y >> s;
    dystans = y - x;
    jumps = dystans / s;
    if (dystans % s > 0)
        jumps++;
    cout << jumps << endl;



    return 0;
}
