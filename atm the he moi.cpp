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

ll W, c;

const int note[] = {0, 1, 1, 1, 2, 1, 2, 2, 2, 3};
const int ways[] = {1, 1, 1, 1, 2, 1, 2, 1, 1, 3};


void countMoney(){
	ll min_note = 0, number_ways = 1;
	
	while(c-- && W > 0){
		
		ll number = W % 10;
		min_note += note[number];
		number_ways *= ways[number];
		W /= 10;
		
	}
	if(W){
		ll last_note = W / 5, div = W % 5;
		min_note += last_note + note[div];
		
		int val = 1;
		if(W % 5 == 1 && W > 1 || W == 4) val = 2;
		if(W % 5 == 4 && W > 4) val = 3;
		
		number_ways *= val;
	}
	
	cout << min_note << " " << number_ways << endl;	
}


void solution(){
	

	cin >> W >> c;
	
	if(W % 1000){
		cout << 0 << endl;
		return;
	}
	
	W /= 1000;
	
	countMoney();
	
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
