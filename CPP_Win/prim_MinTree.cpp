//
// Created by Mark MaMian on 16/6/2.
//
/* Prim算法生成最小生成树  */
void MiniSpanTree_Prim(MGraph MG)
{
    int min, i, j, k;
    int adjvex[MAXVEX];/* 保存相关顶点下标 */
    int lowcost[MAXVEX];/* 保存相关顶点间边的权值 */
    lowcost[0] = 0;/* 初始化第一个权值为0，即v0加入生成树 */
    /* lowcost的值为0，在这里就是此下标的顶点已经加入生成树 */
    adjvex[0] = 0;/* 初始化第一个顶点下标为0 */
    cout << "最小生成树的边为：" << endl;
    for (i = 1; i < MG.numVertexes; i++)
    {
        lowcost[i] = MG.arc[0][i];/* 将v0顶点与之有边的权值存入数组 */
        adjvex[i] = 0;/* 初始化都为v0的下标 */
    }

    for (i = 1; i < MG.numVertexes; i++)
    {
        min = INFINITY; /* 初始化最小权值为∞， */

        j = 1;
        k = 0;

        while (j < MG.numVertexes)/* 循环全部顶点 */
        {
            if (lowcost[j] != 0 && lowcost[j] < min)/* 如果权值不为0且权值小于min */
            {
                min = lowcost[j];/* 则让当前权值成为最小值 */
                k = j;/* 将当前最小值的下标存入k */
            }

            j++;
        }

        cout << "(" << adjvex[k] << ", " << k << ")" << "  "; /* 打印当前顶点边中权值最小的边 */
        lowcost[k] = 0;/* 将当前顶点的权值设置为0,表示此顶点已经完成任务 */

        for (j = 1; j < MG.numVertexes; j++)/* 循环所有顶点 */
        {
            /* 如果下标为k顶点各边权值小于此前这些顶点未被加入生成树权值 */
            if (lowcost[j] != 0 && MG.arc[k][j] < lowcost[j])
            {
                lowcost[j] = MG.arc[k][j];/* 将较小的权值存入lowcost相应位置 */
                adjvex[j] = k;/* 将下标为k的顶点存入adjvex */
            }
        }
    }
    cout << endl;
}
