//Lotito Francesco
#include<fstream>
#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;
ifstream in("input.txt");
ofstream out("output.txt");
int N;
int medie[5000001];

void read()
{
    in>>N;
    for(int i=0;i<N;i++)
    {
        in>>medie[i];
    }
    in.close();
}

bool controlla(int primo, int secondo)
{
    for(int i=0;i<N-1;i++)
    {
        if(secondo>medie[i+1]) return false;
        int scarto=medie[i+1]-secondo;
        primo=secondo;
        secondo=medie[i+1]+scarto;
    }
    return true;
}

int main()
{
    read();
    bool continua=true;
    int primo=medie[0];
    int secondo=primo;
    int cont=0;
    while(secondo<=medie[1])
    {
        continua=controlla(primo,secondo);
        if(continua) cont++;
        primo--;
        secondo++;
    }
    out<<cont;
    out.close();
    return 0;
}
