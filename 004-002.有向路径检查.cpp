/*
题目描述
对于一个有向图，请实现一个算法，找出两点之间是否存在一条路径。
给定图中的两个结点的指针UndirectedGraphNode* a,UndirectedGraphNode* b(请不要在意数据类型，图是有向图),请返回一个bool，代表两点之间是否存在一条路径(a到b或b到a)。
*/

/*
广度优先实现
*/
/*
struct UndirectedGraphNode {
    int label;
    vector<struct UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {}
};*/

class Path {
public:
    bool checkPath(UndirectedGraphNode* a, UndirectedGraphNode* b) {
        if(a == nullptr || b == nullptr || a == b){
            return true;
        }
        return checkPathProxy(a, b) || checkPathProxy(b, a);
    }
    
private:
    bool checkPathProxy(UndirectedGraphNode* a, UndirectedGraphNode* b) {
        if(a == nullptr || b == nullptr || a == b){
            return true;
        }
        std::vector<UndirectedGraphNode*> vec;
        std::queue<UndirectedGraphNode*> que;
        que.emplace(a);
        vec.emplace_back(a);
        
        while(!que.empty()){
            auto top = que.front();
            que.pop();
            for(auto&& neigh : top->neighbors){
                if(neigh == b){
                    return true;
                }else if(neigh != nullptr && std::find(vec.begin(),vec.end(), neigh) == vec.end()){
                    que.emplace(neigh);
                    vec.emplace_back(neigh);
                }
            }
        }
        return false;
    }
};
