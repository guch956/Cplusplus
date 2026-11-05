#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std;
const int N=1000003;
vector<int> p[N];
int q[N];
int ans;
int main(){
    int n,i,a,b,j,k,y;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d %d",&a,&b);
        p[a].push_back(b);
    }
    for(i=1;i<N;i++){
        sort(p[i].begin(),p[i].end());
        q[i]=p[i].size()-1;
    }
    for(i=1;i<N;i++){
        for(j=q[i];j>=0;j--){
            ans++;
            y = p[i][j];
            
        }
    }
}