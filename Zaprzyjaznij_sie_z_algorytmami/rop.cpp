#include <iostream>
using namespace std;


const int N_MAX = 300005;
int n; // pozycja, na ktora chce sie dostac
int m; // liczba lisci
int a[N_MAX]; // pozycja lisci
int my_time;
bool visited[N_MAX];
bool czy = false;

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
        cin >> a[i];

    for (int i = 0; i < m; i++)
    {
        my_time++;
        if (!visited[a[i]])
        {
            visited[a[i]] = true;
            n--;
        }
        if (n <= 0)
        {
            czy = true;
            break;
        }
    }

    if (czy)
        cout << my_time << endl;
    else
        cout << -1 << endl;


    return 0;
}

/*
5 8
1 3 1 4 2 3 5 4


*/
