#include<bits/stdc++.h>
using namespace std;
bool CheckFile(string path){
	 ifstream isf(path);
	 return isf.good();
}
map<string,map<string,int>> maps;
map<string,int>tuoi;
map<string,bool>chuaxet;
void dequy(){
	for(auto j:maps){
		if(chuaxet[j.first]){
			for(auto i:maps[j.first]){
				tuoi[i.first]=tuoi[j.first]-i.second;
				chuaxet[i.first]=true;
			}
		}
	}
}
bool check(){
	for(auto i:chuaxet){
		if(!i.second)return true; 
	}
	return false;
}
bool compare(pair<string,int> a,pair<string,int> b){
	if(a.second!=b.second)return a.second>b.second;
	else return a.first<b.first;
}
void Solution(){
	maps.clear();
	tuoi.clear();
	tuoi["Ted"]=100;
	int n;
	cin>>n;
	while(n--){
		string s1,s2;
		int tuoi;
		cin>>s1>>s2>>tuoi;
		maps[s1][s2]=tuoi;
		chuaxet[s1]=false;
		chuaxet[s2]=false;
	}
	chuaxet["Ted"]=true;
	while(check())dequy();
	tuoi.erase("Ted");
	vector<pair<string,int>> ans;
	for(auto i:tuoi){
		ans.push_back({i.first,i.second});
	}
	sort(ans.begin(),ans.end(),compare);
	for(auto i:ans){
		cout<<i.first<<' '<<i.second<<'\n';
	}
	//cout<<endl;
}
int main(){
	if(CheckFile("input.txt")){
	   freopen("input.txt","r",stdin);
	}
	int t;
	cin>>t;
	cin.ignore();
	for(int i=1;i<=t;i++){
		cout<<"DATASET "<<i<<endl;
		Solution();
	}
	return 0;
}
