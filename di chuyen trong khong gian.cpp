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

struct point{
	int x, y, z;
};

vector<vector<vector<char>>> A;
vector<vector<vector<bool>>> vis;
int h, n, m;
vector<point> dx = {{-1, 0, 0}, {0, -1, 0}, {0, 0, -1}, {0, 0, 1}, {1, 0, 0}, {0, 1, 0}};
point start, fis;

int bfs(){

	queue<pair<point, int>> q;
	q.push({start, 1});
	vis[start.x][start.y][start.z] = true;
	
	while(!q.empty()){
		auto P = q.front(); q.pop();
		point pt = P.f;
		int step = P.s;
		
		if(A[pt.x][pt.y][pt.z] == 'E') return step - 1;
		
		for(auto p: dx){
			if(vis[pt.x + p.x][pt.y + p.y][pt.z + p.z] || A[pt.x + p.x][pt.y + p.y][pt.z + p.z] == '#')
				continue;
			
			vis[pt.x + p.x][pt.y + p.y][pt.z + p.z] = true;
			
			q.push({{pt.x + p.x, pt.y + p.y, pt.z + p.z}, step + 1});
		}
		
		
	}
	return -1;
	
}

void solution(){

	cin >> h >> n >> m;
	
	A.assign(h + 5, vector<vector<char>>(n + 5, vector<char>(m + 5, '#')));
	vis.assign(h + 5, vector<vector<bool>>(n + 5, vector<bool>(m + 5, false)));
	
	FOR(i, 1, h + 1){
		FOR(j, 1, n + 1){
			FOR(k, 1, m + 1){
				cin >> A[i][j][k];
				if(A[i][j][k] == 'S') start = {i, j, k};
				else if(A[i][j][k] == 'E') fis = {i, j, k};
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
/********** I'mAlone ***********/
