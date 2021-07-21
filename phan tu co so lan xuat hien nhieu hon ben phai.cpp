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

map<int, int> cnt;

void solution(){
	
	cnt.clear();
	int n;
	cin >> n;
	vector<int> A(n), ans(n);
	
	FOR(i, 0, n) cin >> A[i], cnt[A[i]]++;
	
	stack<int> stc;
	stc.push(n - 1); ans[n - 1] = -1;
	FORD(i, n - 2, 0){
		if(cnt[A[i]] < cnt[A[i + 1]]){
			stc.push(i);
			ans[i] = i + 1;
		}
		else{
			while(!stc.empty() && cnt[A[i]] >= cnt[A[stc.top()]]){
				stc.pop();
			}
			if(stc.empty()) ans[i] = -1;
			else ans[i] = stc.top();
			stc.push(i);
		}
	}
	
	FOR(i, 0, n){
		cout << (ans[i] == -1? -1 : A[ans[i]]) << " ";
	}
	cout << endl;
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
