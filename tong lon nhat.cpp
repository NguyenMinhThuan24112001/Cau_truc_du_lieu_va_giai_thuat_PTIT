#include<bits/stdc++.h>
using namespace std;
int n;
struct Node{
    int data;
    Node *left, *right;
    Node(int d){
        data = d;
        left = right = NULL;
    }
};
long long level = -1e18;
void makeNode(Node *root,int n1,int n2,char c){
    switch(c){
        case 'L': root->left=new Node(n2);
                break;
        case 'R': root->right=new Node(n2);
                break;
    }
}

void insert(Node *root,int n1,int n2,char c){
     if(root==NULL) return;
     if(root->data == n1)
         makeNode(root,n1,n2,c);
     else{
         insert(root->left,n1,n2,c);
         insert(root->right,n1,n2,c);
     }
}
long long maxSum(Node *root){
    if(root->left == NULL && root->right == NULL) {
        //cout<<"con : "<<root->data<<endl;
        return root->data;
    }
    if(root->left != NULL && root->right != NULL) {
        long long k = maxSum(root->left);
        long long h = maxSum(root->right);
       // cout<<"root : "<<root->data<<endl;
       //cout<<h<<" "<<k<<endl;
        level = max(level, h + k + root->data);
        return max(h, k) + root->data;
    }
    else {
        if(root->left != NULL) return root->data + maxSum(root->left);
        else return root->data + maxSum(root->right);
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        Node *root=NULL;
        while(n--){
            int n1,n2; char c;
            cin>>n1>>n2>>c;
            if(root==NULL){
                root=new Node(n1);
                makeNode(root,n1,n2,c);
            }
            else insert(root,n1,n2,c);
        }
        level = -1e18;
        maxSum(root);
        cout<<level<<endl;
    }

    return 0;
}
