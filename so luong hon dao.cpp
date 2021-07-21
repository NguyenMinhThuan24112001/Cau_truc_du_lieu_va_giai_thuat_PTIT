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


vector<pii> v;
vector<vector<int>> A;
vector<vector<bool>> vis;


int bfs(){
	int count = 0;
	for(auto p: v){
		if(vis[p.f][p.s]) continue;
		queue<pii> q;
		q.push(p);
		
		while(!q.empty()){
			auto P = q.front(); q.pop();
			
			int x = P.f, y = P.s;
			
			FOR(i, x - 1, x + 2){
				FOR(j, y - 1, y + 2){
					if(vis[i][j]) continue;
					if(A[i][j]){
						vis[i][j] = true;
						q.push({i, j});
					}
				}
			}
			
		}
		count++;
	}
	return count;
}

void solution(){
	v.clear();
	
	int n, m;
	cin >> n >> m;
	A.clear();
	A.assign(n + 5, vector<int>(m + 5, 0));
	vis.assign(n + 5, vector<bool>(m + 5, false));
	
	
	FOR(i, 1, n + 1){
		FOR(j, 1, m + 1){
			cin >> A[i][j];
			if(A[i][j]){
				v.eb(i, j);
			}
		}
	}
	cout << bfs() << endl;
	
	
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
