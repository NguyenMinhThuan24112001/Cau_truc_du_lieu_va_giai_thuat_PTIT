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

const int MAXN = 1e4 + 5;
const int mod = 1e9 + 7;

/***** CONSTANT ******/

vector<string> v;
bool vis[15] = {};
int per[15] = {}, n;

int ans = INF;

int calcStep(int index){
	string s1 = v[per[index - 1]];
	string s2 = v[per[index]];
	vector<bool> have(26, false);
	FOR(i, 0, s1.length()) have[s1[i] - '0'] = true;
	int count = 0;
	FOR(i, 0, s2.length()) if(have[s2[i] - '0']) count++;
	return count;
}

void backTrack(int index, int step){
	if(step > ans) return;
	if(index == n + 1){
		ans = min(ans, step);
		return;
	}
	FOR(i, 1, n + 1){
		if(vis[i]) continue;
		vis[i] = true;
		per[index] = i;
		int val = calcStep(index);
		backTrack(index + 1, step + val);
		vis[i] = false;
	}
}


void solution(){

	cin >> n;
	v.resize(n + 1);
	FOR(i, 1, n + 1) cin >> v[i];
	backTrack(1, 0);
	
	cout << ans << endl;

}

/*******************************/
		
/******** MAIN FUNCTION *********/
int main(){
	
	#ifdef NGOCBINH
		FILEINPUT;
		FILEOUTPUT;
	#endif
	
//	freopen("data.in", "r", stdin);
	
	FastIO;
	
	int test = 1;	
//	cin >> test; cin.ignore();	

	while(test--) solution();
	
	return 0;	
}
