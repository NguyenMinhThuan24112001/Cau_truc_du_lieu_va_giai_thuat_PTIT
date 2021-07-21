#include <bits/stdc++.h>
 
using namespace std;
const int N = 3005;
vector<vector<int>> adj;
vector<bool> vis;
int n,m,k,d = 0;
 
vector<pair<int, int>> ans;
 
void Relnit(){
    vis.assign(n + 5, false);
}
 
void TreeBFS(int u){
    queue<int> arr;
    vis[u] = true;
    arr.push(u);
    while (!arr.empty())
    {
        int s=arr.front();arr.pop();
        for(auto node: adj[s])
        {
            if(vis[node]) continue;
            vis[node] = true;
            ans.emplace_back(s, node);
            arr.push(node);
        }
    }
}
 
void TreeGraphBFS(){
    Relnit();
    TreeBFS(k);
    bool possible = true;
    for(int i=1; i<=n; i++) if(!vis[i]) possible = false;
    if(!possible) cout << -1 << endl;
    else 
    {
        for(auto p: ans) cout << p.first << " " << p.second << endl;
    }

}
 
int main(){
	int t;
	cin>>t;
	while (t--) 
	{
	ans.clear();
	cin>>n>>m>>k;
	adj.clear();
	adj.resize(n + 5);
	for (int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	TreeGraphBFS();
	}
	return 0;
}
