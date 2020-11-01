#include<iostream>
using namespace std ;
#include<queue>
#include"BinaryTreeNode.h"
#include<climits>
#include<cmath>
#include<stack>
//takeinput level wise
BinaryTreeNode <int> * takeInputLevelWise(){
	int rootData ;
	cout << "Enter root Data" << endl ;
	cin >> rootData ;
	if(rootData == -1){
		return NULL ;
	}
	BinaryTreeNode <int> * root = new BinaryTreeNode <int> (rootData);
	queue<BinaryTreeNode<int>*>pendingNodes ;
	pendingNodes.push(root);
	while(pendingNodes.size()!= 0){
		BinaryTreeNode<int> *front = pendingNodes.front();
		pendingNodes.pop();
		cout << "Enter the left Child of"<< front->data << endl ;
		int leftChild ; 
		cin >> leftChild ;
		if(leftChild != -1){
			BinaryTreeNode<int> * child = new BinaryTreeNode<int>(leftChild);
			front ->left = child ;
			pendingNodes.push(child);
		}
		cout << "Enter the rigt Child of "<< front ->data << endl ;
		int rightChild ;
		cin >> rightChild ;
		if(rightChild != -1){
			BinaryTreeNode<int> * child = new BinaryTreeNode<int>(rightChild);
			front ->right = child ;
			pendingNodes.push(child);
		}
	}
		return root ;
}
//Print output levelwise 
void printLevelWise(BinaryTreeNode<int> * root ) {
	
	if(root == NULL){
		return ;
	}
	queue<BinaryTreeNode<int>*>q ;
	q.push(root) ;
	while(q.size() != 0){
		BinaryTreeNode<int> * child = q.front();
		cout << child ->data << " :" ;
		q.pop();
		if(child ->left != NULL){
			q.push(child->left);
			cout << " L : " << child->left->data << " ," ;
		}
		else
		cout << "L :-1," ;
		if(child->right != NULL){
			q.push(child->right);
			cout << "R : " << child ->right->data ;
		}
		else
		cout << "R: -1" ;
		cout << endl ;
	}
}
//count the number of nodes
int numNodes(BinaryTreeNode <int> * root ){
	if(root == NULL){
		return 0 ;
	}
	return 1+numNodes(root->left)+numNodes(root->right);
}
//check whether the given root is presnet or not 
bool isNodePresent(BinaryTreeNode<int>*root, int x ){
	if(root == NULL){
		return false ;
	}
	if(root->data == x){
		return true ;
	}
	bool ans1 = isNodePresent(root->left,x);
	if(ans1){
		return true ;
	}
	bool ans2 = isNodePresent(root->right,x);
	return ans2;
}
//calculate the height of the binary tree
int height(BinaryTreeNode<int> * root){
	if(root ==NULL){
		return 0 ;
	}
	else {
		int lheight = height(root->left);
		int rheight = height(root->right);
		if(lheight>rheight)
			return (1+lheight);
			else
			return (1+rheight);
	}
}
//find the mirror of binary tree
void mirrorBinaryTree(BinaryTreeNode<int>*root){
	if(root == NULL){
		return ;
	}
	else {
	  BinaryTreeNode<int>* temp ;
	  mirrorBinaryTree(root->left);
	  mirrorBinaryTree(root->right);
	  temp = root ->left ;
	  root->left = root->right ;
	  root->right = temp ;
	}
}
//inorder 
void inorder(BinaryTreeNode<int>*root){
	if(root == NULL){
		return ;
	}
	inorder(root->left);
	cout << root->data<<endl;
	inorder(root->right);
}
//preorder
void preorder(BinaryTreeNode<int>*root){
	if(root == NULL){
		return ;
	}
	cout << root->data << endl ;
	preorder(root->left);
	preorder(root->right);	
}
//Diameter of the binary tree
int diameter (BinaryTreeNode<int>*root){
	if(root == NULL){
		return 0 ;
	}
	int option1 = height(root->left);
	int option2 = diameter(root->left);
	int option3 = diameter(root->right);
	return max(option1 , max(option2 , option3));
}
//min and max of binary tree
pair<int ,int>getMaxandMin(BinaryTreeNode<int>*root){
	if(root== NULL){
		pair<int,int> p ;
		p.first = INT_MIN ;
		p.second = INT_MIN ;
		return p ;
	}
	pair<int ,int>leftAns = getMaxandMin(root->left);
	pair<int ,int> rightAns = getMaxandMin(root->right);
	int lmax = leftAns.second;
	int lmin = leftAns.first;
	int rmax = rightAns.second;
	int rmin = rightAns.first ;
	int smax = max(lmax , max (root->data , rmax));
	int smin = min(lmin , min(root->data, rmin));
	pair<int,int> p ;
	p.first = smin ;
	p.second = smax ;
	return p ;
}
//sum of nodes
int getSum(BinaryTreeNode<int>*root){
	if(root ==NULL){
		return 0 ;
	}
	else {
		int sum = root->data + getSum(root->left)+ getSum(root->right);
		return sum ;
	}
}
//check balanced or not 
bool isBalanced(BinaryTreeNode<int>*root){
	if(root == NULL){
		return true ;
	}
	int lh = height(root->left);
	int rh = height(root->right);
	if(abs(lh-rh)>1){
		return false ;
	}
	return isBalanced(root->left) && isBalanced(root->right);
}
//level order traversal
void printLeveWise(BinaryTreeNode<int>*root){
	if(root == NULL){
		return ;
	}
	queue<BinaryTreeNode<int>*> q ;
	q.push(root);
	while(q.size()!=0){
		int s = q.size();
		while(s--){
			BinaryTreeNode<int>*child = q.front();
			q.pop();
			cout << child->data << " ";
			if(child->left != NULL)
			q.push(child->left);
			if(child->right != NULL)
			q.push(child->right);
		}
			cout << endl ;
	}
}

//zig zag tree
void zigZagTree(BinaryTreeNode<int>*root){
	if(root == NULL){
		return ;
	}
	stack<BinaryTreeNode<int>*>s1;
	stack<BinaryTreeNode<int>*>s2 ;
	s1.push(root);
	while((!s1.empty()) || (!s2.empty())){
	while(!s1.empty()){
		BinaryTreeNode<int>*top = s1.top();
		s1.pop();
		cout << top->data << " " ;
		if(root->left !=NULL)
			s2.push(top->left);
		if(root->right != NULL)
		    s2.push(top->right);
		}
		cout << endl;
		while(!s2.empty()){
			BinaryTreeNode<int>*top = s2.top();
			s2.pop();
			cout <<top->data <<" ";
			if(top->right != NULL)
			s1.push(top->right);
			if(top->left != NULL)
			s1.push(top->left);
		}
		cout << endl ;
	}
}

int main (){
	BinaryTreeNode <int> * root = takeInputLevelWise();
	printLevelWise(root) ;
    cout <<	"The Number OF Nodes are"<<" "<<numNodes(root) << endl ;
    cout << "Enter the value to be checked"<<endl ;
    int a ;
	cin >> a ;
    cout << isNodePresent(root , a) << endl ;
    cout <<"The height of node is"<< " "<<height(root) << endl ;
    BinaryTreeNode<int>* root1 = root ;
    mirrorBinaryTree(root1);
    cout << "The Mirror Image of the Given Tree"<< endl ;
    printLevelWise(root1);
    BinaryTreeNode<int>* root2 = root ;
    inorder(root2);
    cout << "The Inorder of the Given Tree" << endl ;
    printLevelWise(root2);
    BinaryTreeNode<int>* root3 = root ;
    preorder(root3);
    cout << "The Preorder of the given tree"<<endl ;
    printLevelWise(root3);
    cout << "The Diameter of the tree is" <<" " <<diameter(root)<<endl;
    cout << "The Sum of Nodes is "<< " "<< getSum(root) << endl ;
    if(isBalanced(root)){
    	cout << "The given Tree is balanced"<<endl ;   	
	}
	else{
		cout << "The given tree is not balanced"<<endl ;
	}
	cout << "The levelwise printing of the given tree"<<endl;
	printLeveWise(root);
	cout << "The ZigZag Tree is as follows " << endl;
	zigZagTree(root) ;
    
    
	//1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
}
