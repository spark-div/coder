#include <iostream>

using namespace std;
const int V=6;
//�������� ��������
void Dijkstra(int GR[V][V], int st)
{
	int distance[V], count, index, i, u, m=st+1;
	bool visited[V];
	for (i=0; i<V; i++)
	{
		distance[i]=INT_MAX; visited[i]=false;
	}
	distance[st]=0;
	for (count=0; count<V-1; count++)
	{
		int min=INT_MAX;
		for (i=0; i<V; i++)
			if (!visited[i] && distance[i]<=min)
			{
				min=distance[i]; index=i;
			}
			u=index;
			visited[u]=true;
			for (i=0; i<V; i++)
				if (!visited[i] && GR[u][i] && distance[u]!=INT_MAX &&
					distance[u]+GR[u][i]<distance[i])
					distance[i]=distance[u]+GR[u][i];
	}
	cout<<"Route cost:\t\n";
	for (i=0; i<V; i++) if (distance[i]!=INT_MAX)
		cout<<m<<" > "<<i+1<<" = "<<distance[i]<<endl;
	else cout<<m<<" > "<<i+1<<" = "<<"no route"<<endl;
}
//������� �������
void main()
{
	int start, GR[V][V]={
		{0, 1, 4, 0, 2, 0},
		{0, 0, 0, 9, 0, 0},
		{4, 0, 0, 7, 0, 0},
		{0, 9, 7, 0, 0, 2},
		{0, 0, 0, 0, 0, 8},
		{0, 0, 0, 0, 0, 0}};
		cout<<"Start vert >> "; cin>>start;
		Dijkstra(GR, start-1);
}