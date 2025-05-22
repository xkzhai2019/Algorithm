#include "DirectedWeightedGraph.h"
#include <queue>
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
            
            // 初始化流量
            maxFlow = 0;
            // 初始化残量图
            this->rG = new DirectedWeightedGraph(network->getV(),true);
            for(int v=0; v<network->getV(); v++){
                for(int w: network->adj_V(v)){
                    int c = network->getWeight(v,w);
                    rG->addEdge(v,w,c);
                    rG->addEdge(w,v,0);
                }
            } 
            // 不断寻找增广路径，直至找不到
            while(1){
                 vector<int> augPath = getAugmentingPath();
                 if(augPath.size()==0) break;
                 // 计算增广路径上的最小值
                 int f = INT_MAX;
                 for(int i=1; i<augPath.size(); i++){
                    int v = augPath[i-1];
                    int w = augPath[i];
                    f = min(f,rG->getWeight(v,w));
                 }
                 maxFlow += f;
                 // 根据增广路径更新rG
                 for(int i=1; i< augPath.size();i++){
                    int v = augPath[i-1];
                    int w = augPath[i];
                    rG->setWeight(v,w,rG->getWeight(v,w)-f);
                    rG->setWeight(w,v,rG->getWeight(w,v)+f);
                 }
            }
        }

        vector<int> getAugmentingPath(){
            vector<int> res;
            queue<int> q;
            vector<int> pre = vector<int>(network->getV(),-1);
            q.push(s);
            while(!q.empty()){
                int cur = q.front();
                q.pop();
                if(cur==t) break;
                for(int next: rG->adj_V(cur)){
                    if(rG->getWeight(cur,next)>0){
                        q.push(next);
                    }
                }
            }
            return res;
        }
        int result(){
            return maxFlow;
        }

};
int main(){
    return 0;
}
