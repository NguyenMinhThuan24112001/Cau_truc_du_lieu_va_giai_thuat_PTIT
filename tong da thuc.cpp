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

struct Node{
	int base;
	int power;
	Node* next;
};

Node* createNode(int base, int power){
	Node* node = new Node();
	node->base = base;
	node->power = power;
	node->next = NULL;
	return node;
}

int stringToNum(string s){
	int res = 0;
	FOR(i, 0, s.length()) res = res * 10 + s[i] - '0';
	return res;
}

void insertNode(Node* &node, int base, int power){
	if(node == NULL){
		node = createNode(base, power);
		return;
	}
	insertNode(node->next, base, power);
}

void printList(Node* lst){
	if(lst == NULL) return;
	
	cout << lst->base << "*x^" << lst->power << (lst->next == NULL? "" : " + ");
	printList(lst->next);
}

Node* process(string s){
	Node* lst = NULL;
	
	int N = s.length();
	vector<int> v;
	
	FOR(i, 0, s.length()) if(s[i] == '*') v.pb(i);
	
	for(auto x: v){
		int pos_base = x - 1;
		int pos_pow = x + 3;
		
		string str_base;
		while(pos_base >= 0 && pos_base < N && s[pos_base] >= '0' && s[pos_base] <= '9') str_base = s[pos_base--] + str_base;
		
		string str_pow;
		while(pos_pow >= 0 && pos_pow < N && s[pos_pow] >= '0' && s[pos_pow] <= '9') str_pow += s[pos_pow++];
		
		int val_base = stringToNum(str_base);
		int val_pow = stringToNum(str_pow);
		insertNode(lst, val_base, val_pow);
	}
	
	return lst;
	
}

Node* addNode(Node* lst1, Node* lst2){
	Node* lst = NULL;
	
	while(lst1 != NULL && lst2 != NULL){
		
		int base1 = lst1->base;
		int base2 = lst2->base;
		int pow1 = lst1->power;
		int pow2 = lst2->power;
		
		if(pow1 == pow2){
			insertNode(lst, base1 + base2, pow1);
			lst1 = lst1->next;
			lst2 = lst2->next;
			continue;	
		}
		if(pow1 > pow2){
			insertNode(lst, base1, pow1);
			lst1 = lst1->next;
		}
		else{
			insertNode(lst, base2, pow2);
			lst2 = lst2->next;
		}
	}
	
	while(lst1 != NULL){
		insertNode(lst, lst1->base, lst1->power);
		lst1 = lst1->next;
	}
	
	while(lst2 != NULL){
		insertNode(lst, lst2->base, lst2->power);
		lst2 = lst2->next;
	}
	return lst;
}


void solution(){
	string s1, s2;
	getline(cin, s1);
//	cin.ignore();
	getline(cin, s2);
//	cin.ignore();
	Node* lst1 = process(s1);
	Node* lst2 = process(s2);
	
	Node* ans = addNode(lst1, lst2);
	
	printList(ans);
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
