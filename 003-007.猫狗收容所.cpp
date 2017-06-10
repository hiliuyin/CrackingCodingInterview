/*
题目描述
有家动物收容所只收留猫和狗，但有特殊的收养规则，收养人有两种收养方式，第一种为直接收养所有动物中最早进入收容所的，第二种为选择收养的动物类型（猫或狗），
并收养该种动物中最早进入收容所的。
给定一个操作序列int[][2] ope(C++中为vector<vector<int>>)代表所有事件。若第一个元素为1，则代表有动物进入收容所，第二个元素为动物的编号，正数代表狗，
负数代表猫；若第一个元素为2，则代表有人收养动物，第二个元素若为0，则采取第一种收养方式，若为1，则指定收养狗，若为-1则指定收养猫。请按顺序返回收养的序列。
若出现不合法的操作，即没有可以符合领养要求的动物，则将这次领养操作忽略。
测试样例：
[[1,1],[1,-1],[2,0],[2,-1]]
返回：[1,-1]
*/

/*
分别创建保存猫和狗的队列，并用一个变量order记录猫和狗进入队列的顺序。
*/

//code1:
class CatDogAsylum {
public:
    vector<int> asylum(vector<vector<int> > ope) {
        if(ope.empty()) return {};
        
        int order = 0;
        std::vector<int> result;
        std::queue<std::pair<int, int>> dog;
        std::queue<std::pair<int, int>> cat;
        
        for(auto&& op : ope){
            if(op[0] == 1){ //push
                if(op[1] > 0){ //dog
                    dog.emplace(std::make_pair(op[1], order));
                } else{//cat
                    cat.emplace(std::make_pair(op[1], order));
                }
                ++order;
            }else if(op[0] == 2) { //pop
                if(op[1] == 0){
                    if(dog.empty() && !cat.empty()){
                        result.emplace_back(cat.front().first);
                        cat.pop();
                    }
                    else if(cat.empty() && !dog.empty()){
                        result.emplace_back(dog.front().first);
                        dog.pop();
                    }
                    else if(cat.front().second < dog.front().second){
                        result.emplace_back(cat.front().first);
                        cat.pop();
                    }else{
                        result.emplace_back(dog.front().first);
                        dog.pop();
                    }
                }else{
                    if(op[1] == 1 && !dog.empty()){
                        result.emplace_back(dog.front().first);
                        dog.pop();
                    }else if(op[1] == -1 && !cat.empty()){
                        result.emplace_back(cat.front().first);
                        cat.pop();
                    }
                }                
            }
        }
        
        return result;

    }
};

