#include <iostream>
using namespace std;
#include <climits>
#include <vector>
#include "WeightedGraph.h"
class Dijkstra{
    private:
        WeightedGraph *g;
        int s;// 源点
        vector<int> dis;
        bool *visited; // 所有确定最短路径的点都为true
    public:
        Dijkstra(WeightedGraph *g, int s){
            this->g = g;
            g->validateVertex(s);
            dis = vector<int>(g->getV(),INT_MAX);
            dis[0] = 0;
            visited = new bool[g->getV()]{false};

            while(1){
                int cur = -1, curdis = INT_MAX;
                for(int v=0; v< g->getV(); v++){//从所有最短路径中取出最短的
                    if(!visited[v] && dis[v]<curdis){
                        curdis = dis[v];
                        cur = v;
                    }   
                }
                if(cur==-1){
                    break;
                }
                visited[cur] = true;
                for(int w: g->adj_V(cur)){
                    if(!visited[w]){
                        if(dis[w]>dis[cur]+g->getWeight(cur,w))
                            dis[w] = dis[cur] + g->getWeight(cur,w);
                    }
                }
            }
        }

        bool isConnectedTo(int v){
            g->validateVertex(v);
            return visited[v];
        }
        int distTo(int v){
            g->validateVertex(v);
            return dis[v];
        }

};

int main(){
    // 测试最大整型值
    // vector<int> vec(10,INT_MAX);
    // cout<<vec[1]<<endl;
    WeightedGraph *g = new WeightedGraph("shortest_path.txt");
    Dijkstra *dij = new Dijkstra(g,0);
    for(int v=0;v<g->getV();v++){
        cout<<"0-->"<<v<<":"<<dij->distTo(v)<<endl;
    }
    return 0;
}


