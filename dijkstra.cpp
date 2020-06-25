#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
const int maxn = 1e6+5, INF = 1e9+7;
vector<pair<int, int> > G[maxn];
queue<pair<int, int> > q;
vector<int> d;

void dijkstra(int start){
	q.push(mp(0, start));
	while(!q.empty()){
		pair<int, int> P = q.front();
		q.pop();
		P.first = -P.first;
		for(int i=0; i<G[P.second].size(); i++){
			int v = G[P.second][i].first;
			if(d[v] > d[P.second] + G[P.second][i].second){
				d[v] = d[P.second] + G[P.second][i].second;
				q.push(mp(-d[v], v));
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	int n, m;
	cin>>n>>m;
	for(int i=0; i<m; i++){
		int a, b, c;
		cin>>a>>b>>c;
		G[a].push_back(mp(b, c));
		G[b].push_back(mp(a, c));
	}
	d.resize(n+1, INF);
	d[1] = 0;
	dijkstra(1);
	for(int i=1; i<=n; i++)
		cout<<d[i]<<" ";
	cout<<endl;
}