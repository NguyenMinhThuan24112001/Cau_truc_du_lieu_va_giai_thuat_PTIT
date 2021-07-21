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

const int MAXN = 1005;
const int mod = 1e9 + 7;

/***** CONSTANT ******/


int A[MAXN], B[MAXN], n;

int findNode(int left, int right, int val){
	FOR(i, left, right + 1) if(A[i] == val) return i;
	return -1;
}

void postOrder(int l_in, int r_in, int l_pre, int r_pre){
	
	int pos = findNode(l_in, r_in, B[l_pre]);
	
	int N = pos - l_in;
	
	if(pos != l_in){
		postOrder(l_in, pos - 1, l_pre + 1, l_pre + N);
	}
	
	if(pos != r_in){
		postOrder(pos + 1, r_in, l_pre + N + 1, r_pre);
	}
	
	cout << B[l_pre] << " ";
	
}


void solution(){
	
	cin >> n;
	FOR(i, 0, n) cin >> A[i];
	FOR(i, 0, n) cin >> B[i];
	
	postOrder(0, n - 1, 0, n - 1);
	cout << endl;
		
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
