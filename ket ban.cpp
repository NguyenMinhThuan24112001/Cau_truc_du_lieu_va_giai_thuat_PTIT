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

const int MAXN = 1e6 + 5;
const ll mod = (ll)1e9 + 7;
/********** CONSTANT *********/

vector<int> parent, Rank;

int dsuFind(int u){
	if(parent[u] == u) return u;
	int node = dsuFind(parent[u]);
	
	parent[u] = node;
	return node;
}

void dsuMerge(int u, int v){
	int node1 = dsuFind(u);
	int node2 = dsuFind(v);
	if(node1 == node2) return;
	if(Rank[node1] < Rank[node2]) swap(node1, node2);
	parent[node2] = node1;
	if(Rank[node1] == Rank[node2]) Rank[node1]++;
}


void solution(){
	
	int n, m;
	cin >> n >> m;
	parent.clear();
	parent.resize(n + 1);
	Rank.reserve(n + 1);
	FOR(i, 1, n + 1) parent[i] = i, Rank[i] = 1;
	
	FOR(i, 0, m){
		int u, v;
		cin >> u >> v;
		dsuMerge(u, v);
	}
	
	FOR(i, 1, n + 1) parent[i] = dsuFind(i);
	map<int, int> cnt;
	int ans = 0;
	FOR(i, 1, n + 1){
//		cout << parent[i] << endl;
		cnt[parent[i]]++;
		ans = max(ans, cnt[parent[i]]);
	}
	cout << ans << '\n';
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

