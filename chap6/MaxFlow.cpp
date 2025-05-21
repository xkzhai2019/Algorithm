#include "DirectedWeightedGraph.h"
#include <climits>
#include <cassert>
class MaxFlow{
    private:
        DirectedWeightedGraph *network; // 原始图
        int s, t;// 源点和汇点
        DirectedWeightedGraph *rG; // 残量图
        int maxFlow; // 最大流量

    public:
        MaxFlow(DirectedWeightedGraph *network, int s, int t){
            assert(network->isDirected());
            assert(network->getV()>=2);
            network->validateVertex(s);
            network->validateVertex(t);
            assert(s!=t);
            
            this->network = network;
            this->s = s;
            this->t = t;

            this->rG = new DirectedWeightedGraph(network->getV(),true);
            for(int v=0; v<network->getV(); v++){
                for(int w: network->adj_V(v)){
                    int c = network->getWeight(v,w);
                    rG->addEdge(v,w,c);
                    rG->addEdge(w,v,0);
                }
            }
            while(1){// 不断寻找增广路径，直至找不到
                 vector<int> augPath = getAugmentingPath();
                 if(augPath.size()==0) break;
                 int f = INT_MAX; // 记录增广路径的流量
                 for(int i=1; i<augPath.size(); i++){
                    int v = augPath[i-1];
                    int w = augPath[i];
                 }
            }
        }

        vector<int> getAugmentingPath(){
            vector<int> res;
            return res;
        }

};
int main(){
    return 0;
}
