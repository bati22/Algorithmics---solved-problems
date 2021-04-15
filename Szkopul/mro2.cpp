#include <bits/stdc++.h>
using namespace std;
const int N = 5005;
const int inf = 1e9;

int n, a, b, k, l;
vector<int> g[N];
int cand[N]; // numer mrówki, która pierwsza dojdzie do i-tego wierzchołka
int timecand[N]; // czas w którym dojdzie
int ant[N]; // gdzie jest i-ta mrówka
int vertex[N]; // numer mrówki na i-tym wierzchołku
int timeant[N]; // czas, przez który i-ta mrówka będzie szła
int parent[N];
int result[N];

void dfs1(int v, int p) {
    parent[v] = p;
    if(vertex[v]) {
        cand[v] = vertex[v];
        timecand[v] = 0;
        return;
    }
    cand[v] = 0;
    timecand[v] = inf;
    for(int w : g[v]) if(w != p) {
        dfs1(w, v);
        if(cand[w] && timecand[v] + (cand[v] > cand[w]) > timecand[w] + 1) {
            cand[v] = cand[w];
            timecand[v] = timecand[w] + 1;
        }
    }
    for(int w : g[v]) if(w != p) {
        if(cand[w] && cand[w] != cand[v]) {
            timeant[cand[w]] = timecand[v];
            if(timecand[w] + 1 == timecand[v]) {
                timeant[cand[w]]--;
            }
        }
    }
}

void dfs2(int v, int p, int tajm) {
    if(vertex[v]) {
        timeant[vertex[v]] = min(timeant[vertex[v]], tajm);
        return;
    }
    for(int w : g[v]) if(w != p) {
        if(w != p && cand[w]) {
            if(cand[v] != cand[w]) dfs2(w, v, min(tajm, timecand[v]));
            else dfs2(w, v, tajm);
        }
    }
}


int main()
{
    scanf("%d", &n);
    for (int i =0 ; i < n-1; i++)
    {
        scanf("%d%d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    scanf("%d", &k);
    for (int i = 1; i <= k; i++)
    {
        scanf("%d", ant+i);
        vertex[ant[i]] = i;
    }
    scanf("%d", &l);
    while(l--) {
        scanf("%d", &b);
        
        for(int a = 1; a <= k; a++) {
            timeant[a] = 0; 
        }
        dfs1(b, 0);
        dfs2(b, 0, inf);
        timeant[cand[b]] = timecand[b];

        for(int v = 1; v <= n; v++) {
            vertex[v] = 0;
        }
        for(int a = 1; a <= k; a++) {
            while(timeant[a]--) {
                ant[a] = parent[ant[a]];
            }
            //cout << a << ": " << ant[a] << endl;
            vertex[ant[a]] = a;
        }
        result[vertex[b]]++;
    }
    for (int i = 1; i <= k; i++)
        printf("%d %d\n", ant[i], result[i]);
    return 0;
}