#include<bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define INF INT_MAX
#define pii pair<int, int>
#define pb push_back
#define ll long long
#define LINF LLONG_MAX

vector<pair<pair<ll, ll>, ll>> edges;
int n, m;
vector<ll> dis;
vector<bool> vis;

bool bellman_ford(int start){
	
	dis.assign(n + 5, LINF);
	dis[start] = 0;
	
	for(int i=0; i<n; i++){
		
		for(auto node: edges){
			
			ll u = node.f.f, v = node.f.s;
			ll cost = node.s;
			
			if(dis[u] != LINF && dis[u] + cost < dis[v]){
				dis[v] = dis[u] + cost;
			}
			
		}
		
	}
	
	for(auto node: edges){			
		ll u = node.f.f, v = node.f.s;
		ll cost = node.s;		
		if(dis[u] != LINF && dis[u] + cost < dis[v]){
			return false;
		}			
	}
	
	return true;
	
}

bool isHaveNegativeCycle(){
	vis.assign(n + 5, false);
	
	for(int i=1; i<=n; i++){
//		if(vis[i]) continue;
		bool check = bellman_ford(i);
		if(!check) return true;
//		
//		for(int j=1; j<=n; j++){
//			if(dis[j] != LINF) vis[j] = true;
//		}
		
	}
	
	return false;
}

void solution(){
	
	edges.clear();
	dis.clear();
	
	cin >> n >> m;
	

	for(int i=0; i<m; i++){
		ll u, v, cost;
		cin >> u >> v >> cost;
		edges.pb({{u, v}, cost});
	}
	
	
	bool ans = isHaveNegativeCycle();
	
//	for(int i=1; i<=n; i++) cout << dis[i] << " ";
	
	cout << (ans? 1 : 0) << endl;
	
}


int main(){
	int test = 1;
	cin >> test; 
	while(test--) solution();
	
}
