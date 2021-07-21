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

vector<vector<pii>> adj;
vector<vector<int>> cost, A;

vector<pii> dx = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int n, m;

int dijkstra(){
	
	priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> pq;
	pq.push({A[1][1], {1, 1}});
	while(!pq.empty()){
		auto PI = pq.top(); pq.pop();
		
		int val = PI.f;
		auto p = PI.s;
		int row = p.f, col = p.s;
		if(row == n && col == m) return val;
		if(cost[row][col] < val) continue;
		
		for(auto x: dx){
			if(A[row + x.f][col + x.s] == -1) continue;
			if(val + A[row + x.f][col + x.s] < cost[row + x.f][col + x.s]){
				cost[row + x.f][col + x.s] = val + A[row + x.f][col + x.s];
				pq.push({cost[row + x.f][col + x.s], {row + x.f, col + x.s}});
			}
		}
	}
	return -1;
}


void solution(){
	
	cin >> n >> m;
	A.assign(n + 5, vector<int>(m + 5, -1));
	cost.assign(n + 5, vector<int>(m + 5, INF));
	FOR(i, 1, n + 1) FOR(j, 1, m + 1) cin >> A[i][j];
	
	cout << dijkstra() << endl;
	
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
