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
/******* LIBRARY and DEFINE *******/


template<typename A, typename B> 
ostream& operator << (ostream &os, const pair<A, B> &p){
return os << "(" << p.f << " " << p.s << ")";};

template<typename T>
ostream& operator << (ostream &os, const vector<T> &vec){
os << "VECTOR: "; for(auto ele: vec) os << ele << " "; return os;};
/********** TEMPLATES *********/


ll myfind(ll n, ll step, ll val){
	if(step == 1) return val % 2;
	
	ll dis = (1LL << (step - 1));
	
	if(n == dis) return val % 2;
	
	if(n > dis) n -= dis;
	
	return myfind((ll)n, step - 1, (ll)val / 2);
}

ll findStep(ll n){
	ll step = 0;
	while(n){
		step++;
		n /= 2;
	}
	return step;
}

void solution(){
	
	ll n, L, R;
	cin >> n >> L >> R;

	ll step = findStep(n);
	ll ans = 0;

	for(ll i = L; i <= R; i++){
		if(i >= (1LL << step)) continue;
	
		ll val = myfind(i, step, n);
		if(val == 1) ans++;
	}
	cout << ans << endl;
//	cout << myfind(15, step, n) << endl;
	
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
