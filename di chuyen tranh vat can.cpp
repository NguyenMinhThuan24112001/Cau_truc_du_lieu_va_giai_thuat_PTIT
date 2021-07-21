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

vector<vector<char>> A;
vector<vector<bool>> vis;

int minStep(pii start, pii fis){
	
	queue<pair<pii, int>> q;
	q.push({start, 0});
	vis[start.f][start.s] = true;
	while(!q.empty()){
		auto PI = q.front(); q.pop();
		auto p = PI.f;
		int row = p.f, col = p.s;
		int step = PI.s;
		if(row == fis.f && col == fis.s){
			return step;
		}
		int index1 = col;
		while(A[row][index1] != 'X'){
			if(!vis[row][index1]){
				q.push({{row, index1}, step + 1});
				vis[row][index1] = true;
			}
			index1++;
		}
		
		int index2 = row;
		while(A[index2][col] != 'X'){
			if(!vis[index2][col]){
				q.push({{index2, col}, step + 1});
				vis[index2][col] = true;
			}
			index2++;
		}
		
		int index3 = row;
		while(A[index3][col] != 'X'){
			if(!vis[index3][col]){
				q.push({{index3, col}, step + 1});
				vis[index3][col] = true;
			}
			index3--;
		}
		
		int index4 = col;
		while(A[row][index4] != 'X'){
			if(!vis[row][index4]){
				q.push({{row, index4}, step + 1});
				vis[row][index4] = true;
			}
			index4--;
		}
		
	}
	
	return -1;
}

void solution(){
	
	int n;
	cin >> n;
	
	A.assign(n + 5, vector<char>(n + 5, 'X'));
	vis.assign(n + 5, vector<bool>(n + 5, false));
	FOR(i, 1, n + 1) FOR(j, 1, n + 1) cin >> A[i][j];
	
	pii start, fis;
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	start = {a + 1, b + 1};
	fis = {c + 1, d + 1};
	cout << minStep(start, fis) << endl;
	
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
