//Exemplo de escrita em html
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main(){

    ofstream pag;
    pag.open("pagina.html");//saida do arquivo

    pag << "!DOCTYPE html>\n";
    pag << "<html>\n";
    pag << "<head>\n <title> Estrutura 2 - 2026 </title> </head>\n";
    pag << "<body>\n";
    pag << "<h1> Conversão de Decimal para Hex </h1>\n";

    pag << "<table border=\"1\>\n;";

    for(int i=0;i<100;i++){
        pag << "<tr>" 
            << "<td" << dec << i << "</td>" 
            << "<td>" << i * 10 << "</td>"
            << "<td>" << hex << uppercase << i << "</td>"
            << "</tr>";
    }
    pag << "</table>";
    pag << "</body>";
    pag << "</html>\n";

    //i;i*10;hex(i)
    pag.close();

    return 0;
}