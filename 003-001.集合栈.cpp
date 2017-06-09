/*
题目描述
请实现一种数据结构SetOfStacks，由多个栈组成，其中每个栈的大小为size，当前一个栈填满时，新建一个栈。该数据结构应支持与普通栈相同的push和pop操作。
给定一个操作序列int[][2] ope(C++为vector&ltvector&ltint>>)，每个操作的第一个数代表操作类型，若为1，则为push操作，后一个数为应push的数字；
若为2，则为pop操作，后一个数无意义。请返回一个int[][](C++为vector&ltvector&ltint>>)，为完成所有操作后的SetOfStacks，顺序应为从下到上，
默认初始的SetOfStacks为空。保证数据合法。
*/

class SetOfStacks {
public:
    vector<vector<int> > setOfStacks(vector<vector<int> > ope, int size) {
        if(ope.empty() || size < 1){
            return {};
        }

        std::vector<std::vector<int>> result;
        std::vector<int> tmp;

        for(int i = 0, iEnd = ope.size(); i < iEnd; ++i){
            if(ope[i][0] == 1){
                if(tmp.size() == size){
                    result.emplace_back(tmp);
                    tmp.clear();
                }
                tmp.emplace_back(ope[i][1]);
            }else{
                if(tmp.size() == 0){
                    tmp = result.back();
                    result.pop_back();
                }
                tmp.pop_back();
            }
        }

        
        //最后的tmp记得存入栈集合
        if(!tmp.empty()){
            result.emplace_back(tmp);
        }

        return result;
    }
};
