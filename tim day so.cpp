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

const int MAXN = 2005 + 5;
const int mod = 1e9 + 7;

/***** CONSTANT ******/

int pre[MAXN][MAXN] = {};

void prepare(){
	FOR(i, 1, MAXN){
		for(int j=1; j<=i; j++){
			int val = i / j;
			if(pre[i][val] == 0) pre[i][val] = j;
			else pre[i][val] = min(pre[i][val], j);
			
		}
	}
}


void solution(){
	
	int n;
	cin >> n;
	
	int N = INF;
	vector<int> A(n);
	FOR(i, 0, n) cin >> A[i], N = min(N, A[i]);
	
	

	int ans = INF;
	FOR(i, 1, N + 1){
		bool check = true;
		int sum = 0;
		FOR(j, 0, n){
			if(pre[A[j]][i] == 0){
				check = false;
				break;
			}
			sum += pre[A[j]][i];
		}
		if(check) ans = min(ans, sum);
	}
	
	cout << ans << endl;
	
}

/*******************************/
		
/******** MAIN FUNCTION *********/
int main(){
	
	#ifdef NGOCBINH
		FILEINPUT;
		FILEOUTPUT;
	#endif
	

	
	FastIO;
	
	prepare();
	
	int test = 1;	
//	cin >> test; cin.ignore();	

	while(test--) solution();
	
	return 0;	
}
