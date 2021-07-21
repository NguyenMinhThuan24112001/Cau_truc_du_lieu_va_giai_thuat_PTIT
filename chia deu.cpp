#include<bits/stdc++.h>
#define pb push_back
#define ll long long
#define endl '\n'
#define mp make_pair
#define f first
#define s second
#define eb emplace_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define INF INT_MAX
#define LINF LLONG_MAX
#define all(vec) vec.begin(), vec.end()
#define testIN 0
#define testOUT 0
#define FILEINPUT freopen("inputCNB.txt", "r", stdin);
#define FILEOUTPUT freopen("ouputCNB.txt", "w", stdout);
#define FOR(i, m, n) for(int i=m; i<n; i++)
#define FORD(i, m, n) for(int i=m; i>=n; i--)
#define FastIO cin.tie(0); ios_base::sync_with_stdio(false); cout.tie(0);
#define pq_max priority_queue<int>
#define pq_min priority_queue<int, vector<int>, greater<int>>
#define reset(A) memset(A, 0, sizeof(A))
using namespace std;
/******* LIBRARY and DEFINE *******/
template<typename A, typename B> 
ostream& operator << (ostream &os, const pair<A, B> &p){return os << "(" << p.f << " " << p.s << ")";};
template<typename T>
ostream& operator << (ostream &os, const vector<T> &vec){for(auto ele: vec) os << ele << " "; return os;};
/********** TEMPLATES *********/
const int MAXN = 25;
const int mod = 1e9 + 7;
/********** CONSTANT *********/
int A[MAXN];
 
void resetGlobalVar(){
//	reset(A)
}
 
ll factor(int n){
	ll res = 1;
	FOR(i, 2, n + 1) res *= i;
	return res;
}
 
ll Ckn(int k, int n){
	return factor(n) / factor(n - k) / factor(k);
}
 
void solution(){
	resetGlobalVar();
	// reset global variable
	
	int n, k;
	cin >> n >> k;
	int S = 0;
	FOR(i, 0, n) cin >> A[i], S += A[i];
	if(k == 1){
		cout << 1 << endl;
		return;
	}
	if(S % k){
		cout << 0 << endl;
		return;
	}
	int val = S / k;
	vector<int> cnt(MAXN);
	if(S == 0){
		int count = 0, sum = 0;
		FOR(i, 0, n){
			sum += A[i];
			if(sum == 0) count++;
		}
		if(count < k){
			cout << 0 << endl;
			return;
		}
		else{
			cout << Ckn(k - 1, count - 1) << endl;
			return;
		}
	}
	ll sum = 0, ans = 0;
	FOR(i, 0, n){
		sum += A[i];
		if(sum % val == 0 && sum != 0){
			int index = sum / val;
			if(index == k - 1){
				ll res = 1;
				FOR(i, 1, k - 1) res *= cnt[i];
				ans += res;
			}
			else cnt[index]++;
		}
	}
	cout << ans << endl;
	
	
	
}
 
/*******************************/
		
/******** MAIN FUNCTION *********/
int main(){
	#if testIN
		FILEINPUT;
	#endif
	#if testOUT 
		FILEOUTPUT;
	#endif
	
	FastIO;
 
	int test = 1;
//	cin >> test; cin.ignore();
	while(test--) solution();
	
	return 0;
}
/********** I'mAlone ***********/
/******** CAN NGOC BINH **********/
