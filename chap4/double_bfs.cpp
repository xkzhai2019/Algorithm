double_bfs(){
    初始化状态队列Q1;
    将起始状态initState插入到Q1中，initState的层数为1;
    初始化状态队列Q2;
    将目标状态termState插入到Q2中，termState层数为1;
    初始化判重哈希表hashState1, hashState2;
    修改hashState1[initState], hashState2[termState];
    当前层数level=0;
    while(Q1不空 || Q2不空){
        level++;
        while(Q1不空 && Q1头部状态的层数 <= level){
            state1 = Q1取出头部状态;
            for(当前选项 in 所有可扩展选项){
                tempState1 = state1按当前选项扩展;
                level1 = state1.leve + 1;
                如果tempState1不是合法状态或已超出边界
                    continue;
                if(tempState1在hashState2中出现过)
                    已找到解，路径为initState-...->tempState1-...->termState,返回;
                if(tempState1在hashState1中出现过)
                    重复状态，忽略;
                else
                    修改hashState1[tempState1];
                    将tempState以及level1插入到Q1末尾;
            }
        }
        // 接上
        while(Q2不空 && Q2头部状态的层数<=level){
            state2 = Q2取出头部状态;
            for(当前选项 in 所有可扩展选项){
                tempState2 = state2按当前选项反向扩展;
                level2 = state2.level+1;
                如果tempState2不是合法状态或已超出边界
                    continue;
                if(tempState2在hashState1中出现过)
                    已找到解，路径为initState-...->tempState2-...->termState,返回;
                if(tempState2在hashState2中出现过)
                    重复状态，忽略
                else
                    修改hashState2[tempState2];
                    将tempState2以及level2插入到Q2末尾;
            }
        }
    }
}

