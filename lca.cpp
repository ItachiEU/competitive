#include<bits/stdc++.h>
using namespace std;
const int maxn=3e4+5;
int visited[maxn], d[maxn], ancestor[maxn][19];
vector<int> G[maxn];
queue<int>q;
void BFS(int a)
{
    q.push(a);

    while(!q.empty())
    {
        int v=q.front();
        q.pop();
        visited[v]=1;
        for(int i=0; i<G[v].size(); i++)
        {
            if(visited[G[v][i]]==0)
            {
                q.push(G[v][i]);
                d[G[v][i]]=d[v]+1;
                ancestor[G[v][i]][0]=v;
            }
        }
    }
}
void make_ancestor(int n)
{
    for(int k=1; k<19; k++)
        for(int i=1; i<=n; i++)
        {
            ancestor[i][k]=ancestor[ancestor[i][k-1]][k-1];
        }
}
int lca(int a, int b)
{
    if(d[a]>d[b]) swap(a, b);
    for(int k=18; k>=0; k--)
    {
        if(d[ancestor[b][k]]>=d[a])
            b=ancestor[b][k];
    }
    if(a==b)
    return a;
    for(int k=18; k>=0; k--)
    {
        if(ancestor[a][k]!=ancestor[b][k])
        {
            a = ancestor[a][k];
            b = ancestor[b][k];
        }
    }
    return ancestor[a][0];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=0; i<n-1; i++)
    {
        int a, b;
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    d[1]=0;
    visited[1]=1;
    ancestor[1][0]=1
    BFS(1);
    make_ancestor(n);
    int q, res=0, last=1;
    cin>>q;
    for(int i=0; i<q; i++)
    {
        int a;
        cin>>a;
        if(i==0)
        {
            last=a;
            continue;
        }
        res+=d[a]+d[last]-2*d[lca(a,last)];
        last=a;
    }
    cout<<res<<endl;
}