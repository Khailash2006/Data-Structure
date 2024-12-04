#include<iostream>
using namespace std;

struct Graph{
    int vertex;
    int pi[10];
    int d[10];
    int f[10];
    char color[10];
    int adj[10][10];
    int time;
};

void dfs_visit(Graph &g,int u){
    g.time++;
    g.d[u] = g.time;
    g.color[u] = 'g';
    cout<<u<<" ";
    for(int v = 0;v<g.vertex;v++){
        if(g.adj[u][v] == 1 and g.color[v] == 'w'){
            g.pi[v] = u;
            dfs_visit(g,v);
        }
    }
    g.color[u] = 'b';
    g.time++;
    g.f[u] = g.time;
}

void dfs(Graph &g){
    for(int i = 0;i<g.vertex;i++){
        g.color[i] = 'w';
        g.pi[i] = -1;
    }
    g.time = 0;
    cout << "Nodes : "<<endl;
    for (int i = 0;i<g.vertex;i++){
        if(g.color[i] == 'w') dfs_visit(g,i);
    }
}

int main(){
    Graph g;
    cout<<"Enter the no. of vertices : ";
    cin>>g.vertex;
    cout<<"Enter the adj matrix : ";
    for(int i = 0;i<g.vertex;i++){
        for(int j = 0;j<g.vertex;j++){
            cin>>g.adj[i][j];
        }
    }
    dfs(g);
}