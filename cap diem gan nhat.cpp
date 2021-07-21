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


typedef pair<double, double> point;

struct comp{
	bool operator()(point p1, point p2){
		return p1.s == p2.s? p1.f < p2.f : p1.s < p2.s;
	}
};

double distance(point p1, point p2){
	return (double)sqrt(sqr(p1.f - p2.f) + sqr(p1.s - p2.s));
}

void solution(){
	set<point, comp> st;

	int n;
	cin >> n;
	vector<point> A(n);
	
	FOR(i, 0, n) cin >> A[i].f >> A[i].s;
	
	sort(all(A));
	double dis = (double)INF;
	int pos = 0;
	
	FOR(i, 0, n){
		while(pos < i && A[i].f - A[pos].f >= dis){
			st.erase(A[pos++]);
		}
		auto it = st.upper_bound({INF, A[i].s - dis});
		
		while(it != st.end()){
			if((it->s) - A[i].s >= dis) break;
			dis = min(dis, distance(*it, A[i]));
			it++;
		}
		st.insert(A[i]);
	}
	cout << setprecision(6) << fixed << dis << endl;
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
