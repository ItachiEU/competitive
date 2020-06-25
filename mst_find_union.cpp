#include <bits/stdc++.h>

using namespace std;

const int maxn=1e6+1;

int tab[maxn];

vector < pair < int, pair < int, int > > > G;

int Find(int x){
    if(tab[x]==x)
        return x;
    tab[x]=Find(tab[x]);
        return Find(tab[x]);
}

void Union(int x, int y){
 tab[Find(x)]=Find(y);
}

int main()
{
    int n, m, a, b, c;
    long long int wynik=0;
    scanf("%d%d", &n, &m);
    for(int i=1; i<=n; i++)
        tab[i]=i;


    for(int i=0; i<m; i++)
    {
        scanf("%d%d%d", &a, &b, &c);
        G.push_back(make_pair(c,make_pair(a,b))); //creating list of all the edges
    }
    sort(G.begin(), G.end()); //shortest first

    for(int i=0; i<m; i++)
    {
     if(Find(G[i].second.first)!=Find(G[i].second.second)) //connecting shortest edges that are in separate groups
     {
         Union(G[i].second.first, G[i].second.second);

         wynik+=G[i].first;
     }
    }
    printf("%lld", wynik);
}
