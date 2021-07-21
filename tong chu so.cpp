 
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
 
const int MAXN = 1e2 + 5;
const int mod = 1e9 + 7;
/***** CONSTANT ******/


string dp[105][10005] = {};

string _min(string s1, string s2){
	if(s1 == "") return s2;
	if(s1.length() > s2.length()) return s2;
	if(s1.length() < s2.length()) return s1;
	
	for(int i=0; i<s1.length(); i++){
		if(s1[i] < s2[i]) return s1;
		if(s1[i] > s2[i]) return s2;
	}
	return s2;
}

void solution(){
	
	
	
	int sum_digit, square;
	cin >> sum_digit >> square;
	
	for(int i=1; i<=sum_digit; i++)
		for(int j=1; j<=square; j++) dp[i][j] = "";
	
	for(int i=1; i<=9; i++) dp[i][i * i] = to_string(i);
	
	for(int i=1; i<=sum_digit; i++){
		for(int j=1; j<=square; j++){
			if(dp[i][j] == "") continue;		
			for(int add = 0; add <= 9; add++){
				if(j + add * add > square) continue;
				if(i + add > sum_digit) continue;
				dp[i + add][j + add * add] = _min(dp[i + add][j + add * add], dp[i][j] + (char)(add + '0'));			
			}
		}
	}
	
	cout << (dp[sum_digit][square] == ""? to_string(-1) : dp[sum_digit][square]) << endl;
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
