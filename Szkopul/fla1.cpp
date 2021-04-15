#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N_MAX = 500123;
ll n, X;
ll x[N_MAX];
ll a[N_MAX];
ll b[N_MAX];

ll up_now, down_now, x_now;
ll up_goal, down_goal;
ll result;

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n >> X;
    for (ll i = 1; i <= n; i++)
        cin >> x[i] >> a[i] >> b[i];

    for (ll i = 1; i <= n; i++)
    {
        up_goal = up_now + (x[i]-x_now);
        down_goal = down_now - (x[i]-x_now);

        //dla dolu
        if(down_goal > a[i])
            down_now = down_goal;
        else
        {
            down_now = a[i]+1;
            if(abs(down_now)%2 != abs(down_goal)%2)
                down_now++;
        }

        //cout << "Parzy: " << (-1)%2 << '\n';

        //dla gory
        if(up_goal < b[i])
            up_now = up_goal;
        else
        {
            up_now = b[i]-1;
            if(abs(up_now)%2 != abs(up_goal)%2)
                up_now--;
        }

        x_now = x[i];

       // cout << i << ": " << '\n';
       // cout << x_now << " " << down_now << " " << up_now << '\n';

        if(down_now > up_now)
        {
            cout << "NIE" << '\n';
            return 0;
        }
    }

    if(down_now > 0)
    {
        result += down_now;
        result += (x_now-down_now)/2;
    }

    else if(down_now < 0)
        result = (x_now+down_now)/2;

    else
        result = (x_now/2);

    cout << result << '\n';

    return 0;
}
/*
1 2
1 -1 1
Wynik: NIE

4 11
4 1 4
7 -1 2
8 -1 3
9 0 2
Wynik: 5


*/
