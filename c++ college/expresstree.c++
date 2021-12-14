#include<iostream>
#include<string.h>
using namespace std;
class Node
{
 public:
 char data;
 Node *left, *right;
};
class ExpTree
{
 public:
 Node *root;
 ExpTree()
 {
 root = NULL;
 }
 Node *postfix_expression();
 Node *prefix_expression();
 void recursive_inorder(Node *);
 void recursive_preorder(Node *);
 void recursive_postorder(Node *);
 void nonrecursive_inorder(Node *);
 void nonrecursive_preorder(Node *);
 void nonrecursive_postorder(Node *);
};
Node * ExpTree :: postfix_expression()
{
 Node *leaf;
 int i, top = -1;
 char exp[20];
 Node *stack[20];
 cout<<"Enter the expression: ";
 cin>>exp;
 for(i=0; exp[i]!='\0'; i++)
 {
 if(isalnum(exp[i]))
 {
 leaf = new Node;
 leaf->data = exp[i];
 leaf->left = NULL;
 leaf->right = NULL;
 stack[++top] = leaf;
 }
 else
 {
 root = new Node;
 root->data = exp[i];
 root->right = stack[top--];
 root->left = stack[top--];
 stack[++top] = root;

 }
 }
 root = stack[top--];
 return root;
}
Node * ExpTree :: prefix_expression()
{
Node *n;
 int i, top=-1;
Node *stack[20];
char exp[20];
cout<<"Enter the expression: ";
cin>>exp;
//int arrsize = sizeof(exp)/sizeof(exp[0]);
int arrsize = strlen(exp);
for(i=arrsize-1; i>=0; i--)
{
n = new Node;
n->data = exp[i];
n->left = NULL;
n->right = NULL;
if(isalnum(exp[i]))
{
 stack[++top] = n;
}
else
{
 n->left = stack[top--];
 n->right = stack[top--];
stack[++top] = n;
}
}
n = stack[top--];
return n;
}
void ExpTree :: recursive_inorder(Node *root)
{
 if(root!=NULL)
 {
 recursive_inorder(root->left);
 cout<<root->data;
 recursive_inorder(root->right);
 }
}
void ExpTree ::recursive_preorder(Node *root)
{
 if(root!=NULL)
 {
 cout<<root->data;
 recursive_preorder(root->left);
 recursive_preorder(root->right);
 }
}
void ExpTree ::recursive_postorder(Node *root)
{
 if(root!=NULL)
 {
 recursive_postorder(root->left);
 recursive_postorder(root->right);
 cout<<root->data;
 }
}
void ExpTree :: nonrecursive_inorder(Node *root)
{
 Node *stack[20];
 int top = -1;
 while(root!=NULL || top!=-1)
 {
 if(root!=NULL)
 {
 stack[++top] = root;
 root = root->left;
 }
 else
 {
 root = stack[top--];
 cout<<root->data;
 root = root->right;
 }
 }
}
void ExpTree :: nonrecursive_preorder(Node *root)
{
 Node *stack[20];
 int top = -1;
 stack[++top] = root;
 while(top!=-1)
 {
 root = stack[top--];
 if(root!=NULL)
 {
 cout<<root->data;
 stack[++top] = root->right;
 stack[++top] = root->left;
 }
 }
}
void ExpTree :: nonrecursive_postorder(Node *root)
{
 Node *stack[20];
 int top=-1;
 int flag[10];
 while(top!=-1 || root!=NULL)
 {
 if(root!=NULL)
 {
 stack[++top]=root;
 flag[top]=0;
 root=root->left;
 }
 else
 {
 root=stack[top];
 if(flag[top]==1)
 {
 cout<<root->data;
 top--;
 root=NULL;
 }
 else
 {
 flag[top]=1;
 root=root->right;
 }
 }
 }
}
int main()
{
 ExpTree E, T;
 int choice;
 char ch, c;

 do
 {
 cout<<"1) Postfix Expression"<<endl;
 cout<<"2) Prefix Expression"<<endl;
 cout<<"3) Quit"<<endl;
 cout<<"\n\nEnter your choice: ";
 cin>>choice;

 switch(choice)
 {
 case 1:
 {
 E.root = E.postfix_expression();
 cout<<endl;
 cout<<"a) Recursive Inorder"<<endl;
 cout<<"b) Recursive Preorder"<<endl;
 cout<<"c) Recursive Postorder"<<endl;
 cout<<"d) Non recursive Inorder"<<endl;
 cout<<"e) Non recursive Preorder"<<endl;
 cout<<"f) Non recursive Postorder"<<endl;
 cout<<"g) Quit"<<endl;
 do
 {
 cout<<"\nEnter operation: ";
 cin>>ch;
 switch(ch)
 {
 case 'a':
 {
 cout<<"Recursive Inorder expression: ";
 E.recursive_inorder(E.root);
 break;
 }
 case 'b':
 {
 cout<<"Recursive Prerder expression: ";
 E.recursive_preorder(E.root);
 break;
 }
 case 'c':
 {
 cout<<"Recursive Postorder expression: ";
 E.recursive_postorder(E.root);
 break;
 }
 case 'd':
 {
 cout<<"Non recursive Inorder expression: ";
 E.nonrecursive_inorder(E.root);
 break;
 }
 case 'e':
 {
 cout<<"Non recursive Preorder expression: ";
 E.nonrecursive_preorder(E.root);
 break;
 }
 case 'f':
 {
 cout<<"Non recursive Postorder expression: ";
 E.nonrecursive_postorder(E.root);
 break;
 }
 }
 }while(ch != 'g');
 break;
 }
 case 2:
 {
 T.root = T.prefix_expression();
 cout<<endl;
 cout<<"a) Recursive Inorder"<<endl;
 cout<<"b) Recursive Preorder"<<endl;
 cout<<"c) Recursive Postorder"<<endl;
 cout<<"d) Non recursive Inorder"<<endl;
 cout<<"e) Non recursive Preorder"<<endl;
 cout<<"f) Non recursive Postorder"<<endl;
 cout<<"g) Quit"<<endl;
 do
 {
 cout<<"\nEnter operation: ";
 cin>>c;
 switch(c)
 {
 case 'a':
 {
 cout<<"Recursive Inorder expression: ";
 T.recursive_inorder(T.root);
 break;
 }
 case 'b':
 {
 cout<<"Recursive Prerder expression: ";
 T.recursive_preorder(T.root);
 break;
 }
 case 'c':
 {
 cout<<"Recursive Postorder expression: ";
 T.recursive_postorder(T.root);
 break;
 }
 case 'd':
 {
 cout<<"Non recursive Inorder expression: ";
 T.nonrecursive_inorder(T.root);
 break;
 }
 case 'e':
 {
 cout<<"Non recursive Preorder expression: ";
 T.nonrecursive_preorder(T.root);
 break;
 }
 case 'f':
 {
 cout<<"Non recursive Postorder expression: ";
 T.nonrecursive_postorder(T.root);
 break;
 }
 }
 }while(c != 'g');
 break;
 }
 }
 } while(choice != 3);

 return 0;
}