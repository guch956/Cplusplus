#include<iostream>
#include<queue>
using namespace std;
int A[52][52]={0};
int d[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
int bfs(int x,int y){
    queue<pair<int,int>> q;
    pair<int ,int> t;
    int nx,ny,i,s=1;
    q.push({x,y});
    while(q.size()){
        t = q.front();
        q.pop();
        for(i=0;i<4;i++){
            nx = t.first+d[i][0];ny = t.second+d[i][1];
            if(A[nx][ny]==1){
                A[nx][ny] = 0;
                q.push({nx,ny});
                s++;
            }
        }
    }
    return s;
}
int main(){
    int w,h,i,j,x1,y1;
    char c;
    cin>>w>>h;
    for(i=1;i<=h;i++){
        for(j=1;j<=w;j++){
            cin>>c;
            if(c=='.'){
                A[i][j] = 1;
            }
            else if(c=='#'){
                A[i][j] = 0;
            }
            else{
                A[i][j] = 0;
                x1 = i;y1 = j;
            }
        }
    }
    cout<<bfs(x1,y1);
    return 0;
}