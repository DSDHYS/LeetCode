#include<bits/stdc++.h>
using namespace std;
/**
 * @brief 两数之和
 * 
 * @param nums 
 * @param target 
 * @return vector<int> 
 */
vector<int> twoSum(vector<int>& nums,int target)
{
    #if 0 //暴力解法
    int i,j;
    for(i=0;i<nums.size()-1;i++)
    {
        for(j=i+1;j<nums.size();j++)
        {
            if(nums[i]+nums[j]==target)
            {
                return{i,j};
            }
        }
    }
    return {i,j};
    #endif
    #if 1 //哈希算法
    unordered_map<int,int> hashtable;

    for(int i=0;i<nums.size();i++)
    {
        auto it=hashtable.find(target-nums[i]);
        if(it!=hashtable.end())
        {
            return {it->second,i};
        }
        hashtable[nums[i]]=i;

    }
    return {};
    #endif

};
int main()
{
    vector<int> num={3,2,4};
    vector<int> index=twoSum(num,6);
    cout<<index[0]<<endl;
    cout<<index[1]<<endl;

};
