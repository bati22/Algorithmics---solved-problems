#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N_MAX = 1000123;

ll n;
ll s [ N_MAX ];
ll pref [ N_MAX ];
ll res;

int main() {
	ios_base::sync_with_stdio(0);
	
	cin >> n;
	for ( ll i = 1; i <= n; i++ ) {
		cin >> s [ i ];
	}
	for ( ll i =n; i >= 1; i-- ) {
		pref [ i ] = s [ i ] + pref [ i + 1 ];
	}
	
	for ( ll i = 1; i <= n; i++ ) {
		if ( s [ i ] == 0 ) {
			res += pref [ i + 1 ];
		}
	}
	
	cout << res << '\n';
	
	return 0;
}
