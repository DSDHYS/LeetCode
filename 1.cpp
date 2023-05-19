#include <iostream>
#include <iomanip>
#include <vector>	//包含向量容器头文件
#include <unordered_map>
#include <numeric>
using namespace std ;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {//哈希表的建立，有些许的复杂
        // 自定义对 array<int, 26> 类型的哈希函数
        auto arrayHash = [fn = hash<int>{}] (const array<int, 26>& arr) -> size_t {//const array<int, 26>& arr常值引用，认为花括号里的为函数
            return accumulate(arr.begin(), arr.end(), 0u, [&](size_t acc, int num) {//acc是创建了一个初值0的变量
                
                return (acc << 1) ^ fn(num);


            });
        };



        unordered_map<array<int, 26>, vector<string>, decltype(arrayHash)> mp(0, arrayHash);
        for (string& str: strs) {
            array<int, 26> counts{};//长度26的数组
            int length = str.length();
            for (int i = 0; i < length; ++i) {
                counts[str[i] - 'a'] ++;
            }
            mp[counts].emplace_back(str);//向哈希表中写入值
        }
        vector<vector<string>> ans;
        for (auto it = mp.begin(); it != mp.end(); ++it) {
            ans.emplace_back(it->second);
        }
        return ans;
    }
};
int main()
{
    Solution DSD;

    array<int, 4> arr={0,1,2,3};

    size_t b;
    size_t c=arr[0];

    b=accumulate(arr.begin(), arr.end(), 0u, [&](size_t acc, int num) {
        cout<<acc<<endl;
        return (acc+1);
    });

    vector<string> strs={"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> ans=DSD.groupAnagrams(strs);


    
};

