#include <iostream>
#include <cstring>
using namespace std;
int q[513]; // 用数组模拟状态队列
int hashState[513];// 9位二进制最大值为512
int step[513]; // 各个不同状态的步数

int getHash(int state){// 倒序转成2进制
    int res = 0;
    for(int i=0; i<9;i++){
        res = res*2 + state%10;
        state = state/10;
    }
    return res;
}

int getNewState(int state, int op){
    // 1011 ----> 0 0 0 0 0 1 0 1 1
    int tmp[9];
    for(int i=0;i<9;i++){
        tmp[8-i] = state%10;
        state = state/10;
    }
    // 0 1 2
    // 3 4 5
    // 6 7 8
    tmp[op] = 1 - tmp[op];
    if(op%3!=2){
        tmp[op+1] = 1 - tmp[op+1];
    }
    if(op%3!=0){
        tmp[op-1] = 1 - tmp[op-1];
    }
    if(op<6){
        tmp[op+3] = 1 - tmp[op+3];
    }
    if(op>2){
        tmp[op-3] = 1 - tmp[op-3];
    }
    
    int res = 0;
    for(int i=0;i<9;i++){
        res = res*10 + tmp[i];
    }
    return res;
}

int bfs(int initState){ // 返回步数
    memset(q,0,sizeof(q));
    memset(step,0,sizeof(step));
    q[0]=initState;
    step[0] = 0;
    int head = 0;
    int tail = 0;
    memset(hashState,0,sizeof(hashState));
    hashState[getHash(initState)] = true;

    while(head<=tail){
        int state = q[head];
        int stateStep = step[head];
        head++;

        for(int i=0;i<9;i++){
            int tempState = getNewState(state,i);
            int tempStep = stateStep + 1;
            int tempStateHash  = getHash(tempState);
            if(hashState[tempStateHash]){
                continue;
            }
            hashState[tempStateHash] = true;
            if(tempState == 111111111){
                return tempStep;
            }
            q[++tail] = tempState;
            step[tail] = tempStep;
        }
    }
    return -1;
}

int main(){
    int initState = 0, tmp;
    for(int i=0;i<9;i++){
        cin >> tmp;
        initState = initState*10 + tmp;
    }
    cout<<bfs(initState)<<endl;
    return 0;
}
