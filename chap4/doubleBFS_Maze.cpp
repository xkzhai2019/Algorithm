#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

// 0 1 2 3  分别表示向东、南、西、北各走一步
const int dx[4] = {0,1,0,-1};
const int dy[4] = {1,0,-1,0};

char maze[102][102];// 迷宫
int minTurns[102][102][4];// 记录最小拐弯次数和前驱状态的两个哈希表, 正向
int pre[102][102][4][3];  
int minTurns2[102][102][4];// 记录最小拐弯次数和前驱状态的两个哈希表，反向
int pre2[102][102][4][3];  

int n;
int head,tail,head2,tail2;
int q[40001][4]; // 队列数组，分别为0: x, 1: y, 2: direction, 3: Turns
int q2[40001][4]; // 队列数组，反向

// 倒推路径，输出结果
void printResult(int x, int y, int dir, int dir2){// 横纵坐标以及朝向
    int res[40001][2];
    int turns = 0;
    int x2 = x;
    int y2 = y;

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
    while(true){
        int tx = pre2[x2][y2][dir2][0];
        int ty = pre2[x2][y2][dir2][1];
        dir2 = pre2[x2][y2][dir2][2];
        if(tx==n && ty==n){
            break;
        }
        cout<<"("<<tx<<","<<ty<<")-->";
        x2 = tx;
        y2 = ty;
    }
    cout<<"("<<n<<','<<n<<")"<<endl;
}

void double_bfs(){
    // 初始化正向队列以及哈希表
    memset(q,0,sizeof(q));
    memset(minTurns,10,sizeof(minTurns));// 起始值将是非常大的数字
    memset(pre,0,sizeof(pre));

    // 第一个起始状态入队
    q[0][0] = 1;
    q[0][1] = 1;
    q[0][2] = 0; // East;
    q[0][3] = -1;
    // 第二个起始状态入队
    q[1][0] = 1;
    q[1][1] = 1;
    q[1][2] = 1; // south;
    q[1][3] = -1;
    head = 0;
    tail = 1;
    minTurns[1][1][0] = -1;
    minTurns[1][1][1] = -1;

    // 初始化反向队列以及哈希表
    memset(q2,0,sizeof(q2));
    memset(minTurns2,10,sizeof(minTurns2));// 起始值将是非常大的数字
    memset(pre2,0,sizeof(pre2));

    // 第一个起始状态入队
    q2[0][0] = n;
    q2[0][1] = n;
    q2[0][2] = 0; // from west;
    q2[0][3] = -1;
    // 第二个起始状态入队
    q2[1][0] = n;
    q2[1][1] = n;
    q2[1][2] = 1; // form north;
    q[1][3] = -1;
    head2 = 0;
    tail2 = 1;
    minTurns2[1][1][0] = -1;
    minTurns2[1][1][1] = -1;
    int level = -2;

    // 只要正反向两个队列中任意一个不为空，就继续循环
    while(head<=tail || head2<=tail2){
        level++;
        // 如果正向队列层数在范围内
        while(q[head][3]<=level){
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
                for(int i=0; i<2; i++){ // 判断能否拐弯（左拐/右拐）
                    int id = (dir + 3 - i*2)%4;
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

                        // 如果遇到了反向来的相同状态，就意味着找到了一条通路，可以输出
                        for(int j=0; j<2;j++){
                            if(minTurns2[tx][ty][(id+3-j*2)%4]<1000000){
                                printResult(tx,ty,id,(id+3-j*2)%4);
                                return;
                            }
                        }
                    }
                }
            }
        }

        while(q2[head2][3]<=level){
            int x = q2[head2][0];
            int y = q2[head2][1];
            int dir = q2[head2][2];
            int turns = q2[head2][3];
            head2++;
            int tx = x;
            int ty = y;
            
            while(true){
                tx -= dx[dir];
                ty -= dy[dir]; // 一直向前，直到撞墙
                if(maze[tx][ty]=='*'){
                    break;
                }
                for(int i=0; i<2; i++){ // 判断能否拐弯（左拐/右拐）
                    int id = (dir + 3 - i*2)%4;
                    if(maze[tx-dx[id]][ty-dy[id]]=='.' && minTurns2[tx][ty][id] > turns + 1){
                        // 若有路，且没有被判断过，则生成新状态，更新hash表，以及前驱
                        tail2++;
                        q2[tail2][0] = tx;
                        q2[tail2][1] = ty;
                        q2[tail2][2] = id;
                        q2[tail2][3] = turns + 1;
                        minTurns2[tx][ty][id] = turns + 1;
                        pre2[tx][ty][id][0] = x;
                        pre2[tx][ty][id][1] = y;
                        pre2[tx][ty][id][2] = dir;

                        // 如果遇到了正向来的相同状态，就意味着找到了一条通路，可以输出
                        for(int j=0; j<2;j++){
                            if(minTurns[tx][ty][(id+3-j*2)%4]<1000000){
                                printResult(tx,ty,(id+3-j*2)%4,id);
                                return;
                            }
                        }
                    }
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
    double_bfs();
    
    cout << "Total State: "<< tail + tail2<< endl;
    return 0;
}
