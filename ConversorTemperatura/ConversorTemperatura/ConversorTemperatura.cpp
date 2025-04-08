#include "MainT.h"

struct conversor {
    /* Essa estrutura serve para o caso do usuario digita o tipo de conversão o mesmo que ele tem
       o sistema vai indentificar se for o mesmo ele não faz nehuma modificação apenas retorna
       o valor, ex: ceuls para ceuls */
    char tipoAtual; // O tipo atual do Usuario, EX: ele colocou um valor em ceuls, farenheit 
    char tipoConversao; // O tipo que o usuario quer converter. EX: para farenheit  ou Ceuls 
};

static float Conversor(conversor tipos, float temperatura) {
    float Farenheit{};
    float Kelvim{};
    float Ceuls{};

    // Se os tipos forem iguais
    if (tipos.tipoAtual == tipos.tipoConversao) {
        return temperatura;
    }
    // converter Farenheit para Ceuls 
    else if (tipos.tipoAtual == 'F' && tipos.tipoConversao == 'C') {
        Ceuls = ((temperatura - 32) / 9) * 5;
        return Ceuls;
    }
    // converter Farenheit para Kelvim 
    else if (tipos.tipoAtual == 'F' && tipos.tipoConversao == 'K') {
        Kelvim = (((temperatura - 32) * 5) / 9) + 273.15;
        return Kelvim;
    }
    // converter Ceuls para Farenheit
    else if (tipos.tipoAtual == 'C' && tipos.tipoConversao == 'F') {
        Farenheit = ((temperatura * 9) / 5) + 32;
        return Farenheit;
    }
    // converter Ceuls para Kelvim
    else if (tipos.tipoAtual == 'C' && tipos.tipoConversao == 'K') {
        Kelvim = temperatura + 273.15;
        return Kelvim;
    }
    // converter Kelvim para Ceuls
    else if (tipos.tipoAtual == 'K' && tipos.tipoConversao == 'C') {
        Ceuls = temperatura - 273.15;
        return Ceuls;
    }
    // converter Kelvim para Farenheit
    else if (tipos.tipoAtual == 'K' && tipos.tipoConversao == 'F') {
        Farenheit = (((temperatura - 273.15) * 9) / 5) + 32;
        return Farenheit;
    }
    else {
        cout << "Erro dados fornecidos." << endl;
        return -1;
    }
}

int main() { // Conversor de temperatura
    conversor dados{}; // Estrutura {char tipoAtual, char tipoConversao}
    char escolhaTA{};  // Escolha TA = Tipo Atual
    char escolhaTC{};  // Escolha TA = Tipo Conversão
    int escolhasM1{};  // Escolha para o Menu Tipo Atual
    int escolhasM2{};  // Escolha para o Menu Tipo Conversão
    float Temperatura{}; // Temperatura que o usuario vai converter

    // Menu Tipo Atual
    cout << "======================================================" << endl;
    cout << "Qual eh o tipo de temperatura que vai ser convertida?" << endl;
    cout << "[ 1 ] Ceuls" << endl;
    cout << "[ 2 ] Kelvim" << endl;
    cout << "[ 3 ] Farenheit" << endl;
    cout << "Sua escolha: ";
    cin >> escolhasM1;

    if (escolhasM1 == 1) {
        escolhaTA = 'C';
    }
    else if (escolhasM1 == 2) {
        escolhaTA = 'K';
    }
    else if (escolhasM1 == 3) {
        escolhaTA = 'F';
    }
    else {
        escolhaTA = '!';
    }

    // Menu Tipo Conversão
    cout << "======================================================" << endl;
    cout << "Vai ser convertida qual temperatura?" << endl;
    cout << "[ 1 ] Ceuls" << endl;
    cout << "[ 2 ] Kelvim" << endl;
    cout << "[ 3 ] Farenheit" << endl;
    cout << "Sua escolha: ";
    cin >> escolhasM2;

    if (escolhasM2 == 1) {
        escolhaTC = 'C';
    }
    else if (escolhasM2 == 2) {
        escolhaTC = 'K';
    }
    else if (escolhasM2 == 3) {
        escolhaTC = 'F';
    }
    else if (escolhaTA == '!' || escolhasM2 > 3) {
        escolhaTC = '!';
    }

    // Temperatura que o usuario vai converter
    cout << "======================================================" << endl;
    cout << "Digite a temperatura que vai ser convertida: ";
    cin >> Temperatura;

    dados.tipoAtual = escolhaTA; // O tipo atual
    dados.tipoConversao = escolhaTC;  // O tipo que o usuario quer

    cout << fixed << showpoint;
    cout << setprecision(2);
    cout << "O valor da conversao eh: " << Conversor(dados, Temperatura) << escolhaTC << endl;
    cout << "======================================================" << endl;
}
