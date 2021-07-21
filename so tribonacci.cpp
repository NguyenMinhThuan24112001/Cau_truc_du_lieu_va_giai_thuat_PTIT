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
#define FOR(i,l,r) for (int i=l;i<=r;i++)
#define FOD(i,r,l) for (int i=r;i>=l;i--)
#define FastIO cin.tie(0); ios_base::sync_with_stdio(false); cout.tie(0);
#define pq_max priority_queue<int>
#define pq_min priority_queue<int, vector<int>, greater<int>>
#define reset(A) memset(A, 0, sizeof(A))
#define debug cerr << "debug: "
/******* LIBRARY and DEFINE *******/

const ll mod = 1e15 + 7;
ll n, T[5], dp[5];

struct Matrix {
	int x, y;
	ll A[5][5];
};

Matrix a, x, ans;

ll multi(ll a, ll b){
	if(b == 0) return 0;
	if(b == 1) return a % mod;
	else if(b & 1) return ((multi(a, b-1) % mod) + a) % mod;
	else return ((multi(a, b/2) % mod) * 2) % mod;
}

Matrix operator * (Matrix a, Matrix b) {
	int row = a.x, col = b.y;
	Matrix res = {row, col};
	FOR(i,1,res.x){
		FOR(j,1,res.y) res.A[i][j] = 0LL;	
	} 
	FOR(i,1,res.x){
		FOR(j,1,res.y){
			FOR(k,1,a.y)
				res.A[i][j] = (res.A[i][j] + multi(a.A[i][k]%mod, b.A[k][j]%mod)) % mod;
		}
	}
	return res;
}

Matrix masterPow(Matrix m, ll n){
	if(n == 1) return m;
	else if(n & 1) return masterPow(m, n-1)*m;
	else{
		Matrix mtr = masterPow(m, n/2);
		return mtr * mtr;
	}
}

void set_(){
	a.x = 4; a.y = 1;
	a.A[1][1] = dp[3]; a.A[2][1] = T[3]; a.A[3][1] = T[2]; a.A[4][1] = T[1];
	x.x = x.y = 4;
	x.A[1][1] = x.A[1][2] = x.A[1][3] = x.A[1][4] = x.A[2][2] = x.A[2][3] = x.A[2][4] = x.A[3][2] = x.A[4][3] = 1LL;
}

int main() {

	FOR(i,1,3) T[i] = i, dp[i] =  T[i] + dp[i - 1];
	
	set_();
	int test;
	cin >> test;
	while(test--) {
		cin >> n;
		if (n <= 3) {
			cout << dp[n] << endl;
			continue;
		}
		ans = masterPow(x, n-3) * a;
		cout << ans.A[1][1] << '\n';
	}
	return 0;
}
