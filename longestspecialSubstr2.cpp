#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
};

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
  int maximumLength(string s) {
        unordered_map<string, long long> map;
        int res = -1;
        long long i = 0;
        for(long long j=0;j<=s.size();j++)
        {
            if(j==s.size() || s[j] != s[i])
            {
                long long c = j-i;
            
                for(long long k = 1;k<=c;k++)
                {
                    //if we already have till now largest possible length of substring we dont need to store the substrings
                    //less than res length
                    if(j-i > res)
                    {
                        map[s.substr(i,j-i)] += k;
                        if(map[s.substr(i,j-i)] >= 3) res = j-i > res ? j-i :res;
                    }
                    i++;
                }
                i = j;
            }
        }
        
        return res;
    }
int main()
{
}