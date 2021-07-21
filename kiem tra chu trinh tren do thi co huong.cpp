#include<bits/stdc++.h>
using namespace std;


#define pb push_back
#define ll long long
#define endl '\n'
#define mp make_pair
#define mt make_tuple
#define f first
#define s second
#define eb emplace_back
#define pii pair<int, int>
#define INF INT_MAX
#define LINF LLONG_MAX
#define all(vec) vec.begin(), vec.end()
#define FILEINPUT freopen("inputCNB.txt", "r", stdin);
#define FILEOUTPUT freopen("ouputCNB.txt", "w", stdout);
#define FOR(i, m, n) for(int i=(int)m; i<(int)n; i++)
#define FORD(i, m, n) for(int i=(int)m; i>=(int)n; i--)
#define FastIO cin.tie(0); ios_base::sync_with_stdio(false); cout.tie(0);
#define pq_max priority_queue<int>
#define pq_min priority_queue<int, vector<int>, greater<int>>
#define reset(A) memset(A, 0, sizeof(A))
/******* LIBRARY and DEFINE *******/


template<typename A, typename B> 
ostream& operator << (ostream &os, const pair<A, B> &p){
return os << "(" << p.f << " " << p.s << ")";};

template<typename T>
ostream& operator << (ostream &os, const vector<T> &vec){
os << "VECTOR: "; for(auto ele: vec) os << ele << " "; return os;};
/********** TEMPLATES *********/


const int MAXN = 1e7 + 5;
const ll mod = (ll)1e9 + 7;
/********** CONSTANT *********/

vector<vector<int>> adj;
vector<bool> vis;
map<pii, bool> cts;
map<int, bool> used;
vector<int> cnt;
bool ans = false;

void dfs(int u){
	vis[u] = true;
	for(auto x: adj[u]){
		if(vis[x]){
			if(cnt[u] - cnt[x] >= 2) ans = true;
		}
		else{
			cnt[x] = cnt[u] + 1;
			dfs(x);
		}
	}
}

void bfs(int u){
	queue<int> q;
	q.push(u);
	vis[u] = true;
	while(!q.empty()){
		int node = q.front(); q.pop();
		
		for(auto x: adj[node]){
			if(vis[x]){
				if(!cts[{node, x}]) ans = true;
				continue;
			}
			cts[{node, x}] = true;
			cts[{x, node}] = true;
			vis[x] = true;
			q.push(x);
		}
	}
}


void solution(){
	cts.clear();
	int n, m;
	cin >> n >> m;
	adj.clear();
	adj.resize(n + 1);
	cnt.assign(n + 1, 0);
	vis.assign(n + 1, false);
	
	FOR(i, 0, m){
		int x, y;
		cin >> x >> y;
		adj[x].pb(y);
//		adj[y].pb(x);
	}
	
	ans = false;
	FOR(i, 1, n + 1){
		if(ans) break;
		vis.assign(n + 1, false);
		dfs(i);
	}
	cout << (ans? "YES" : "NO") << endl;
}



/*******************************/
		
/******** MAIN FUNCTION *********/
int main(){
	
	#ifdef NGOCBINH
		FILEINPUT;
		FILEOUTPUT;
	#endif
	
	FastIO;
	
	int test = 1;	
	cin >> test; cin.ignore();	

	while(test--) solution();
	
	return 0;	
}
