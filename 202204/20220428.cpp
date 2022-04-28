//
// Created by aldlss on 2022/4/28.
//

//905. 按奇偶排序数组
//简单题，偷懒的我一个sort打发了，nlogn其实不是很友善
//题目有n的写法，但是就是懒多捏，n的写法也就是差不多那几种

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        sort(nums.begin(),nums.end(),[](int a,int b)->bool {return a%2<b%2;});
        return nums;
    }
};