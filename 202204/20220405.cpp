//
// Created by aldlss on 2022/4/5.
//

//简单题，刚刚写完树状数组，对这个取最低位1的写法还是有深刻印象的，然后打表，最后暴力就没了
//官解那个位运算mask也是会玩，看了一会才看懂，不过我觉得你这个不也是用了for吗，为了这点空间是否

class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        const int zs[]={2,3,5,7,11,13,17,19};
        int sum=0,ans=0;
        for(int i=left;i<=right;++i)
        {
            sum=0;
            for(int mark=i;mark;mark-=mark&(-mark))++sum;
            for(int j=0;j<=7;++j)if(zs[j]==sum)
            {
                ++ans;
                break;
            }
        }
        return ans;
    }
};