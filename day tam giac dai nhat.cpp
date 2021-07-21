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




void solution(){
	
	int n;
	cin >> n;
	vector<int> A(n);
	for(auto &x: A) cin >> x;
	vector<int> len1(n + 5), len2(n + 5);
	len1[0] = 1;
	FOR(i, 1, n){
		if(A[i] > A[i - 1]) len1[i] = len1[i - 1] + 1;
		else len1[i] = 1;
	}
	len2[n - 1] = 1;
	FORD(i, n - 2, 0){
		if(A[i] > A[i + 1]) len2[i] = len2[i + 1] + 1;
		else len2[i] = 1;
	}
	int ans = 0;
	FOR(i, 0, n) ans = max(ans, len1[i] + len2[i] - 1);
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
	
 	
 
	int test = 1;	
	cin >> test; cin.ignore();	
 
	while(test--) solution();
	
	return 0;	
}
