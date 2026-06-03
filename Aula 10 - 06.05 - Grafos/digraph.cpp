#include <unordered_map>
#include <vector>
#include <fstream>
#include <cstdlib> 

namespace UPF {

template <typename T>
class digraph {
private:
    struct node {
        T value;
        std::vector<node*> links;
    };

    std::unordered_map<T, node> graph;

    node* find(const T& val)
    {
        auto it = graph.find(val);
        if(it==graph.end()){ // Not found!
            return nullptr;
        }
        return &it->second;
    }

public:
    void insert_node(const T& val)
    {
        if (graph.count(val) != 0)
            return;
        node aux;
        aux.value = val;
        graph[val] = aux;
    }

    void insert_link(const T& from, const T& to)
    {
        auto pfrom = find(from);
        if(!pfrom) return;
        auto pto = find(to);
        if(!pto) return;

        pfrom->links.push_back(pto);
    }

    void show(){
        std::ofstream dot("/tmp/g123456.dot");
        dot << "digraph{\n";
        for(const auto &[key, node] : graph){
            dot << "\t\"" << key << "\" -> {";
            for(const auto &link : node.links){
                dot << "\"" << link->value << "\" ";
            }
            dot << "};\n";
        }
        dot << "}\n";
        dot.close();
        system("dot -Tx11 /tmp/g123456.dot");
    }
};
}
