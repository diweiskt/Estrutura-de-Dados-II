#include <unordered_map>
#include <unordered_set>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string>

namespace UPF {

template <typename T>
class digraph {
private:
    struct node {
        T value;
        std::unordered_set<node*> links;
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

    void visit_node(node *p, std::unordered_set<node *> &visited, int level){
        std::cout << std::string(level, '\t')<< p->value << "\n";
        visited.insert(p);
        for(auto adj: p->links){
            if(visited.count(adj)==0){
                visit_node(adj, visited, level+1);
            }
        }
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

        pfrom->links.insert(pto);
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

    void DFS_from(const T& from){
        auto p = find(from);
        if(!p) return;
        std::unordered_set<node *> visited;
        visit_node(p, visited, 0);
    }

    void save(const std::string &filename){
        std::ofstream out(filename);
        out << graph.size() << "\n";
        for (const auto& [key, node] : graph){
            out << node.value << "\n";
        }
        for (const auto& [key,node] : graph){
            for(const auto& link : node.links){
                out << key << '\n';
                out << link->value << '\n';
            }
        }
        out.close();
    }

    void load(const std::string &filename){
        std::ifstream in(filename);
        if(!in) return; //Se não tem arquivo sai da função
        int n;
        in >> n; in.ignore();
        std::string line, line2;
        while(n--){  // enquanto n for true executa(qualquer numero que nao seja 0 é true)
            getline(in,line);
            insert_node(line);
        }
        while(getline(in,line) && getline(in, line2)){
            insert_link(line, line2);
        }

        in.close();
    }

    void remove(const T &name){
        auto pfrom = find(name);
        if(!pfrom) return;
        
        for(auto& [key, node] : graph){
            node.links.erase(pfrom);
        }
        graph.erase(name);
    }
};
}
