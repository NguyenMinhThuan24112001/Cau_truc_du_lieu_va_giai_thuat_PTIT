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
 
const int MAXN = 2e5 + 5;
const int mod = 1e9 + 7;
const int N = 1 << 4;
/***** CONSTANT ******/
 
 
 
 
void solution(){
	
	ll n;
	cin >> n;
	
	string s;
	cin >> s;
	
	int pos_a = 0, pos_b = 0;
	ll ans = 0;
	
	ll count = 0;
	
	FOR(i, 1, s.length() + 1){
		if(s[i - 1] == 'A'){
			int dis = i - pos_a;
			count += dis + (pos_a > pos_b && pos_b);
			pos_a = i;
		}
		else{
			int dis = i - pos_b;
			count += dis + (pos_a < pos_b && pos_a);
			pos_b = i;
		}
//		cout << i << " " << count << endl;
	}
	
	cout << n * (n + 1) / 2 - count << endl;
	
	
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
/********** I'mAlone ***********/
