//Lotito Francesco 100/100
#include<fstream>
#include<algorithm>
#include<queue>
using namespace std;
ifstream in("input.txt");
ofstream out("output.txt");
int w[2001], r[101];
int N, M;
int park[101];
queue<int> arrivi;

int main()
{
	in>>N>>M;
	int guadagno=0;
	for(int i=0;i<N;i++) in>>r[i+1];
	for(int i=0;i<M;i++) in>>w[i+1];
	for(int i=0;i<2*M;i++)
	{
		int car;
		in>>car;
		if(car>0)
		{
			arrivi.push(car);
			//se si Ã¨ liberato un posto
			for(int j=1;j<=N;j++) 
			{ 
				if(park[j]==0) 
				{
					park[j]=arrivi.front();
				    arrivi.pop();
					break;
				} 
			}
		}
		else
		{
			int posto;
			car=-car;
			for(int j=1;j<=N;j++) if(park[j]==car) posto=j;
			guadagno+=w[car]*r[posto];
			if(!arrivi.empty())
			{
				park[posto]=arrivi.front();
				arrivi.pop();
			} 
			else park[posto]=0;
		}
		
	}
	out<<guadagno;
}
