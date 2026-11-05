#include<iostream>
#include<queue>
using namespace std;
int A[102][102]={0};
int d[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int bfs(int x,int y){
    queue<pair<int,int>> q;
    pair<int,int> t;
    int nx,ny,s=1,i;
    q.push({x,y});
    while(q.size()){
        t = q.front();
        q.pop();
        for(i=0;i<4;i++){
            nx = t.first+d[i][0];ny = t.second+d[i][1];
            if(A[nx][ny]==1){
                A[nx][ny]=0;s++;
                q.push({nx,ny});
            }
        }
    }
    return s;
}
int main(){
    int m,n,i,j,max1=0;
    cin>>n>>m;
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            cin>>A[i][j];
        }
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            if(A[i][j]==1){
                A[i][j] = 0;
                max1 = max(max1,bfs(i,j));
            }
        }
    }
    cout<<max1;
    return 0;
}