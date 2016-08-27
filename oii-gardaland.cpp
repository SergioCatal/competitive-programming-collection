//Lotito Francesco, 5/5
#include<iostream>
#include<fstream>
using namespace std;
int N, L;
ifstream in("input.txt");
ofstream out("output.txt");

int main()
{
    in>>N>>L;
    int p[N];
    for(int i=0;i<N;i++)in>>p[i];
    for(int i=0;i<L;i++)
    {
        int ln, la;
        in>>ln>>la;
        p[ln]-=la;
    }
    int cont=0;
    for(int i=0;i<N;i++)if(p[i]!=0)cont++;
    out<<cont;
    for(int i=0;i<N;i++)if(p[i]!=0)out<<i<<" "<<p[i];
    return 0;
}
