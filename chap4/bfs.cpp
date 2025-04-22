bfs(){
    初始化状态队列Q;
    将起始状态initState插入到Q中;
    初始化状态哈希表hashState;
    修改hashState[initState];

    while(Q不为空){
        state = 从Q中取出头部状态;
        for(当前选项 in 所有可扩展选项){
            tempState = state按当前选项扩展;
            如果tempState不是合法状态或已超出边界
                continue;
            对tempState进行判重并更新hashState[tempState];
            if(tempState 符合解的条件)
                更新解，如果要求找步数最少的解，则直接返回;
            else
                将tempState插入到Q末尾;
        }
    }
}
