//Lotito Francesco 100/100
#include<fstream>
using namespace std;
ifstream in("input.txt");
ofstream out("output.txt");
int N, T, P;
int m[2001][2001];
int taskValue[2001];

typedef struct cont
{
	int ID;
	int punteggio;
	int risolti;
} cont;

cont c[2001];

int main()
{
	for(int i=0;i<=2000;i++) 
	{
		c[i].ID=0;
		c[i].punteggio=0;
		c[i].risolti=0;
	}
	in>>N>>T>>P;
	//INPUT
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<T;j++)
		{
			in>>m[i][j];
		}
	}
	//CALCOLO VALORI TASK
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<T;j++)
		{
			if(m[i][j]==0) taskValue[j]++;
		}
	}
	//CALCOLO PUNTEGGIO CONTESTANTS
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<T;j++)
		{
			if(m[i][j]==1) { c[i].punteggio+=taskValue[j]; c[i].risolti++; }
			c[i].ID=i+1;
		}
	}
	//ORDINO
	for(int i=0;i<N-1;i++)
	{
		for(int j=i;j<N;j++)
		{
			if(c[i].punteggio<c[j].punteggio)
			{
				cont t=c[i];
				c[i]=c[j];
				c[j]=t;
			}
			else if(c[i].punteggio==c[j].punteggio)
			{
				if(c[i].risolti<c[j].risolti)
				{
					cont t=c[i];
					c[i]=c[j];
					c[j]=t;
				}
				else if(c[i].risolti==c[j].risolti)
				{
					if(c[i].ID>c[j].ID)
					{
						cont t=c[i];
						c[i]=c[j];
						c[j]=t;
					}
				}
				
			}
		}
	}
	
	for(int i=0;i<N;i++)
	{
		if(c[i].ID==P) out<<c[i].punteggio<<" "<<i+1<<endl;
	}
	
}
