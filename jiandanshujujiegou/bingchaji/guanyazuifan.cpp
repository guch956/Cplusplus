#include<iostream>
#include<algorithm>
const int N=40002;const int M=100002;
struct edge{
    int v1;
    int v2;
    int w;
};
bool bijiao(edge & e1,edge & e2){
    return e2.w<e1.w;
}
edge g[M];
int s[N];
int find_set(int x){
    if(s[x]!=x) s[x]=find_set(s[x]);
    return s[x];
}
void hebing(int x,int y){
    int a=find_set(x),b=find_set(y);
    if(a!=b){
        s[a]=b;
    }
}
int main(){
    using namespace std;
    int i,n,m;
    cin>>n>>m;
    for(i=1;i<=2*n;i++){
        s[i]=i;
    }
    for(i=0;i<m;i++){
        cin>>g[i].v1>>g[i].v2>>g[i].w;
    }
    sort(g,g+m,bijiao);
    for(i=0;i<m;i++){
        hebing(g[i].v1,g[i].v2+n);
        hebing(g[i].v2,g[i].v1+n);
        if(find_set(g[i].v1)==find_set(g[i].v1+n)){
            cout<<g[i].w;
            return 0;
        }
    }
    cout<<0;
    return 0;
}