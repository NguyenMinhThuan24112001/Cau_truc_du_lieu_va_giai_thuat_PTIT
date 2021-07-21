#include<bits/stdc++.h>
using namespace std;


#define pb push_back
#define ll long long
#define endl '\n'
#define mp make_pair
#define mt make_tuple
#define f first
#define pll pair<long long, long long>
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

const int MAXN = 1e4 + 5;
const int mod = 1e9 + 7;

/***** CONSTANT ******/

vector<vector<int>> adj;
vector<int> vis;

int bfs(int u, int v){
	
	queue<pii> q;
	q.push({u, 0});
	vis[u] = true;
	
	while(!q.empty()){
		auto P = q.front(); q.pop();
		int node = P.f, step = P.s;
		if(node == v) return step;
		
		for(auto x: adj[node]){
			if(vis[x]) continue;
			q.push({x, step + 1});
			vis[x] = true;
		}
	}
	
	return -1;
	
}


void solution(){
	
	int n, m;
	cin >> n >> m;
	adj.clear();
	adj.resize(n + 1);
	vis.assign(n + 1, false);
	
	FOR(i, 0, m){
		int x, y;
		cin >> x >> y;
		adj[x].pb(y);
	}
	
 	int count = 0, ans = 0;
	FOR(i, 1, n + 1){
		FOR(j, 1, n + 1){
			if(i == j) continue;
			vis.assign(n + 1, false);
			int dis = bfs(i, j);
			if(dis == -1) continue;
			
			ans += dis;
			count++;
		}
	}
	cout << setprecision(2) << fixed << ans * 1.0 / count << endl;
	
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
