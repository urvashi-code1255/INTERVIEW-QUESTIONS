/* (https://leetcode.com/problems/longest-common-subsequence/)

Question:- Given two strings text1 and text2, return the length of their longest common subsequence.

Approach :- 
1. Initialisation:- when any of the two strings is empty then empty subsequence will be common.
2. Code:- Starting from whole length of both strings everytime we will check if both letters are equal , if yes then adding that in length and further go for shorter length,
if not equal then we will take maximum of the lengths after discarding the uncommon letter from both strings.

*/

//  Solution 1: Using Recursion (It will give TLE)
class Solution
{
public:
    int countLength(string text1, string text2, int n, int m)
    {
        if (n == 0 || m == 0)
            return 0;

        if (text1[n - 1] == text2[m - 1])
            return 1 + countLength(text1, text2, n - 1, m - 1);

        return max(countLength(text1, text2, n, m - 1), countLength(text1, text2, n - 1, m));
    }

    int longestCommonSubsequence(string text1, string text2)
    {
        return countLength(text1, text2, text1.size(), text2.size());
    }
};

// Solution 2: Using Recursion + Memoization
class Solution
{
public:
    int t[1001][1001];
    int countLength(string text1, string text2, int n, int m)
    {
        if (n == 0 || m == 0)
            return 0;

        if (t[n][m] != -1)
            return t[n][m];

        if (text1[n - 1] == text2[m - 1])
            return t[n][m] = 1 + countLength(text1, text2, n - 1, m - 1);

        return t[n][m] = max(countLength(text1, text2, n, m - 1), countLength(text1, text2, n - 1, m));
    }

    int longestCommonSubsequence(string text1, string text2)
    {
        memset(t, -1, sizeof(t));

        return countLength(text1, text2, text1.size(), text2.size());
    }
};

// Solution 3: DP(Bottom Up)
class Solution
{
public:
    int countLength(string text1, string text2, int n, int m)
    {
        int DP[n + 1][m + 1];

        for (int i = 0; i <= n; i++)
            DP[i][0] = 0;

        for (int i = 0; i <= m; i++)
            DP[0][i] = 0;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (text1[i - 1] == text2[j - 1])
                    DP[i][j] = 1 + DP[i-1][j-1];
                else
                    DP[i][j] = max(DP[i-1][j], DP[i][j-1]);
            }
        }

        return DP[n][m];
    }

    int longestCommonSubsequence(string text1, string text2)
    {
        return countLength(text1, text2, text1.size(), text2.size());
    }
};
