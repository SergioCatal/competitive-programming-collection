//Lotito Francesco 100/100
#include<fstream>
#include<iostream>
#include<algorithm>
using namespace std;
ifstream in("input.txt");
ofstream out("output.txt");
int A, B;
bool vis[32001];

int main()
{
    in>>A>>B;
    int pos=0;
    int cont=0;
    while(!vis[pos])
    {
        //visito posizione e la conto
        vis[pos]=true;
        cont++;
        //calcolo la successiva
        pos=(pos+B)%A;
    }
    out<<cont;
    //secondo problema
    bool fine=false;
    B=20;
    while(!fine)
    {
        fill(vis, vis+32001, false);
        pos=0;
        cont=0;
        while(!vis[pos])
        {
            //visito posizione e la conto
            vis[pos]=true;
            cont++;
            //calcolo la successiva
            pos=(pos+B)%A;
        }
        if(cont==A)fine=true;
        else B++;
    }
    out<<" "<<B;
    in.close();
    out.close();
}
