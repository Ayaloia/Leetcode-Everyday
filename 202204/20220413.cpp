//
// Created by aldlss on 2022/4/13.
//

//380. O(1) 时间插入、删除和获取随机元素
//这个题目，算是学了很多新语法了，也比较透彻地理解了一些之前一知半解的地方
//这个似乎它是真的能看出你是不是真的用了随机，只能说它这个真的有点智能的
//这个vector随机访问，维护主要维护无序map的方法又是有点没想到，有点意思
//尤其是删除的那个维护方法还必须那样写，不然下标很难维护
//最后就是没想到花费我最久时间的是生成随机数= =，原本想直接一个rand过去
//后来IDE给我提示说rand太旧了，建议使用新的随机数生成办法，啊，新的好啊
//一看，c++11，这是好的，然后又一看，我超这随机数引擎和分布器是什么鬼!?
//然后又查了好多资料才算大概明白这两个东西是什么东西，也大概明白怎么用了
//结果一用上去，好嘛，空间大了，时间慢了，直接被90%多的用户超过，我谔谔
//看到知乎有人说这个太不好用了，我也是有点同感，不过只能说也是有利有弊吧
//不过学到了一些新东西还是挺有好的，尤其这个分布器，感觉大有可为啊

#include <bits/stdc++.h>
using namespace std;
class RandomizedSet {
private:
    unordered_map<int,int>aya;
    vector<int>value;
    mt19937 mt{random_device{}()};
public:
    RandomizedSet():aya{},value{}{
    }

    bool insert(int val) {
        auto exist=aya.find(val);
        if(exist!=aya.end())return false;
        aya.insert(make_pair(val,value.size()));
        value.push_back(val);
        return true;
    }

    bool remove(int val) {
        auto exist=aya.find(val);
        if(exist==aya.end())return false;
//        value.erase(value.begin()+exist->second);
        aya.find(*(value.end()-1))->second=exist->second;
        swap(value[exist->second],*(value.end()-1));
        value.pop_back();
        aya.erase(exist);
        return true;
    }

    int getRandom() {
        return value[uniform_int_distribution<>(0,value.size()-1)(mt)];
    }
};

int main()
{
    RandomizedSet* a=new RandomizedSet();
    a->insert(123);
    a->insert(651651);
    int b=a->getRandom();
    b=a->getRandom();
    b=a->getRandom();
    return 0;
}

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */