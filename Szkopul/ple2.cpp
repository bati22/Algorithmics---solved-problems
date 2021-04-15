#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N_MAX = 1003;
const ll T_MAX = 23;
const ll A_MAX = 81;
const ll W_MAX = 800 * 1003;

ll T; // ilosc tlenu potrzebnego
ll A; // ilosc azotu potrzebnego

ll t [ N_MAX ]; //tlen i-tej butli
ll a [ N_MAX ]; //azot i-tej butli
ll w [ N_MAX ]; //waga i-tej butli

ll n; //liczba dostepnych butli
ll dp [ T_MAX ] [ A_MAX ];
ll sumW;


int main() {
	ios_base::sync_with_stdio(0);

	cin >> T;
	cin >> A;
	cin >> n;
	for ( ll i = 1; i <= n; i++ ) {
		cin >> t [ i ] >> a [ i ] >> w [ i ];
		sumW += w [ i ];
	}

	
	//inicjalizuje dp
	for ( ll i = 0; i <= T; i++ ) {
		for ( ll j = 0; j <= A; j++ ) {
			dp [ i ] [ j ] = sumW;
		}
	}
	dp [ 0 ] [ 0 ] = 0;
	



	for ( ll k = 1; k <= n; k++ ) {

		for ( ll j = T; j >= 0; j--) {
			for ( ll i = A; i >= 0; i-- ) {
				ll td = min( T, j + t [ k ] ); //dodatkowy tlen
				ll ad = min( A, i + a [ k ] ); //dodatkowy azot
				dp [ td ] [ ad ] = min( dp [ td ] [ ad ], dp [ j ] [ i ] + w [ k ] );
			}
		}
	}
	/*
	cout << "dp: " << '\n';
	for ( ll i = 0; i <= T; i++ ) {
		for ( ll j = 0; j <= A; j++ ) {
			cout << i << "," << j << ": " << dp [ i ] [ j ] << '\n';
		}
	}
	cout << '\n';
	*/


	cout << dp [ T ] [ A ] << '\n';


	return 0;
}
/*
5 60
5
3 36 120
10 25 129
5 50 250
1 45 130
4 20 119


*/