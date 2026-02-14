#include<bits/stdc++.h>
using namespace std;
class Graph
{
    int V;    
    list<int> *adj;  
public:
    Graph(int V); 
    void addEdge(int v, int w);
    void printGraph();
};

//Constructor
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
 
//function to add an edge to graph
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
}

void Graph::printGraph()
{
    for (int v = 0; v < V; ++v)
    {
        cout << "\n Adjacency list of vertex "<< v << "\n head->";
        for (auto x : adj[v])
           cout << x<<"  ";
        printf("\n");
    }
}

int main()
{
    Graph g(3);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.printGraph();
    return 0;
}
