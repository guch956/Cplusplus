#include<iostream>
#include<string>
using namespace std;
const int N=500004;
string s;
int dp_min[N][3]; /*0绿,1红,2蓝*/
int dp_max[N][3];
int dfs1(int k){
    if(s[k]=='0'){
        dp_min[k][0]=dp_max[k][0]=1;
        dp_min[k][1]=dp_min[k][2]=0;
        dp_max[k][1]=dp_max[k][2]=0;
        return k;
    }
    if(s[k]=='1'){
        int c=k+1;
        int a=dfs1(c);
        dp_min[k][0]=min(dp_min[c][1],dp_min[c][2])+1;
        dp_min[k][1]=min(dp_min[c][0],dp_min[c][2]);
        dp_min[k][2]=min(dp_min[c][0],dp_min[c][1]);
        dp_max[k][0]=max(dp_max[c][1],dp_max[c][2])+1;
        dp_max[k][1]=max(dp_max[c][0],dp_max[c][2]);
        dp_max[k][2]=max(dp_max[c][0],dp_max[c][1]);
        return a;
    }
    else{
        int c = k+1;
        int a = dfs1(c);
        a++;
        int b=dfs1(a);
        dp_min[k][0]=min(dp_min[c][1]+dp_min[a][2],dp_min[c][2]+dp_min[a][1])+1;
        dp_min[k][1]=min(dp_min[c][0]+dp_min[a][2],dp_min[c][2]+dp_min[a][0]);
        dp_min[k][2]=min(dp_min[c][0]+dp_min[a][1],dp_min[c][1]+dp_min[a][0]);
        dp_max[k][0]=max(dp_max[c][1]+dp_max[a][2],dp_max[c][2]+dp_max[a][1])+1;
        dp_max[k][1]=max(dp_max[c][0]+dp_max[a][2],dp_max[c][2]+dp_max[a][0]);
        dp_max[k][2]=max(dp_max[c][1]+dp_max[a][0],dp_max[c][0]+dp_max[a][1]);
        return b;
    }
}
int main(){
    cin>>s;
    dfs1(0);
    cout<<max(dp_max[0][0],max(dp_max[0][1],dp_max[0][2]))<<' '<<min(dp_min[0][0],min(dp_min[0][1],dp_min[0][2]));
    return 0;
}