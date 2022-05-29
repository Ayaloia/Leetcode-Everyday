//
// Created by aldlss on 2022/5/29.
//

//468. 验证IP地址
//傻逼题目，纯纯浪费人生，没什么意义
//就嗯分析，没有技术含量，就是嗯写

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string validIPAddress(string queryIP) {
#define nei return "Neither";
        auto ipv=queryIP.find('.');
        if(ipv!=queryIP.npos)//ipv4
        {
            int count=0,last=0;
            queryIP+='.';
            for(int i=ipv;i!=queryIP.npos;i=queryIP.find('.',last))
            {
                int sum=0;
                if(++count>4||last==i||i-last>3)
                    nei
                for(int j=last;j<i;++j)
                {
                    char q=queryIP[j];
                    if(!isdigit(q)||(!sum&&j!=last))
                        nei
                    sum*=10;
                    sum+=q-'0';
                }
                if(sum>255)
                    nei
                last=i+1;
            }
            if(count<4)
                nei
            return "IPv4";
        }
        ipv=queryIP.find(':');
        if(ipv!=queryIP.npos)//ipv6
        {
            int count=0,last=0;
            queryIP+=':';
            for(int i=ipv;i!=queryIP.npos;i=queryIP.find(':',last))
            {
                if(++count>8||last==i||i-last>4)
                    nei
                for(int j=last;j<i;++j)
                {
                    char q=queryIP[j];
                    if(!isdigit(q)&&!((q>='a'&&q<='f')||(q>='A'&&q<='F')))
                        nei
                }
                last=i+1;
            }
            if(count<8)
                nei
            return "IPv6";
        }
        nei
    }
};

int main()
{
    Solution a;
    a.validIPAddress("2001:0db8:85a3:0:0:8A2E:0370:7334");
    return 0;
}