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


const int MAXN = 1e5 + 5;
const ll mod = (ll)1e9 + 7;
/********** CONSTANT *********/


vector<vector<int>> adj;
bool ans = true;


void dfs(){
	
}

void solution(){
	ans = true;
	adj.clear();
	
	int n, m;
	cin >> n >> m;
	
	adj.resize(n + 5);
	
	FOR(i, 0, m){
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	
	FOR(i, 1, n + 1){
		for(auto x: adj[i]){
			if(x == i) continue;
			for(auto y: adj[x]){
				if(y == i || y == x) continue;
				bool possible = false;
				for(auto node: adj[y]){
//					cout << i << " " << x << " " << y << " " << node << endl;
					if(node == i){
						possible = true;
						break;
					}
				}
				if(!possible){
//					cout << i << " " << x << " " << y << endl;
					ans = false;
					break;
				}
			}
		}
		if(!ans) break;
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
/********** I'mAlone ***********/
