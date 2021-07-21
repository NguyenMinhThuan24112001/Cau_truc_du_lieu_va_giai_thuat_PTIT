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
 
const int MAXN = 1005;
const int mod = 1e9 + 7;
/***** CONSTANT ******/

vector<int> dx = {-2, -1, 1, 2, -2, -1, 1, 2};
vector<int> dy = {-1, -2, -2, -1, 1, 2, 2, 1};
bool vis[50][50] = {};

int bfs(pii start, pii fis){
	queue<pair<pii, int>> q;
	q.push({start, 0});
	while(!q.empty()){
		auto p = q.front(); q.pop();
		auto Pa = p.f;
		int step = p.s;
		if(Pa.f == fis.f && Pa.s == fis.s){
			return step;
		}
		FOR(i, 0, dx.size()){
			int x = Pa.f + dx[i], y = Pa.s + dy[i];
			if(x >= 1 && x <= 8 && y >= 1 && y <= 8){
				if(vis[x][y]) continue;
				vis[x][y] = true;
				q.push({{x, y}, step + 1});		
			}
		
		}
		
	}
	return -1;
}

void solution(){

	reset(vis);
	string s1;
	string s2;
	cin >> s1 >> s2;
	char c1 = s1[0], c2 = s1[1], c3 = s2[0], c4 = s2[1];
	int x1 = c1 - 'a' + 1, y1 = c2 - '0';
	int x2 = c3 - 'a' + 1, y2 = c4 - '0';
	
	pii start = {x1, y1};
	pii fis = {x2, y2};
//	cout << start << " " << fis << endl;
	cout << bfs(start, fis) << endl;

	
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
