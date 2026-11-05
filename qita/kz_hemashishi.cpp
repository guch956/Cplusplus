#include<iostream>
using namespace std;
struct k_tree{
    int child[9]={0,0,0,0,0,0,0,0,0};
    int parent=0;
    int cishu;
};
inline bool bijiao(k_tree & t1,k_tree & t2){
    return t1.cishu<t2.cishu;
}
int main(){
    int n,k,i,a,d=0,b;
    k_tree *t,c,*p;
    cin>>n>>k;
    t = new k_tree[2*n+1];
    p = new k_tree[9];

}