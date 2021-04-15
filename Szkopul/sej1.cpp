#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll K_MAX = 250123;
ll n;
ll k;
ll m [ K_MAX ];
vector <ll> v;

int main() {
	ios_base::sync_with_stdio(0);

	cin >> n >> k;
	for ( ll i = 1; i <= k; i++ ) {
		cin >> m [ i ];
	}

	//wyliczam dzielniki liczby n
	ll i =1;
	for ( i = 1; i * i < n; i++ ) {
		if ( n % i == 0 ) {
			v.push_back(i);
			v.push_back( n /  i);
		}
	}
	if ( i * i == n ) {
		v.push_back(i);
	}

	//sortuje dzielniki
	sort(v.begin(), v.end());

	sort(m+1, m + k );
	reverse(m+1, m + k );



	for ( int i = 0; i < (int) v.size(); i++ ) {
		ll d = v [ i ];
		bool res = true;
		for ( ll j = 1; j < k; j++ ) {
			if ( m [ j ] % d == 0 ) {
				res = false;
				break;
			}
		}

		if ( m [ k ] % d != 0 ) {
			res = false;
		}
		if ( res ) {
			cout << n / d << '\n';
			break;
		}
	}


	return 0;
}
/*
42 5
28 31 10 38 24

*/