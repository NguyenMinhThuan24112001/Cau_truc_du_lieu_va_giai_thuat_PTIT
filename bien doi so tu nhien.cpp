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


int bfs(int n){
	
	queue<pii> q;
	q.push({n, 0});
	
	map<int, bool> cts;
	
	while(!q.empty()){
		auto P = q.front(); q.pop();
		int number = P.f, step = P.s;
		
		if(number == 1) return step;
		
		if(!cts[number - 1]){
			q.push({number - 1, step + 1});
			cts[number - 1] = true;
		}
		
		FOR(i, 2, (int)sqrt(number) + 1){
			if(number % i == 0){
				if(cts[number / i]) continue;
				
				q.push({number / i, step + 1});
				cts[number / i] = true;
			}
		}
		
	}
	
	return -1;
	
	
}


void solution(){
	
	int n;
	cin >> n;
	
	cout << bfs(n) << endl;
	
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
