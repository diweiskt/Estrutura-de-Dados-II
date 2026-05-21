#include "digraph.cpp"
#include <string>

int main(){
    UPF::digraph<std::string> g;

    g.insert_node("A"); 
    g.insert_node("B");
    g.insert_node("C");
    g.insert_node("E");
    g.insert_node("F");
    g.insert_node("G");

    g.insert_link("A", "B");    
    g.insert_link("A", "C");
    g.insert_link("C", "A");    
    g.insert_link("C", "B");
    g.insert_link("B", "E");
    g.insert_link("C", "F");
    g.insert_link("B", "G");
    
    g.DFS_from("A");
    g.show();
}
