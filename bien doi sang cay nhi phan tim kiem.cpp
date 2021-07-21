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

struct Node{
	int data;
	Node* left;
	Node* right;
};

Node* createNode(int data){
	Node* node = new Node();
	node->data = data;
	node->left = node->right = NULL;
	return node;
}

Node* inputTree(){
	int n;
	cin >> n;
	Node* root = NULL;
	map<int, Node*> cts;
	
	FOR(i, 0, n){
		int x, y;
		char c;
		cin >> x >> y >> c;
		
		if(cts.find(x) == cts.end()){
			Node* n = createNode(x);
			cts[x] = n;
			if(root == NULL) root = n;
		}
		
		Node* node = cts[x];
		
		Node* node_y = createNode(y);
		
		if(c == 'L') node->left = node_y;
		else node->right = node_y;
		
		cts[y] = node_y;
		
	}
	return root;
}



void printTree(Node* node){
	if(node == NULL) return;
	
	cout << node->data << " ";
	
	printTree(node->left);
	printTree(node->right);
}

vector<int> lst;
void loadTree(Node* node){
	if(node == NULL) return;
	
	lst.pb(node->data);
	
	loadTree(node->left);
	loadTree(node->right);
}

pii cnt[MAXN] = {};
int calcNodeChild(Node* node){
	if(node == NULL) return 0;
	cnt[node->data].f += calcNodeChild(node->left);
	cnt[node->data].s += calcNodeChild(node->right);
	return cnt[node->data].f + cnt[node->data].s + 1;
}

map<int, int> pos;
void toBinarySearchTree(Node* node, int left, int right){
	if(node == NULL || left > right) return;
//	cout << node->data << " " << cnt[node->data].f << endl;
	toBinarySearchTree(node->left, left, left + cnt[node->data].f - 1);
	
	cout << lst[left + cnt[node->data].f] << " ";
	
	toBinarySearchTree(node->right, left + cnt[node->data].f + 1, right);
	
}

void solution(){
	lst.clear();
	reset(cnt);
	pos.clear();
	
	Node* node = inputTree();
	
	calcNodeChild(node);
	loadTree(node);
	sort(all(lst));
	
//	printTree(node);
	toBinarySearchTree(node, 0, lst.size() - 1);
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
