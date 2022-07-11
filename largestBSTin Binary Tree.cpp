#include<iostream>
using namespace std;
struct node{
     int data;
     node *left,*right;
};
node *create_node(int data){
    node *cur_node = new node;
    cur_node->data = data;
    cur_node->left=cur_node->right=NULL;
    return cur_node;
}
struct info{
     int ans;
     int sz;
     int mn;
     int mx;
     int isBst;
};
info func(node *root){
     if(root==NULL){
         return {0,0,INT_MAX,INT_MIN,1};
     }
     if(root->left==NULL && root->right==NULL){
        return {1,1,root->data,root->data,1};
     }
     info l=func(root->left);
     info r=func(root->right);

     info ret;
     ret.sz=(l.sz+r.sz+1);


     if(l.isBst==1 && r.isBst==1 && root->data>l.mx && root->data<r.mn){


         ret.mn=min(l.mn,min(r.mn,root->data));
         ret.mx=max(r.mx,max(l.mx,root->data));
         ret.ans = l.ans+r.ans+1;
         ret.isBst=1;
         return ret;
     }
     ret.ans = max(l.ans, r.ans);
     ret.isBst=0;
     return ret;

}
int main()
{
    node *root=NULL;
    root=create_node(60);
    root->left = create_node(65);
    root->right = create_node(70);
    root->left->left = create_node(50);
    //root->left->right = create_node(69);
   // root->left->right->left = create_node(67);
    cout<<func(root).ans<<endl;

}
/*


#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node* left;
	struct Node* right;
	Node(int data)
	{
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}
};

struct info
{
	bool isValid;
	int size, min, max;
};

info maxSize(Node* currNode, int &maxBST)
{
	if (currNode == NULL)
	{
		// isValid, size, min, max.
		return {true, 0, INT_MAX, INT_MIN};
	}


	// Information of left and right subtrees.
	info left = maxSize(currNode -> left, maxBST);
	info right = maxSize(currNode -> right, maxBST);


	info currInfo;

	currInfo.size = left.size + right.size + 1;


	currInfo.isValid = left.isValid & right.isValid;

	// Current subtree must form a BST.
	currInfo.isValid &= (currNode -> data > left.max);
	currInfo.isValid &= (currNode -> data < right.min);

	// Updating min and max for current subtree.
	currInfo.min = min(min(left.min, right.min), currNode -> data);
	currInfo.max = max(max(left.max, right.max), currNode -> data);


	if (currInfo.isValid == true)
	{
		maxBST = max(maxBST, currInfo.size);
	}

	return currInfo;
}



int main()
{
	Node *root = new Node(60);
	root->left = new Node(65);
	root->right = new Node(70);
	root->left->left = new Node(50);

	int ans = 0;
	maxSize(root , ans);
	printf(" Size of the largest BST is %d\n", ans);
	return 0;

}
*/
