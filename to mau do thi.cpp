#include<bits/stdc++.h>
using namespace std;

#define pb push_back

vector<vector<int>> adj;
int n, m, k;
vector<int> color;

bool check(){
	for(int i=1; i<=n; i++){
		for(auto x: adj[i]){
			if(color[i] == color[x]) return false;
		}
	}
	return true;
}

bool backTrack(int node){
	
	if(node == n + 1){
		return check();
	}
	
	for(int i=1; i<=k; i++){
		color[node] = i;
		if(node == n){
			if(check()) return true;
		}
		else if(backTrack(node + 1)) return true;
	}
	return false;
}

void solution(){
	
	cin >> n >> m >> k;
	
	adj.clear();
	color.clear();
	
	adj.resize(n + 5);
	color.resize(n + 5);
	
	for(int i=0; i<m; i++){
		int x, y;
		cin >> x >> y;
		adj[x].pb(y);
		adj[y].pb(x);
	} 
	
	
	cout << (backTrack(1)? "YES" : "NO") << endl;
	
	
}

int main(){
	int test = 1;
	cin >> test;
	while(test--) solution();
}
