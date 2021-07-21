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
const ll N = (ll)1e16 + 5;
/***** CONSTANT ******/

/*
X-1
T-2
D-3
*/
int n;
vector<int> A(n), B(n);

int findIndex(int val, int comp, int local){
	int pos = -1;
	FORD(i, n - 1, local + 1){
		if(A[i] == val){
			if(pos == -1) pos = i;
			if(B[i] == comp) return i;
		}
	}
	return pos;
}

void solution(){
	

	cin >> n;
	A.resize(n);
	B.resize(n);
	FOR(i, 0, n){
		char c;
		cin >> c;
		A[i] = c == 'X'? 1 : c == 'T'? 2 : 3;
		B[i] = A[i];
	}
	sort(all(B));
	int ans = 0;
	FOR(i, 0, n){
		if(A[i] == B[i]) continue;
		int pos = findIndex(B[i], A[i], i);
		
		swap(A[pos], A[i]);
		ans++;
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
	

	
	int test = 1;	
//	cin >> test; cin.ignore();	

	while(test--) solution();
	
	return 0;	
}
