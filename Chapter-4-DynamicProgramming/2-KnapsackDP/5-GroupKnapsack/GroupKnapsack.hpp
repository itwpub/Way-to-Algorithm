#ifndef TWO_DIMENSION_KNAPSACK
#define TWO_DIMENSION_KNAPSACK

#ifndef MAX
#define MAX 1024
#endif
// #include <iostream>
#include <algorithm>
using namespace std;


// f[k][j] 前 k 组重量不超过 j 的最大价值
int f[MAX][MAX];

/**
 * 物品分为 n 组
 * 第 i 组中有 group_n[i] 个物品 范围为 [ 1, group_n[i] ]
 * group[i][j] 为第 i 组中的第 j 个物品
 * 该物品 item 的价值为 item.value_ 重量为 item.weight_
 * 背包能装载的最大重量为 total_weight
*/

struct Item {
    int value_;
    int weight_;
};

bool ItemCompare(const Item & a, const Item & b)
{
    double rate_a = (double)a.value_ / (double)a.weight_;
    double rate_b = (double)b.value_ / (double)b.weight_;
    if (rate_a != rate_b)
        return rate_a > rate_b;
    else
        return a.weight_ < b.weight_;
}

int GroupKnapsack(Item group[MAX][MAX], int group_n[MAX], int n, int total_weight)
{
    // 初始化
    for (int i = 0; i < MAX; i++)
        for (int j = 0; j < MAX; j++)
            f[i][j] = 0;

    // 对所有分组进行排序
    for (int i = 1; i <= n; i++) {
        group[i];
        sort( (Item*)group[i] + 1, (Item*)group[i] + 1 + group_n[i], ItemCompare );
        group[i];
    }

    // 第 k 组物品
    for (int k = 1; k <= n; k++) {
        // 一组中的第 i 个物品
        for (int i = 1; i <= group_n[k]; i++) {
            // 重量不超过 j
            for (int j = 0; j <= total_weight; j++) {
                // 在同一组 k 中的不同物品 i 之间是互斥的
                // 至多只能选择一个
                // 选择物品 i 和前一个物品 i-1 之中价值最大的
                int tmp;
                if (j >= group[k][i].weight_) {
                    tmp = max( f[k-1][j], f[k-1][ j - group[k][i].weight_ ] + group[k][i].value_ );
                } else {
                    tmp = f[k-1][j];
                }
                f[k][j] = max( f[k][j], tmp );
            }
        }
    }

    /*
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= total_weight; j++) {
            cout << "f[" << i << "][" << j <<"]: " << f[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl << endl;
    */

    return f[n][total_weight];
}


#endif
