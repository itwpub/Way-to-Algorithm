#ifndef BRUTE_FORCE_HPP
#define BRUTE_FORCE_HPP 1

#include <vector>
#include <cstring>
using namespace std;
#ifndef MAX
#define MAX 1024
#endif

auto ArrayToVector(int s[MAX], int n) -> vector<int>
{
    vector<int> ret;
    for (int i = 0; i < n; i++)
        ret.push_back(s[i]);
    return ret;
}

auto BruteForce(int s[MAX], int n, int m) -> vector<vector<int>>
{
    vector<vector<int>> combinations;
    for (int i_0 = 0; i_0 < m; i_0++)
        for (int i_1 = 0; i_1 < m; i_1++)
            for (int i_2 = 0; i_2 < m; i_2++)
                /* ... */
                for (int i_n_1 = 0; i_n_1 < m; i_n_1++) {
                    s[0] = i_0;
                    s[1] = i_1;
                    s[2] = i_2;
                    /* ... */
                    s[n - 1] = i_n_1;
                    combinations.push_back( ArrayToVector(s, n) );
                }

    return combinations;
}


#endif
