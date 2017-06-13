/*
题目描述
对于一个有向图，请实现一个算法，找出两点之间是否存在一条路径。
给定图中的两个结点的指针UndirectedGraphNode* a,UndirectedGraphNode* b(请不要在意数据类型，图是有向图),请返回一个bool，代表两点之间是否存在一条路径(a到b或b到a)。
*/
/*method
深度优先搜索和广度优先搜索均可实现，也各有利弊。深度优先搜索实现起来比较简单，只需要简单的递归即可。
广度优先搜索适合用来查找最短路径，而深度优先搜索可能回先深度遍历其中一个邻近节点。
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

/*
深度优先搜索
*/

class Path {
public:
    bool checkPath(UndirectedGraphNode* a, UndirectedGraphNode* b) {
        if(a == nullptr || b == nullptr || a == b){
        return true;
    	}
        std::vector<UndirectedGraphNode*> vecAToB;
        vecAToB.emplace_back(a);
        std::vector<UndirectedGraphNode*> vecBToA;
        vecBToA.emplace_back(b);
        return checkPathProxy(a, b, vecAToB) || checkPathProxy(b, a, vecBToA);
    }
private:
    bool checkPathProxy(UndirectedGraphNode* a, UndirectedGraphNode* b, std::vector<UndirectedGraphNode*>& vec) {
        if(a == b){
            return true;
        }
        bool result = false;
        for(auto&& node : a->neighbors){
            if(node == b){
                return true;
            }
            if(std::find(std::begin(vec), std::end(vec), node) == std::end(vec)){
                vec.emplace_back(node);
                result = checkPathProxy(node, b, vec);
            }
        }

        return false;
    }
};
