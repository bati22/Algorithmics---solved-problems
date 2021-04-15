#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N_MAX = 35;
const ll S_MAX = 1000123;

ll n;
ll k;
ll s;
ll m [ N_MAX ];
bitset <S_MAX> DP;
ll numberBlocks [ S_MAX ];
ll result;

int main() {
	ios_base::sync_with_stdio(0);

	cin >> n;
	cin >> k;
	cin >> s;

	//ustawiam liczbe blokow na wiecej niz mozliwe
	for (ll i = 1; i <= s; i++ )
		numberBlocks [ i ] = 10000;

	for ( ll i = 1; i <= n; i ++ )
		cin >> m [ i ];

	DP.set(0);
	for ( ll i = 1; i <= n; i++ ) {

		ll r = m [ i ];

		for ( ll j = s-r; j >= 0; j-- ) {
			if ( DP [ j ] == 1) {
				DP.set(j+r);
				numberBlocks [ j + r ] = min(numberBlocks[ j ] + 1, numberBlocks[ j + r ] );
				/*if ( j < r ) {
					DP.set(j+r);
					numberBlocks [ j + r ] = min(numberBlocks[ j ] + 1, numberBlocks[ j + r ] );
				}
				else {
					if ( !( DP [ j - r ] == 1 && numberBlocks [ j - r ] + 1 == numberBlocks [ j ] ) ) {
						DP.set(j+r);
						numberBlocks [ j + r ] = min(numberBlocks[ j ] + 1, numberBlocks[ j + r ] );
					}
				}*/
				
			}
		}
	}

	for ( ll i = s; i >= 0; i-- ) {
		if ( numberBlocks [ i ] <= k ) {
			result = i;
			break;
		}
	}

	cout << result << '\n';

	return 0;
}
