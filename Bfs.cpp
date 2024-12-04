#include<iostream>
#include<queue>
using namespace std;

struct node{
    char visit[5];
    int distance[5];
    int pi[5];
};

void bfs(int start,int adj[][5],int num){
    node no;
    for (int i = 0;i<5;i++){
        no.visit[i] = 'w';
        no.distance[i] = -1;
        no.pi[i] = -1;
    }    
    no.visit[start] = 'g';
    no.distance[start] = 0;
    queue<int> que;
    que.push(start);

    while(!que.empty()){
        int node = que.front();
        que.pop();

        cout<<node<<" ";
        for(int neighbour = 0;neighbour < 5;neighbour++){
            if(adj[node][neighbour] == 1 and no.visit[neighbour] == 'w'){
                no.visit[neighbour] = 'g';
                no.distance[neighbour] = no.distance[node] + 1;
                no.pi[neighbour] = node;
                que.push(neighbour);
            }
        }
        no.visit[node] = 'b';
    }
}

int main(){
    int num = 5;
    int graph[5][5];
    cout<<"Enter the adj matrix";
    for(int i = 0;i<5;i++){
        for(int j = 0;j<5;j++){
            cin>>graph[i][j];
        }
    }
    int start = 0;
    cout<<"The Bfs starting from the node "<<start<<endl;
    bfs(start,graph,num);
}
