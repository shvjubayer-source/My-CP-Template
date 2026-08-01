#include <bits/stdc++.h>
using namespace std;

struct Edge{
    int v, capacity, rev;
};


vector<vector<Edge>> graph;
vector<int> parent;
vector<int> parentEdge;

void addEdge(int u, int v, int cap){
    graph[u].push_back({v, cap, (int)graph[v].size()});
    graph[v].push_back({u, 0, (int)graph[u].size()-1});
}

bool bfs(int s, int t){
    for(auto &i:parent) i=-1;

    queue<int> q;
    q.push(s);
    parent[s]=s;

    while(!q.empty()){
        int u=q.front();
        q.pop();

        for (int i=0; i<graph[u].size(); i++) {
            Edge &e=graph[u][i];

            if(parent[e.v]==-1 && e.capacity>0) {
                parent[e.v]=u;
                parentEdge[e.v]=i;

                if(e.v==t) return true;

                q.push(e.v);
            }
        }
    }

    return false;
}

int maxFlow(int s, int t){
    int flow=0;

    while(bfs(s, t)){

        int pathFlow=INT_MAX;

        for (int v=t; v!=s; v=parent[v]) {
            int u=parent[v];
            Edge &e=graph[u][parentEdge[v]];
            pathFlow=min(pathFlow, e.capacity);
        }

        for (int v=t; v!=s; v=parent[v]) {
            int u=parent[v];

            Edge &e=graph[u][parentEdge[v]];
            e.capacity-=pathFlow;

            graph[v][e.rev].capacity+=pathFlow;
        }

        flow+=pathFlow;
    }

    return flow;
}

struct Flight{
    string name;
    string st;
    string dest;

    int dept_time;
    int arrive_time;

};

int toTime(string s){
    int t=(s[0]-'0')*10+(s[1]-'0');
    t=t*60;
    t+=10*(s[3]-'0')+(s[4]-'0');

    return t;
}


int main(){
    int n;
    cin>>n;

    graph.resize(2*n+2);
    parent.resize(2*n+2);
    parentEdge.resize(2*n+2);

    vector<Flight> F(n); 

    for(int i=0; i<n; i++){
        cin>>F[i].name>>F[i].st>>F[i].dest;
        
        string emni1, emni2;
        cin>>emni1>>emni2;

        F[i].dept_time=toTime(emni1);
        F[i].arrive_time=toTime(emni2);

    }

    for(int i=1; i<=n; i++) addEdge(0, i, 1);

    for(int i=n+1; i<=2*n; i++) addEdge(i, 2*n+1, 1);

    for(int i=0; i<n; i++){

        for(int j=0; j<n; j++){

            if(i==j) continue;
            
            if(F[i].dest==F[j].st && F[i].arrive_time+180<=F[j].dept_time){
                addEdge(1+i, n+1+j, 1);
            }
        }

    }

    cout<<"Number of Aircraft: "<<n-maxFlow(0, 2*n+1)<<endl;

    vector<int> nxt(n, -1);  
    vector<bool> starters(n, true);


    for(int i=0; i<n; i++){

        for(auto &e : graph[1+i]){

            if(e.capacity==0 && n+1<=e.v && e.v<=2*n){
                nxt[i]=e.v-n-1;
                starters[e.v-n-1]=false;
            }
        }
    }

    int aircraft=1;

    for(int i=0; i<n; i++){
        if(starters[i]){

            cout<<"Aircraft "<<aircraft<<": ";

            for(int cur=i; cur!=-1; cur=nxt[cur]){
                cout<<F[cur].name;

                if(nxt[cur]!=-1) cout<<" -> ";
            }

            aircraft++;
            cout<<endl;
        }
    }

    return 0;
}