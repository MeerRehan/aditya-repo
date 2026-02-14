
#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    map<int, bool> visited;
    map< int, list <int> > adj;
    void addEdge(int v, int w);
    void DFS(int v);
};
 
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); 
    adj[w].push_back(v);
}
 
void Graph::DFS(int v)
{
    visited[v] = true;
    cout << v << " ";
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
    {
        if (!visited[*i])
        {
            DFS(*i);
        }
    }
}
 
// Driver code
int main()
{
   int V,m,x,y,k;
	cout<<"Enter no of Vertex ad edges:";
	cin>>V>>m;
  	Graph g;
  	
  	for(int i=0;i<m;i++)
  	{
  		cin>>x>>y;
  		g.addEdge(x,y);
  	}
  	cout<<"Enter Stating Vertex:";
    cin>>k;
	cout << "Following is Depth First Traversal"
            " (starting from vertex "<<k<<")\n";
    
    g.DFS(k);
 
    return 0;
}
 
// improved by Vishnudev C
