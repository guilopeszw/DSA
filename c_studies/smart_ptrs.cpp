#include <memory>
#include <iostream>
using namespace std;

struct Pessoa {
    string nome;
    Pessoa(string n) : nome(n) {}
};

int main() {
    auto p = make_unique<Pessoa>("Ana");
    cout << p->nome << endl;
} // memória liberada automaticamente

// usar smart pointers evita:
    // vazamentos de memória -> Quando você aloca memória, mas nunca libera do heap, ou perde todas as referências para aquele bloco.
        // Analogia: você tirou um carro de um estacionamento, perdeu o ticket e nunca devolveu o carro. Ele fica ocupando vaga para sempre.

    // double delete -> Liberar a mesma memória duas vezes. Isso causa comportamento indefinido: crash imediato, corrupção da heap, etc.
        // Analogia: você devolveu o carro duas vezes, mas só tinha um ticket. O estacionamento não sabe o que fazer.

    // dangling pointers -> Um ponteiro que aponta para memória inválida. Isso pode causar crash ou acessar dados inválidos.
        // Analogia: você devolveu o carro, mas ainda está tentando dirigir ele. O carro não existe mais, mas você ainda acha que ele está lá.

