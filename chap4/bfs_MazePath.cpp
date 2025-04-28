#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

const int deltaX[4] = {1, 0, -1 ,0};
const int deltaY[4] = {0, 1, 0, -1};

int n, m;
int maze[100][100];
bool hashState[100][100];
int startX, startY, endX, endY;

struct node{
    int x,y; // 记录状态
    int l; // 记录路径长度
};
// 从起点到每个坐标都有一条最短路径
int pre[100][100][2];// 记录每个坐标的前驱
// pre[tx][ty][0]: 前驱的x
// pre[tx][ty][1]: 前驱的y


void printPath(int x, int y){// 打印前驱
    int res[n*m][2];
    res[0][0] = x;
    res[0][1] = y;
    int k = 0;
    while(x!=startX || y!= startY){
        int tx = pre[x][y][0];
        int ty = pre[x][y][1];
        k++;
        res[k][0] = tx;
        res[k][1] = ty;
        x = tx;
        y = ty;
    }
    for(int i=k;i>=0;i--){
        cout<<"("<<res[i][0]<<","<<res[i][1]<<")-->";
    }
    cout<<"("<<endX<<","<<endY<<")"<<endl;
}


void bfs() {
    queue<node> q; // 定义队列
    q.push((node){startX,startY,1});
    memset(pre,0,sizeof(pre));
    memset(hashState, 0, sizeof(hashState));
    hashState[startX][startY] = true;

    while(!q.empty()){
        node now = q.front();// 取队首状态
        q.pop();// 将队首移出队列

        for(int i=0; i<4; i++){
            int tx = now.x + deltaX[i];
            int ty = now.y + deltaY[i];
            if(tx < 1 || tx > n || ty < 1 || ty > m || maze[tx][ty])
                continue; 
            if(hashState[tx][ty])
                continue;
            hashState[tx][ty] = true;
            if(tx==endX && ty==endY){// 到达终点
                printPath(now.x,now.y);
                cout<<"最短路径为："<<now.l<<endl;;                
                return;
            }else{
                q.push((node){tx,ty,now.l+1});
                pre[tx][ty][0] = now.x;
                pre[tx][ty][1] = now.y;
            }
            
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> maze[i][j];
    cin >> startX >> startY >> endX >> endY;
    bfs();
    return 0;
}
