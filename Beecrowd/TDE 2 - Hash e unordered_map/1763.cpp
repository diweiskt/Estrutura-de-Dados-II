/*
Tradutor do Papai Noel

Nicolau já está bastante cansado e sua memória não é mais a mesma. 
Você, como navegador, deverá auxiliar o Papai Noel a gritar a frase 
"Feliz Natal" no idioma correto de cada país de que trenó está sobrevoando.

Como você é um elfo muito esperto, você já criou um pequeno app no seu celular 
(sim, elfos tem celular) que irá lhe informar a frase no idioma correto dado o 
nome do país. Como o trenó é moderno (foi atualizado no ano 2000) ele exibe no 
painel de navegação o nome do país atual.

Os dados inseridos no seu app foram:

brasil              Feliz Natal!
alemanha            Frohliche Weihnachten!
austria             Frohe Weihnacht!
coreia              Chuk Sung Tan!
espanha             Feliz Navidad!
grecia              Kala Christougena!
estados-unidos      Merry Christmas!
inglaterra          Merry Christmas!
australia           Merry Christmas!
portugal            Feliz Natal!
suecia              God Jul!
turquia             Mutlu Noeller
argentina           Feliz Navidad!
chile               Feliz Navidad!
mexico              Feliz Navidad!
antardida           Merry Christmas!
canada              Merry Christmas!
irlanda             Nollaig Shona Dhuit!
belgica             Zalig Kerstfeest!
italia              Buon Natale!
libia               Buon Natale!
siria               Milad Mubarak!
marrocos            Milad Mubarak!
japao               Merii Kurisumasu!
Para não correr o risco de infomar o nome errado você decidiu testar o aplicativo mais algumas vezes.

Entrada
Você irá testar o seu aplicativo com diversos nomes de paises, simulando os dados informados 
pelo painel de navegação do trenó.

Saída
O seu aplicativo deverá mostrar na tela a frase no idioma correto. 
Caso ela não esteja cadastrada, você deverá exibir a mensagem "--- NOT FOUND ---" 
para que depois dos testes você possa completar o banco de dados.
*/

#include <iostream>
#include <unordered_map>

using namespace std;

int main(){

    unordered_map<string, string> tradutor;
    
    tradutor["brasil"] = "Feliz Natal!";
    tradutor["alemanha"] = "Frohliche Weihnachten!";
    tradutor["austria"] = "Frohe Weihnacht!";
    tradutor["coreia"] = "Chuk Sung Tan!";
    tradutor["espanha"] = "Feliz Navidad!";
    tradutor["grecia"] = "Kala Christougena!";
    tradutor["estados-unidos"] = "Merry Christmas!";
    tradutor["inglaterra"] = "Merry Christmas!";
    tradutor["australia"] = "Merry Christmas!";
    tradutor["portugal"] = "Feliz Natal!";
    tradutor["suecia"] = "God Jul!";
    tradutor["turquia"] = "Mutlu Noeller";
    tradutor["argentina"] = "Feliz Navidad!";
    tradutor["chile"] = "Feliz Navidad!";
    tradutor["mexico"] = "Feliz Navidad!";
    tradutor["antardida"] = "Merry Christmas!";
    tradutor["canada"] = "Merry Christmas!";
    tradutor["irlanda"] = "Nollaig Shona Dhuit!";
    tradutor["belgica"] = "Zalig Kerstfeest!";
    tradutor["italia"] = "Buon Natale!";
    tradutor["libia"] = "Buon Natale!";
    tradutor["siria"] = "Milad Mubarak!";
    tradutor["marrocos"] = "Milad Mubarak!";
    tradutor["japao"] = "Merii Kurisumasu!";

    string entrada;

    while (getline(cin, entrada)) {
        if(tradutor.count(entrada) == 0){
            cout << "--- NOT FOUND ---\n";
        } else {
            cout << tradutor[entrada] << "\n";
        }
    }

    return 0;
}