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
#define pll pair<ll, ll>
#define INF INT_MAX
#define LINF LLONG_MAX
//#define testOUT 1
#define all(vec) vec.begin(), vec.end()
#define FILEINPUT freopen("inputCNB.txt", "r", stdin);
#define FILEOUTPUT freopen("ouputCNB.txt", "w", stdout);
#define FOR(i, m, n) for(int i=m; i<n; i++)
#define FORD(i, m, n) for(int i=m; i>=n; i--)
#define FastIO cin.tie(0); ios_base::sync_with_stdio(false); cout.tie(0);
#define pq_max priority_queue<int>
#define pq_min priority_queue<int, vector<int>, greater<int>>
#define reset(A) memset(A, 0, sizeof(A))
#define debug cerr << "debug: "
/******* LIBRARY and DEFINE *******/

template<typename A, typename B> 
ostream& operator << (ostream &os, const pair<A, B> &p){
return os << "(" << p.f << " " << p.s << ")";};

template<typename T>
ostream& operator << (ostream &os, const vector<T> &vec){
os << "VECTOR: "; for(auto ele: vec) os << ele << " "; return os;};
/********** TEMPLATES *********/

const int MAXN = 5005 + 5;
const int mod = 1e9 + 7;
/********** CONSTANT *********/

vector<vector<int>> adj(MAXN), path;
int back[MAXN] = {};

void road(int node){
	path[path.size() - 1].pb(node);
	if(back[node] == 1){
		path[path.size() - 1].pb(1);
		return;
	}
	road(back[node]);
}

void dfs(int u){
	if(adj[u].size() == 0){
		path.resize(path.size() + 1);
		road(u);
		return;
	}
	for(auto x: adj[u]){
		back[x] = u;
		dfs(x);
	}
}

void output(){
	sort(all(path), [&](vector<int> v1, vector<int> v2){
		return v1[0] < v2[0];
	});
	
	FOR(i, 0, path.size()){
		FORD(j, path[i].size() - 1, 0) cout << path[i][j] << ' ';
		cout << endl;
	}
	cout << endl;
	
}

void solution(){
	adj.clear();
	int n;
	cin >> n;
	adj.resize(n + 5);
	path.clear();
	reset(back);
	FOR(i, 0, n - 1){
		int x, y;
		cin >> x >> y;
		adj[x].pb(y);
	}
	
	dfs(1);
	
	output();
	
}


/*******************************/
		
/******** MAIN FUNCTION *********/
int main(){
	#ifdef testIN
		FILEINPUT;
	#endif
	#ifdef testOUT 
		FILEOUTPUT;
	#endif
	
	FastIO;
	
	int test = 1;	
	cin >> test; cin.ignore();	
	while(test--) solution();	
	return 0;	
}
/********** I'mAlone ***********/
