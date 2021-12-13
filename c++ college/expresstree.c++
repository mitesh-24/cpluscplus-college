#include<iostream>
using namespace std;
class node{
    public :
    char value;
    node* left;
    node* right;
    node* next = NULL;
    node (char c)
    {
        this->value=c;
        left=NULL;
        right=NULL;
    }
    node()
    {
        left=NULL;
        right=NULL;
    }
    
}