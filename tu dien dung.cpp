#include<bits/stdc++.h>
using namespace std;

vector<vector<char>> A;
vector<string> dictionary;
vector<vector<bool>> vis;
map<string, bool> out;
bool isHave = false;

void backTrack(int row, int col, string path){
	// check xem path co trong dictionary
	for(int i=0; i<dictionary.size(); i++){
		if(dictionary[i] == path && !out[path]){
			cout << path << " ";
			isHave = true;
//			out[path] = true;
		}
	}
	
	vis[row][col] = true;
	
	for(int i=row-1; i<=row+1; i++){
		for(int j=col-1; j<=col+1; j++){
			if(A[i][j] == '\0') continue;
			if(vis[i][j]) continue;
			backTrack(i, j, path + A[i][j]);
			
		}
	}
	
	vis[row][col] = false;
	
	
}

void solution(){
	isHave = false;
	out.clear();
	vis.clear();
	dictionary.clear();
	A.clear();
	
	int amount, n, m;
	
	cin >> amount >> n >> m;
	dictionary.resize(amount);
	A.assign(n + 5, vector<char>(m + 5, '\0'));
	vis.assign(n + 5, vector<bool>(m + 5, false));
	
	for(int i=0; i<amount; i++) cin >> dictionary[i];
	
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++) cin >> A[i][j];
	}
	
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			string path; path.push_back(A[i][j]);
			backTrack(i, j, path);
		}
	}
	
	if(!isHave){
		cout << -1;
	}
	cout << endl;
	
}




int main(){

	int test = 1;
	cin >> test;
	while(test--) solution();
	
}
