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
#define sqr(a) (1.0)*(a)*(a)
/******* LIBRARY and DEFINE *******/


template<typename A, typename B> 
ostream& operator << (ostream &os, const pair<A, B> &p){
return os << "(" << p.f << " " << p.s << ")";};

template<typename T>
ostream& operator << (ostream &os, const vector<T> &vec){
os << "VECTOR: "; for(auto ele: vec) os << ele << " "; return os;};
/********** TEMPLATES *********/

int n, m, u;
vector<vector<int>> adj;
vector<bool> vis;
//int back[1005] = {};
vector<int> back, cnt;
int vertex = 0;
bool check;
vector<pii> ans;

void dfs(int u){
	vis[u] = true;
		
	for(auto x: adj[u]){
		if(vis[x]) continue;
		ans.eb(u, x);
		dfs(x);
	}
}



void solution(){
//	reset(back);
	ans.clear();
	vertex = 0;
	cin >> n >> m >> u;
	adj.clear();
	adj.resize(n + 1);
	vis.assign(n + 5, false);
	back.assign(n + 5, false);
	cnt.assign(n + 5, 0);
	
	bool check = true;
	FOR(i, 0, m){
		int x, y;
		cin >> x >> y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	
	dfs(u);
	
	FOR(i, 1, n + 1) if(!vis[i]) check = false;
	
	if(!check){
		cout << -1 << endl;
		return;
	}
	
	for(auto p: ans) cout << p.f << " " << p.s << endl;
	
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
/********** I'mAlone ***********/
