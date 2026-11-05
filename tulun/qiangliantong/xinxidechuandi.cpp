#include<iostream>
#include<vector>
using namespace std;
const int N=1002;
vector<int> g[N];
int dfn;int numb;int ans;
int stack[N];int top=1;int n;
int rudu[N];int low[N];int num[N];int liant[N];
void tarjan(int s){
    int i,v;
    dfn++;
    num[s] = dfn;low[s]=dfn;
    stack[top]=s;top++;
    for(i=0;i<g[s].size();i++){
        v = g[s][i];
        if(num[v]==0){
            tarjan(v);
            low[s] = min(low[s],low[v]);
        }
        else if(!liant[v]){
            low[s] = min(low[s],num[v]);
        }
    }
    if(low[s]==num[s]){
        numb++;
        while(1){
            top--;
            liant[stack[top]]=numb;
            if(stack[top]==s){
                break;
            }
        }
    }
}
void jisuan(){
    int i,j,v;
    for(i=1;i<=n;i++){
        if(num[i]==0){
            tarjan(i);
        }
    }
    for(i=1;i<=n;i++){
        for(j=0;j<g[i].size();j++){
            v = g[i][j];
            if(liant[i]!=liant[v]){
                rudu[liant[v]]++;
            }
        }
    }
    for(i=1;i<=numb;i++){
        if(rudu[i]==0){
            ans++;
        }
    }
    cout<<ans;
}
int main(){
    int i,j,a;
    cin>>n;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            cin>>a;
            if(a){
                g[i].push_back(j);
            }
        }
    }
    jisuan();
    return 0;
}
