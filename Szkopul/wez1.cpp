#include <bits/stdc++.h>
using namespace std;

const int N_MAX = 123;
int t [ N_MAX ];
int n;

int main() {
	ios_base::sync_with_stdio(0);
	
	cin >> n;
	for ( int i = 1; i <= n; i++ ) {
		t [ i ] = i;
	}
	
	for ( int i = 1; i <= n; i++ ) {
		if ( i % 2 == 1 ) {
			for ( int j = 1; j <= n; j++ ) {
				cout << t [ j ] << " ";
			}
			cout << '\n';
		}
		else {
			for ( int j = n; j >= 1; j-- ) {
				cout << t [ j ] << " ";
			}
			cout << '\n';
		}
		
		for ( int j = 1; j <= n; j++ ) {
			t [ j ] += n;
		}
	}
	
	return 0;
}