#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

const int dx[4] = {0,1,0,-1};
const int dy[4] = {1,0,-1,0};

char maze[102][102];
int minTurns[102][102][4];// 记录各个位置在4个方向的最小拐弯次数
// minTurns[tx][ty][0]: 到达tx,ty时，朝向为东的最小拐弯次数
// minTurns[tx][ty][1]: 到达tx,ty时，朝向为南的最小拐弯次数
// minTurns[tx][ty][2]: 到达tx,ty时，朝向为西的最小拐弯次数
// minTurns[tx][ty][3]: 到达tx,ty时，朝向为北的最小拐弯次数

int pre[102][102][4][3];  // 记录前驱
// pre[tx][ty][id][0]: 前一个状态的x
// pre[tx][ty][id][1]: 前一个状态的y
// pre[tx][ty][id][2]: 前一个状态的朝向
int n;
int head,tail;
int q[40001][4]; // 2维数组模拟队列 0: x, 1: y, 2: direction, 3: Turns


void printResult(int x, int y, int dir){// 横纵坐标以及朝向
    int res[40001][2];
    int turns = 0;
    res[0][0] = x;
    res[0][1] = y;
    while(x!=1 || y!=1){
        int tx = pre[x][y][dir][0];
        int ty = pre[x][y][dir][1];
        dir = pre[x][y][dir][2];
        turns++;
        res[turns][0]=tx;
        res[turns][1]=ty;
        x = tx;
        y = ty;
    }
    for(int i=turns; i>=0;i--){
        cout << "(" << res[i][0] << ","<<res[i][1]<<")-->";
    }
    cout << "(" << n << "," << n << ")"<<endl;
}
void bfs(){
    memset(q,0,sizeof(q));
    memset(minTurns,10,sizeof(minTurns));// 起始值将是非常大的数字
    memset(pre,0,sizeof(pre));

    q[0][0] = 1;
    q[0][1] = 1;
    q[0][2] = 0; // East;
    q[0][3] = -1;
    q[1][0] = 1;
    q[1][1] = 1;
    q[1][2] = 1; // south;
    q[1][3] = -1;
    head = 0;
    tail = 1;
    minTurns[1][1][0] = -1;
    minTurns[1][1][1] = -1;

    while(head<=tail){
        int x = q[head][0];
        int y = q[head][1];
        int dir = q[head][2];
        int turns = q[head][3];
        head++;
        int tx = x;
        int ty = y;
        while(true){
            tx += dx[dir];
            ty += dy[dir]; // 一直向前，直到撞墙
            if(maze[tx][ty]=='*'){
                break;
            }
            if(tx==n && ty==n){
                printResult(x,y,dir);
                return;
            }
            for(int i=0; i<2; i++){ // 判断能否拐弯（左拐/右拐）
                int id = (dir + 3 - i*2)%4;
                // 0东 1南 2西 3北
                // 朝左拐：+3对4取余
                // 朝右拐：+1对4取余
                // 0 --> 3 和 1  当前朝东0，左拐朝北3/右拐朝南1
                // 1 --> 0 和 2  当前朝南1，左拐朝东0/右拐朝西2
                // 2 --> 1 和 3  当前朝西2，左拐朝南1/右拐朝北3
                // 3 --> 2 和 0  当前朝北3，左拐朝西2/右拐朝东0
                // 判断能否拐弯 以及 当前坐标有没有被扩展过
                if(maze[tx+dx[id]][ty+dy[id]]=='.' && minTurns[tx][ty][id] > turns + 1){
                    // 若有路，且没有被判断过，则生成新状态，更新hash表，以及前驱
                    tail++;
                    q[tail][0] = tx;
                    q[tail][1] = ty;
                    q[tail][2] = id;
                    q[tail][3] = turns + 1;
                    minTurns[tx][ty][id] = turns + 1;
                    pre[tx][ty][id][0] = x;
                    pre[tx][ty][id][1] = y;
                    pre[tx][ty][id][2] = dir;
                }
            }
        }
    }
}


int main(){
    ifstream fin("2.in");
    fin>>n;
    for(int i=0;i<=n+1;i++){
        string s;
        fin>>s;
        for(int j=0;j<=n+1;j++){
            maze[i][j] = s[j];
        }
    }
    fin.close();
    bfs();
    
    cout << "Total State: "<< tail << endl;
    return 0;
}
