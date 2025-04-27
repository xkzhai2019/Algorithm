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

void bfs() {
    queue<node> q; // 定义队列
    q.push((node){startX,startY,1});
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
                cout<<"最短路径为："<<now.l<<endl;;                
                return;
            }else{
                q.push((node){tx,ty,now.l+1});
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
