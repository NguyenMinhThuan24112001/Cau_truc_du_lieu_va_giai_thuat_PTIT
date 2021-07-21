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

vector<vector<int>> ans;
const int N = 1e4 + 5;

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

void printTree(Node* node){
	if(node == NULL) return;
	
	printTree(node->left);
	printTree(node->right);
	cout << node->data << " ";
}

//void levelTree(Node* node, int lvl){
//	if(node == NULL) return;
//	ans[lvl].pb(node->data);
//	
//	levelTree(node->left, lvl + 1);
//	levelTree(node->right, lvl + 1);
//}

int search(int arr[], int strt, int end, int value)
{
    for (int i = strt; i <= end; i++)
        if (arr[i] == value)
            return i;
    return -1;
}
 
int* extrackKeys(int in[], int level[], int m, int n)
{
    int *newlevel = new int[m], j = 0;
    for (int i = 0; i < n; i++)
        if (search(in, 0, m - 1, level[i]) != -1)
            newlevel[j] = level[i], j++;
    
    return newlevel;
}
 
Node* newNode(int data)
{
    Node* node = new Node();
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}

Node* buildTree(int in[], int level[], int inStrt,
                int inEnd, int n)
{
 
    if (inStrt > inEnd)
        return NULL;

    Node* root = newNode(level[0]);

    if (inStrt == inEnd)
        return root;

    int inIndex = search(in, inStrt, inEnd, root->data);
    if(inIndex == -1) return NULL;

    int* llevel = extrackKeys(in, level, inIndex, n);

    int* rlevel
        = extrackKeys(in + inIndex + 1, level, n - 1, n);

    root->left = buildTree(in, llevel, inStrt, inIndex - 1,
                           inIndex - inStrt);
    root->right = buildTree(in, rlevel, inIndex + 1, inEnd,
                            inEnd - inIndex);
                            
    delete[] llevel;
    delete[] rlevel;
 
    return root;
}
 
int in[1005], level[1005];

void solution(){
	
	int n;
	cin >> n;
	FOR(i, 0, 1005) in[i] = -1, level[i] = -1;;

	FOR(i, 0, n) cin >> in[i];
	FOR(i, 0, n) cin >> level[i];
	
	Node* node = buildTree(in, level, 0, n - 1, n);
	
	printTree(node);
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
