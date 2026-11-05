#include<bits/stdc++.h>
using namespace std;
int A[102][102]={0};
int d[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
int ans=0;
void bfs(int x,int y){
    queue<pair<int ,int>> q1;
    pair<int,int> t;
    int s=1,x1,y1,nx,ny,i;
    q1.push({x,y});
    while(q1.size()){
        t = q1.front();
        q1.pop();
        x1 = t.first;y1 = t.second;
        for(i=0;i<4;i++){
            nx = x1+d[i][0];ny = y1+d[i][1];
            if(A[nx][ny]==1){
                A[nx][ny] = 0;
                q1.push({nx,ny});
            }
        }
    }
}
int main(){
    int m,n,i,j,c;
    char s;
    cin>>m>>n;
    for(i=1;i<=m;i++){
        for(j=1;j<=n;j++){
            cin>>s;
            if(s=='0'){
                A[i][j]=0;
            }
            else{
                A[i][j]=1;
            }
        }
    }
    for(i=1;i<=m;i++){
        for(j=1;j<=n;j++){
            if(A[i][j]==1){
                A[i][j] = 0;
                bfs(i,j);
                ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}