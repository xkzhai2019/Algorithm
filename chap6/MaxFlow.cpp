#include "DirectedWeightedGraph.h"
#include <iostream>
#include <queue>
#include <climits>
#include <cassert>
using namespace std;
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
            queue<int> q;
            // 记录顶点是否已经入队
            vector<int> pre = vector<int>(network->getV(),-1);
            q.push(s);
            pre[s] = s;
            while(!q.empty()){
                int cur = q.front();
                q.pop();
                if(cur==t) break;
                for(int next: rG->adj_V(cur)){
                    if(pre[next]==-1 && rG->getWeight(cur,next)>0){
                        q.push(next);
                        pre[next] = cur;
                    }
                }
            }
            vector<int> res;
            if(pre[t]==-1){// s->t已无路径
                return res;
            }
            int cur = t;
            while(cur!=s){// 从终点往起点回溯
                res.push_back(cur);
                cur = pre[cur];
            }
            res.push_back(s);
            reverse(res.begin(),res.end());// 反转向量
            return res;
        }
        int result(){
            return maxFlow;
        }
        int flow(int v, int w){
            assert(network->hasEdge(v,w));
            return rG->getWeight(w,v);
        }

};
int main(){
    DirectedWeightedGraph *network = new DirectedWeightedGraph("network.txt",true);
    MaxFlow *maxflow = new MaxFlow(network,0,3);
    cout<<maxflow->result()<<endl;
    for(int v=0; v<network->getV();v++){
        for(int w: network->adj_V(v)){
            cout<<v<<"-"<<w<<":"<<maxflow->flow(v,w)<<"/"<<network->getWeight(v,w)<<endl;
        }
    }
    
    DirectedWeightedGraph *network2 = new DirectedWeightedGraph("network2.txt",true);
    MaxFlow *maxflow2 = new MaxFlow(network2,0,5);
    cout<<maxflow2->result()<<endl;
    for(int v=0; v<network2->getV();v++){
        for(int w: network2->adj_V(v)){
            cout<<v<<"-"<<w<<":"<<maxflow2->flow(v,w)<<"/"<<network2->getWeight(v,w)<<endl;
        }
    }
    return 0;
}
