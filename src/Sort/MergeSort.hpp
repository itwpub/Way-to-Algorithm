﻿#ifndef SORT_MERGE_HPP
#define SORT_MERGE_HPP 1

#ifndef MAX
#define MAX 1024
#endif


auto Merge(int s[MAX], int start, int mid, int last) -> void
{
    int t[MAX];
    int i, j, k;

    for (i = start, j = mid+1, k = start; i <= mid && j <= last; ++k) {
        if (s[i] <= s[j]) {
            t[k] = s[i];
            i++;
        } else {
            t[k] = s[j];
            j++;
        }
    }
    for (; i <= mid; ++i, ++k)
        t[k] = s[i];
    for (; j <= last; ++j, ++k)
        t[k] = s[j];

    /* copy(t+start, t +last+1, s) will also work */
    for (i = start; i <= last; ++i)
        s[i] = t[i];
}

/**
* @brief MergeSort  归并排序
* @param s[MAX]     无序序列
* @param beg        序列s的起始下标
* @param end        序列s为左闭右开区间[beg, end)
*/
void MergeSort(int s[MAX], int beg, int end)
{
    int mid = (beg + end-1) / 2;

    if (beg + 2 >= end) {
        Merge(s, beg, mid, end-1);
        return;
    }
    MergeSort(s, beg, mid+1);
    MergeSort(s, mid+1, end);
    Merge(s, beg, mid, end-1);
}

#endif
