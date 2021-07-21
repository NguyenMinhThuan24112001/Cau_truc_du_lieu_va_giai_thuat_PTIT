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

//int high(Node* node){
//	if(node == NULL) return 0;
//	return node->height;
//}
//
//
//Node* rightRotate(Node* node){
//	Node* nl = node->left;
//	Node* nlr = nl->right;
//	
//	nl->right = node;
//	node->left = nlr;
//	
//	
//	node->height = max(high(node->left), high(node->right)) + 1;
//	nl->height = max(high(nl->left), high(nl->right)) + 1;
//	
//	return nl;
//}
//
//Node* leftRotate(Node* node){
//	Node* nr = node->right;
//	Node* nrl = nr->left;
//	
//	nr->left = node;
//	node->right = nrl;
//
//	
//	node->height = max(high(node->left), high(node->right)) + 1;
//	nr->height = max(high(nr->left), high(nr->right)) + 1;
//	
//	return nr;
//}
//
//int getDis(Node* node){
//	if(node == NULL) return 0;
//	return high(node->left) - high(node->right);
//}
//
//Node* insert(Node* node, int val){
//	
//	if(node == NULL){
//		node = createNode(val);
//		node->height = 1;
//		return node;
//	}
//	
//	if(val < node->data) node->left = insert(node->left, val);
//	else if(val > node->data) node->right = insert(node->right, val);
//	else return node;
//	
//	node->height = max(high(node->left), high(node->right)) + 1;
////	cout << val << " " << node->data << " " << node->height << endl;
//	int dis = getDis(node);
//
//	if(dis > 1 && val < node->left->data) return rightRotate(node);
//	
//	else if(dis < -1 && val > node->right->data) return leftRotate(node);
//	
//	else if(dis > 1 && val > node->left->data){
//		node->left = leftRotate(node->left);
//		return rightRotate(node);
//	}
//	else if(dis < -1 && val < node->right->data){
//		node->right = rightRotate(node->right);
//		return leftRotate(node);
//	}
//	
//	
//	return node;
//	
//}
//
//void printTree(Node* node){
//	if(node == NULL) return;
//	
//
//	printTree(node->left);
//	printTree(node->right);
//	cout << node->data << " ";
//}

vector<int> A;

Node* avlTree(Node* node, int left, int right){
	int mid = (left + right) >> 1;
	node = createNode(A[mid]);
	if(left < mid) node->left = avlTree(node->left, left, mid - 1);
	if(right > mid) node->right = avlTree(node->right, mid + 1, right);
	return node;
}

void postOrder(Node* node){
	if(node == NULL) return;

	postOrder(node->left);
	postOrder(node->right);
	cout << node->data << " ";
}

void solution(){
	
	int n;
	cin >> n;
	A.clear();
	A.resize(n);
	FOR(i, 0, n) cin >> A[i];
	sort(all(A));
	cout << A[(n - 1) / 2] << endl;
//	Node* node = NULL;
//	node = avlTree(node, 0, n - 1);
//	
//	postOrder(node);
//	cout << endl;
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
