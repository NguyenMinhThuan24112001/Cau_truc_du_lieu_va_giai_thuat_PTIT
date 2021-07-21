#include<bits/stdc++.h>
using namespace std;
vector<vector<int> > c;
int a[101];
int store[1001];
bool chuaxet[1001];
void DFS(int u){
    for(int i = 0 ; i < c[u].size() ; i++){
        if(chuaxet[c[u][i]] == false){
            store[c[u][i]]++;
            chuaxet[c[u][i]] = true;
            DFS(c[u][i]);
        }
    }
}
int main(){
    int k, n, m;
    cin>>k>>n>>m;
    for(int i = 1 ; i <= k ; i++) cin>>a[i];
    int countA = 0;
    c.resize(n+1);
    int tmp1, tmp2;
    for(int i = 1 ; i <= m ; i++){
        cin>>tmp1>>tmp2;
        c[tmp1].push_back(tmp2);
    }
    for(int i = 1; i <= k ; i++) {
        store[a[i]]++;
        memset(chuaxet, 0, n+1);
        chuaxet[a[i]] = true;
        DFS(a[i]);
    }
    for(int i = 1  ; i <= n ; i++){
        if(store[i] == k) countA++; 
    }
    cout<<countA<<endl;
    return 0;
}
