#include<bits/stdc++.h>
using namespace std;

vector<vector<long long>> cost;

void SOLVE(){
	
	int n, m;
	cin >> n >> m;
	cost.assign(n + 5, vector<long long>(n + 5, INT_MAX));
	
	for(int i=1; i<=n; i++) cost[i][i] = 0;
		
	for(int i=0; i<m; i++){
		int u, v, value;
		cin >> u >> v >> value;		
		cost[u][v] = value;
		cost[v][u] = value;
	}
	
	//floyd
	for(int k=1; k<=n; k++){
		for(int i=1; i<=n; i++){
			for(int j=1; j<=n; j++){
				cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
			}
		}
	}
	
	int Q;
	cin >> Q;
	while(Q--){
		int x, y;
		cin >> x >> y;
		cout << cost[x][y] << endl;
	}
	
	
	
}

int main(){
	int test = 1;
//	cin >> test;
	while(test--) SOLVE();
}
