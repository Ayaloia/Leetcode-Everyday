//
// Created by aldlss on 2022/3/31.
//

//该说不愧是简单题吗，暴力都能直接过，只能说数据量还是小了，应该是会有更好的算法的吧（？

class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int>ans;
        int bit=0,mark=0;
        for(int i=left;i<=right;++i)
        {
            mark=i;
            while(mark)
            {
                bit=mark%10;
                if(!bit||i%bit)goto con;
                mark/=10;
            }
            ans.push_back(i);
            con:;
        }
        return ans;
    }
};