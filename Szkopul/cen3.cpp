#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N_MAX = 100123;

ll getSquareDistance( ll x, ll y ) {
	return x * x + y * y;
}

ll n; // liczba wielokatow
ll k; // wzrost zasiegu wiezy na metr wiezy
ll m; // liczba wierzcholkow i-tego domu
ll p; // abonament i-tego domu
ll x;
ll y;
ll maxSquareDistance;

pair<ll, ll> a [ N_MAX ];
ll result;

ll binsearch(ll l, ll r, ll R ) {
	ll squareR = R * R;
	ll mid = (l + r ) / 2;

//	cout << "mid: " << mid << '\n';

	if ( a [ mid ].first <= squareR ) {
		//ostatni
		if ( mid == n ) {
			return mid;
		}
		else {
			if ( a [ mid + 1 ].first <= squareR ) {
				return binsearch( mid+1, r, R );
			}
			else {
				return mid;
			}
		}
	}
	else {
		return binsearch( l, mid - 1, R );
	}
}

ll countCost( ll x ) {
	x--;
	return ( ( 1 + x ) * x ) / 2;
}

int main() {
	ios_base::sync_with_stdio(0);

	cin >> n >> k;
	for ( ll i = 1; i <= n; i++ ) {
		cin >> m >> p;
		maxSquareDistance = 0;
		for ( ll j = 1; j <= m; j++ ) {
			cin >> x >> y;
			maxSquareDistance = max(maxSquareDistance, getSquareDistance(x, y ) );
		}
		a [ i ].first = maxSquareDistance;
		a [ i ].second = p;
	}

	sort( a + 1, a + 1 + n );

	//suma prefiksowa
	for ( ll i = 2; i <= n; i++ ) {
		a [ i ].second += a [ i - 1 ].second;
	}

	for ( ll i = 1; i <= n; i++ ) {
		//czy moze byc wieza o zerowej wysokosci??????????????????????????????????
		ll squareR = a [ i ].first;
		ll R = sqrt(squareR);
		if ( R * R != squareR ) {
			R++;
		}
		// ogarnij koszt i promien
		ll towerHeight = R / k;
		if ( towerHeight * k != R ) {
			towerHeight++;
		}

		//cout << "promien: " << towerHeight * k << '\n';
		ll mid = binsearch(1, n, towerHeight * k );
	//	cout << "liczba domow: " << mid << '\n';
		ll resultNow = a [ mid ].second - countCost(towerHeight);
	//	cout << "zysk: " << resultNow << '\n';
	//	cout << "resultNow: " << resultNow << '\n';
		result = max(result, resultNow);
	//	cout << '\n';
	}

	cout << result << '\n';


	return 0;
}
/*
3 2
3 4 -2 0 -3 0 -3 1
6 5 1 2 2 3 2 2 3 4 1 4 1 3
3 1 -2 -8 0 -7 2 -8
*/