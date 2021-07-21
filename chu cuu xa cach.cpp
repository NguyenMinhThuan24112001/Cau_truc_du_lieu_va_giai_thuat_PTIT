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


int a[300][300];
int parent[300][300];
int store[10000][2];
int N, K, M;
typedef pair<int, int > II;
int direcX[] = {0, -2, 0, 2};
int direcY[] = {2, 0, -2, 0};
II check(){
    for(int i = 1 ; i <= 2 * N - 1 ; i+=2){
        for(int j = 1 ; j <= 2 * N - 1 ; j+=2){
            if(parent[i][j] == 0) return II(i, j);
        }
    }
    return II(0, 0);
}
void make(){
    queue<II> q;
    II tmp;
    int countA = 1;
    while (true)
    {
        II k = check();
        if(k.first == 0 && k.second == 0) break;
        parent[k.first][k.second] = countA;
        q.push(k);
        while (!q.empty())
        {
            tmp = q.front();
            q.pop();
            for(int i = 0 ; i < 4; i++){
                int x = tmp.first + direcX[i];
                int y = tmp.second + direcY[i];
                if(x >= 1 && x <= 2 * N - 1 && y <= 2 * N  - 1 && y >= 1 && parent[x][y] == 0 && a[(tmp.first+x)/2][(tmp.second+y)/2] == 0){
                    parent[x][y] = parent[tmp.first][tmp.second];
                    q.push(II(x, y));
                }
            }
        }
        
        countA++;
    }
   /*for(int i = 1 ; i <=2* N-1 ; i++){
            for(int j = 1 ; j <=2* N - 1; j++) cout<<parent[i][j]<<" ";
            cout<<endl;
    }*/
}
int main(){
    cin>>N>>K>>M;
    int tmp1, tmp2, tmp3, tmp4;
    for(int i = 1 ; i <= M ; i++){
        cin>>tmp1>>tmp2>>tmp3>>tmp4;
        if(tmp1 == tmp3){
            int x = min(tmp2, tmp4);
            a[tmp1*2-1][x*2] = 1;
        }
        else{
            int x = min(tmp1, tmp3);
            a[x*2][tmp2*2-1] = 1;
        }
    }
    make();
    int countA = 0;
    for(int i = 1 ; i <= K; i++) {
        cin>>store[i][0]>>store[i][1];
        store[i][0] = store[i][0] *2-1;
        store[i][1] = store[i][1] *2-1;
    }
    for(int i = 1 ; i < K ; i++){
        for(int j = i+1 ; j <= K ; j++){
           // cout<<store[i][0]<<" "<<store[i][1]<<" "<<store[j][0]<<" "<<store[j][1]<<endl;
           if(parent[store[i][0]][store[i][1]] != parent[store[j][0]][store[j][1]]) countA++;
        }
    }
    cout<<countA<<endl;
    return 0;
}
