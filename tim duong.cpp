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


vector<vector<char>> A;
pii start, fis;
vector<vector<bool>> vis;
int n, m;
//vector<pii> dx = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

bool bfs(){
	queue<pair<pii, int>> q;
	q.push({start, -1});
	vis[start.f][start.s] = true;
	
	
	while(!q.empty()){
		auto P = q.front(); q.pop();
		
		auto pos = P.f;
		int move = P.s;
		int x = pos.f, y = pos.s;
		
		if(x == fis.f && y == fis.s) return true;
// 		cout << x << " " << y << " " << move << endl;
		if(move >= 2) continue;
		
		
		int index = 0;
		int row = x - 1, col = y;

		while(row > 0 && row <= n && A[row][col] == '.'){
			if(vis[row][col]){
				row--;
				continue;
			}
			vis[row][col] = true;
			q.push({{row--, col}, move + 1});
		}
		if(A[row][col] == 'T') return true;
		
		row = x + 1, col = y;
		while(row > 0 && row <= n && A[row][col] == '.'){
			if(vis[row][col]){
				row++;
				continue;
			}
			vis[row][col] = true;
			q.push({{row++, col}, move + 1});
		}
		if(A[row][col] == 'T') return true;
		
		row = x, col = y - 1;
		while(col > 0 && col <= m && A[row][col] == '.'){
			if(vis[row][col]){
				col--;
				continue;
			}
			vis[row][col] = true;
			q.push({{row, col--}, move + 1});
		}
		if(A[row][col] == 'T') return true;
		
		row = x, col = y + 1;
		while(col > 0 && col <= m && A[row][col] == '.'){
			
			if(vis[row][col]){
				col++;
				continue;
			}
//			cout << col << endl;
			vis[row][col] = true;
			q.push({{row, col++}, move + 1});
		}
		if(A[row][col] == 'T') return true;
		
	}
	return false;
	
}

void solution(){

	cin >> n >> m;
	
	A.assign(n + 5, vector<char>(m + 5, '*'));
	vis.assign(n + 5, vector<bool>(m + 5, false));
	
	
	FOR(i, 1, n + 1) FOR(j, 1, m + 1){
		cin >> A[i][j];
		if(A[i][j] == 'S') start = {i, j};
		else if(A[i][j] == 'T') fis = {i, j};
	}
//	bool ans = bfs();
	
	cout << (bfs()? "YES" : "NO") << endl;
	
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
