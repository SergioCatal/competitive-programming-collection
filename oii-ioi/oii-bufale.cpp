//Lotito Francesco 100/100
#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;

bool cmp(pair<int, int> a, pair<int,int> b)
{
    return (a.first>b.first); //ordine decrescente per differenza
}

long long solve(int N, int *M, int *P)
{
    long long sm=0, sp=0;
    pair<int,int> d[N];
    for(int i=0;i<N;i++) { d[i].first=M[i]-P[i]; d[i].second=i; } //salvo differenza in first e poisizone in second
    nth_element(d,d+N/2,d+N, cmp);
    for(int i=0;i<N/2;i++) sm+=M[d[i].second]; //differenza maggiore a sm
    for(int i=N/2;i<N;i++) sp+=P[d[i].second]; //differenza minore a sp
    return sm+sp;
}

