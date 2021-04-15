#include <bits/stdc++.h>
using namespace std;
const int N_MAX = 2123;
int n;
bool t[N_MAX][N_MAX];
int G[N_MAX];

stack <pair<int, int>> stos;
pair <int, int> para;

int x_1, x_2, y_1, y_2;
int result;

int previous_k;
int x, y;

void oblicz_result()
{
	x_1 = stos.top().first;
	x_2 = x-1;
	y_1 = y-stos.top().second+1;
	y_2 = y;	

	int result_now = (abs(x_2-x_1)+1)*(abs(y_2-y_1)+1);
	result = max(result, result_now);

	/*if(true) // wyświetlam
	{
		cout << x_1 << " " << x_2 << "      " << y_1 << " " << y_2 << '\n';
		cout << "result_now: " << result_now << '\n';
	}*/

	stos.pop();
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin >> n;
	for (int y = 0; y <= n+1; y++)
		for (int x = 0; x <= n+1; x++)
			t[y][x]=true;

	for (int y = 1; y <= n; y++)
		for(int x = 1; x <= n; x++)
			cin >> t[y][x];

	for (y = 0; y <= n+1; y++)
	{
		for (x = 0; x <= n+1; x++)
		{
			/*if(true) // wyświetlam
			{
				cout << y << ":   " << x << ": " << '\n';
			}*/



			previous_k = x;

			if(t[y][x]==1)
				G[x] = 0;
			else
				G[x]++;

			if(G[x]==0)
			{
				while(!stos.empty())
				{
					oblicz_result();
				}

			}

			else
			{
				while(!stos.empty() && stos.top().second > G[x])
				{
					previous_k = stos.top().first;
					oblicz_result();
				}

				if(stos.empty() || stos.top().second < G[x])
				{
					para.first = previous_k;
					para.second = G[x];
					stos.push(para);
				}
			}

			/*if(true) // wyświetlam
			{
				if(!stos.empty())
					cout << "stos: " << stos.top().first << " " << stos.top().second << '\n';
				else
					cout << "stos: pusty" << '\n';
				cout << '\n';
			}*/
		}
	}

	cout << result << '\n';




	return 0;
}

/*
5
0 1 0 1 0
0 0 0 0 0
0 0 0 0 1
1 0 0 0 0
0 1 0 0 0


8
0 0 0 0 1 0 0 0
1 0 0 1 0 0 0 0
0 0 0 0 0 1 0 0
0 1 0 0 0 0 1 1
0 0 0 0 0 0 1 0
0 0 0 0 0 0 0 0
0 1 0 0 0 0 0 0
0 0 0 0 0 1 0 0


*/