    #include <bits/stdc++.h>
    using namespace std;
    typedef long long ll;
    const ll N_MAX = 1000009;
    ll n, s;
    ll x[N_MAX];
    int result;
    map<ll, int>pref;
    ll prefiks;
    ll k;
    ll szukany_indeks;
     
    int main()
    {
    	ios_base::sync_with_stdio(0);
    	cin >> n >> s;
    	for (int i = 1; i <= n; i++)
    		cin >> x[i];
     
    	for (int j = 0; j <= 100; j++)
    	{
    		pref[0] = 0;
    		for (int i = 1; i <= n; i++)
    		{
    			prefiks += x[i];
    			if ( (prefiks&100) == j)
    			{
    				if (pref[prefiks]==0)
    					pref[prefiks]=i;
    				else
    					pref[prefiks] = min(pref[prefiks], i);
    			}
    			if (pref.count(prefiks-s))
    					result = max(result, i - pref[prefiks-s]);
    		}
    		prefiks = 0;
    		pref.clear();
    	}
     
     
    	if (result == 0)
    		cout << "BRAK" << endl;
    	else
    		cout << result << endl;
     
     
     
     
     
    	return 0;
    }