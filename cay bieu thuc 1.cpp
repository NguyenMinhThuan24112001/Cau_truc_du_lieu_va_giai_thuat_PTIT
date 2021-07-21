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

string ans = "";

struct Node{
	char data;
	Node* left;
	Node* right;
};

Node* creatNewNode(char data){
	Node* node = new Node();
	node->left = node->right = NULL;
	node->data = data;
	return node;
}

void printTree(Node* node){
	if(node == NULL) return;
	
	printTree(node->left);
	cout << node->data;
	printTree(node->right);
}

void solution(){
	string s;
	cin >> s;
	ans.clear();
	stack<Node*> stc;
	
	FOR(i, 0, s.length()){
		if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/'){
			Node* node = creatNewNode(s[i]);
			
			node->right = stc.top(); stc.pop();
			node->left = stc.top(); stc.pop();
			stc.push(node);
		}
		else{
			stc.push(creatNewNode(s[i]));	
		}
	}
	printTree(stc.top());
	cout << endl;
	
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
