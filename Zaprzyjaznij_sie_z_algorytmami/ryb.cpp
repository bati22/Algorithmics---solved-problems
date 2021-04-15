#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N_MAX = 1000005;
ll n;
ll fish_value[N_MAX];
ll fish_direction[N_MAX];
stack <ll> fish_stack;
ll result;

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (ll i = 0; i < n; i++)
        cin >> fish_value[i];
    for (ll i = 0; i < n; i++)
        cin >> fish_direction[i];

    for (ll i = 0; i < n; i++)
    {
        if (fish_direction[i])
            fish_stack.push(fish_value[i]);
        else
        {
            while(fish_stack.size() > 0 && fish_value[i] > fish_stack.top())
                fish_stack.pop();
            if (fish_stack.size() == 0)
                result++;
        }
    }
    result += fish_stack.size();
    cout << result << endl;



    return 0;
}

/*
5
4 3 2 1 5
0 1 0 0 0
*/


