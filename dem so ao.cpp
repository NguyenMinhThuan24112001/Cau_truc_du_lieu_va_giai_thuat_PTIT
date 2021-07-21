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
 
const int MAXN = 1e2 + 5;
const int mod = 1e9 + 7;
/***** CONSTANT ******/


char A[MAXN][MAXN] = {};
bool vis[MAXN][MAXN] = {};



void bfs(pii P){
	queue<pii> q;
	q.push(P);
	vis[P.f][P.s] = true;
	
	while(!q.empty()){
		auto p = q.front(); q.pop();
		int x = p.f, y = p.s;
		for(int i=x-1; i<=x+1; i++){
			for(int j=y-1; j<=y+1; j++){
				if(vis[i][j]) continue;
				if(A[i][j] == 'W'){
					q.push({i, j});
					vis[i][j] = true;
				}
			}
		}
	}
	
}



void solution(){
	int n, m;
	cin >> n >> m;

	FOR(i, 1, n + 1) FOR(j, 1, m + 1) cin >> A[i][j];
	
	int count = 0;
	
	FOR(i, 1, n + 1){
		FOR(j, 1, m + 1){
			if(vis[i][j] || A[i][j] == '.') continue;
			bfs({i, j});
			count++;
		}
	}
	
	cout << count << endl;
	
	
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
//	cin >> test; cin.ignore();	
 
	while(test--) solution();
	
	return 0;	
}

