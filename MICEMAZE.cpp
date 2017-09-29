#include<stdio.h>
#include<list>
#include<iostream>
#include<deque>
#include<limits.h>
#include<queue>
#include<bits/stdc++.h>
 
 using namespace std;

typedef pair<int,int> ipair;

class graph{
	private:
		int v;
		list<pair<int,int> > *adj;
		//int dist[v];
	public:
		graph(int v);
		void addEdge(int u,int p,int w);
		int sp(int s);
};

graph::graph(int v)
{
	this->v=v;
	adj=new list<pair<int,int> >[v];
	
	
}
void graph::addEdge(int u,int p,int w)
{
	adj[u].push_back(make_pair(p,w));
	//adj[v].push_back(make_pair(u,w));
}

int graph::sp(int s)
{
	priority_queue<ipair,vector<ipair>,greater<ipair> > pq;
	
	vector<int> dist(v,INT_MAX);
	pq.push(make_pair(0,s));
	dist[s]=0;
	while(!pq.empty())
	{
		int u=pq.top().second;
		pq.pop();
		list<pair<int,int> >::iterator t;
		for(t=adj[u].begin();t!=adj[u].end();t++)
		{
			int V=(*t).first;
			int weight=(*t).second;
			
			if(dist[V]>dist[u]+weight)
			{
				dist[V]=dist[u]+weight;
				pq.push(make_pair(dist[V],V));
			}
		}
	}
     if(dist[1]<=5)
     return 1;
     else 
     return 0;
}

int main()
{
	int count;
	graph g(4);
	g.addEdge(0,1,1);
	g.addEdge(0,2,1);
	g.addEdge(1,0,1);
	g.addEdge(1,3,1);
	g.addEdge(2,0,1);
	g.addEdge(2,3,1);
	g.addEdge(3,1,1);
	g.addEdge(3,2,1);
	count+=g.sp(0);
	count+=g.sp(1);
	//count+=g.sp(2);
	count+=g.sp(3);
	
	cout<<"number of mice exit:"<<count+1;
	
	return 0;
}
