#include "BipartitionDetection.h"
#include "DirectedGraph.h"
#include <cassert>
#include <queue>
class matchXYL{
    private:
        DirectedGraph *g;
        int maxMatching = 0; // 存储最大匹配数
        vector<int> matching; // 存储谁与谁匹配
    public:
        matchXYL(DirectedGraph *g){
            BipartitionDetection *bg = new BipartitionDetection(g);
            assert(bg->isBipartite());
            this->g = g;
            vector<int> colors = bg->getcolors(); // 用颜色区分左右两边
            
            matching = vector<int>(g->getV(),-1);// 初始化匹配数组
            for(int v=0;v<g->getV();v++){
                if(colors[v]==0 && matching[v]==-1){//如果是左边没有匹配的点
                    if(bfs(v)){// 对顶点v广度优先搜索，并找到了增广路径
                        maxMatching++;
                    }
                }
            }
        }
        bool bfs(int v){// 对顶点v进行广度优先搜索，看能否找到增广路径
            queue<int> q;
            q.push(v);

            vector<int> pre = vector<int>(g->getV(),-1);
            pre[v] = v;
            while(!q.empty()){
                int cur = q.front();
                q.pop();
                for(int next: g->adj_V(cur)){
                    if(pre[next]==-1){// 该邻接的点没有被访问过
                        if(matching[next]!=-1){// 该邻接点已经匹配
                            q.push(matching[next]);
                            pre[next] = cur;
                            pre[matching[next]] = next;
                        }else{// 该邻接点没有匹配
                            pre[next] = cur;
                            // 匹配反转
                            vector<int> augPath = getAugPath(pre,v,next);
                            for(int i=0;i<augPath.size();i+=2){
                                matching[augPath[i]] = augPath[i+1];
                                matching[augPath[i+1]] = augPath[i];
                            }
                            return true;
                        }
                    }
                }

            }
            return false;
        }

        vector<int> getAugPath(vector<int> pre, int start, int end){
            vector<int> res;
            int cur = end;
            while(cur!=start){
                res.push_back(cur);
                cur = pre[cur];
            }
            res.push_back(start);
            return res;
        }

        int maxMatches(){
            return maxMatching;
        }
        bool isPerfectMatching(){
            return maxMatching*2==g->getV();
        }
};
int main(){
    DirectedGraph *g = new DirectedGraph("maxMatching.txt",false);
    matchXYL *match = new matchXYL(g);
    cout<<match->maxMatches()<<endl;
    
    DirectedGraph *g2 = new DirectedGraph("maxMatching2.txt",false);
    matchXYL *match2 = new matchXYL(g2);
    cout<<match2->maxMatches()<<endl;
    return 0;
}
