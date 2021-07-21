#include<bits/stdc++.h>
using namespace std;

#define pb push_back

vector<vector<int>> adj;
vector<bool> vis;
bool ans = false;
int n, m;


void dfs(int node, int count){
	vis[node] = true;
	if(count == n) ans = true;
	if(ans) return;
	for(auto x: adj[node]){
		if(vis[x]) continue;
		dfs(x, count + 1);
	}
	vis[node] = false;
}


void solution(){
	
	ans = false;
	adj.clear();
	
	cin >> n >> m;
	adj.resize(50);
	vis.assign(n + 5, false);
	
	for(int i=0; i<m; i++){
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
		
	for(int i=1; i<=n; i++){
		vis.assign(n + 5, false);
		dfs(i, 1);
	}
	
	cout << (ans? 1 : 0) << endl;
	
}

int main(){
	int test = 1;
	cin >> test;
	while(test--) solution();
}
