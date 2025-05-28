#include "DirectedGraph.h"
#include "matchXYL.h"
class Solution {
public:
    int domino(int n, int m, vector<vector<int>>& broken) {
        vector<vector<int>> board(n,vector<int>(m,0));
        for(vector<int> p: broken){
            board[p[0]][p[1]] = 1;
        }

        DirectedGraph *g = new DirectedGraph(n*m,false);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(j+1<m && board[i][j]==0 && board[i][j+1]==0)
                    g->addEdge(i*m+j,i*m+j+1);
                if(i+1<n && board[i][j]==0 && board[i+1][j]==0)
                    g->addEdge(i*m+j,(i+1)*m+j);
            }
        }
        matchXYL *match = new matchXYL(g);
        return match->maxMatches();
    }
};

int main(){
    vector<vector<int>> broken(2,vector<int>(2,0));
    broken[0][0] = 1;
    broken[0][1] = 1;
    broken[1][0] = 0;
    broken[1][1] = 1;
    cout<<(new Solution())->domino(2,3,broken)<<endl;
    return 0;
}
