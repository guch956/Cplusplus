#include<iostream>
struct duilie{
    int *A;
    int lenth;
    int tou;
    int wei;
};
inline int jian(int a,int n){
    return a==0?n-1:a-1;
}
inline int jia(int a,int n){
    return a==n-1?0:a+1;
}
void push(duilie & d,int x){
    int i = d.wei,b = jian(d.tou,d.lenth);
    while(i!=b && d.A[i]<x){
        i = jian(i,d.lenth);
    }
    d.wei = jia(i,d.lenth);
    d.A[d.wei] = x;
}