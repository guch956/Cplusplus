#include<iostream>
struct tree{
    tree* parent;
    tree* brother;
    tree* child;
};
int main(){
    using namespace std;
    int n;
    tree * t;
    cin>>n;
    t = new tree[n];
    
}