#include <iostream>
#include "DirectedGraph.h"
class BipartitionDetection{
    private:
        DirectedGraph *g;
        bool *visited;
        vector<int> colors;
        bool Bipartite;

        bool dfs(int v, int color){ // 返回是否是二分图
            visited[v] = true;
            colors[v] = color;
            for(int w: g->adj_V(v)){
                if(!visited[w]){
                    if(!dfs(w,1-color))
                        return false;
                }else if(colors[w]==colors[v]){
                    return false;
                }
            }
            return true;
        }
    public:
        BipartitionDetection(DirectedGraph *g){
            this->g = g;
            visited = new bool[g->getV()]{false};
            colors = vector<int>(g->getV(),-1);
            Bipartite = true;
            for(int v= 0; v<g->getV();v++){
                if(!visited[v]){
                   if(!dfs(v,0)){
                       Bipartite = false;
                       break;
                   }
                }
            }
        }
        bool isBipartite(){
            return Bipartite;
        }
        vector<int> getcolors(){
            return colors;
        }
};
