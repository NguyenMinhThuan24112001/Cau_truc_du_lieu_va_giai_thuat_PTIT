#include<bits/stdc++.h>
using namespace std;
int V, E;
typedef struct Dinh{
    int x, y, z;
}dinh;
dinh a[10005];
int parent[10005];
bool compareA(dinh a, dinh b){
    if(a.z != b.z) return a.z < b.z;
    if(a.x != b.x) return a.x < b.x;
    return a.y < b.y;
}
int find(int v){
    if (parent[v] == -1)
        return v;
    return find(parent[v]);
}
int Kruscal(){
    int ans = 0;
    memset(parent,-1, 4 *(V+1));
    for(int i = 0 ; i < E; i++){
        int x = find(a[i].x);
        int y = find(a[i].y);
        if(x != y){
            parent[x] = y;
            ans += a[i].z;
        }
    }
    return ans; 
}
int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>V>>E;
        for(int i = 0 ; i < E; i++){
            cin>>a[i].x>>a[i].y>>a[i].z;
        }
        sort(a, a+E, compareA);
        cout<<Kruscal()<<endl;
    }

    return 0;
}
