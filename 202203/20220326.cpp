#include <bits/stdc++.h>
using namespace std;

/*被迭代器坑惨了*/
class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int>num;
        int ans=0;
        for(string str:ops)
        {
            switch(str[0])
            {
                case '+':num.push_back(num[num.size()-2]+num[num.size()-1]);break;
                case 'C':num.pop_back();break;
                case 'D':num.push_back(*(num.end()-1)*2);break;
                default:
                    num.push_back(stoi(str));
                    break;
            }
        }
        for(int i:num)ans+=i;
        return ans;
    }
};

int main()
{
    Solution a;
    vector<string> w={"5","2","C","D","+"};
    printf("%d",a.calPoints(w));
    return 0;
}