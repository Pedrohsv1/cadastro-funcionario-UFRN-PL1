#include <iostream>
#include <string>
#include <limits>

#include "funcionario.h"
#include "desenvolvedor.h"
#include "gerente.h"
#include "estagiario.h"
#include "gettype.h"



int main() {
    //vetor de ponteiros
    Funcionario ** lista = (Funcionario**)malloc(10*sizeof(Funcionario*));

    //solicitação de 6 funcionários no mínimo
    int contador = 0;
    //sem entrada e contador = 7 -> F F -> sai do while
    while(contador < 10){
        int tipo;

        string nome;
        int id;
        float salarioBase;

        cout<< "Digite o nome do seu funcionário: ";
        cin>> nome;

        cout<< "Digite o id do seu funcionário: ";
        cin>> id;

        cout<< "Digite o salário base do seu funcionário: ";
        cin>> salarioBase;

        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            
        tipo = getType() + 1;
        // Verifica se o tipo é válido
            

        if(tipo == 1){
            int qtdDeProjetos;
            cout<< "Digite a quantidade de projetos do seu desenvolvedor: ";
            cin>> qtdDeProjetos;

            Desenvolvedor* dev = new Desenvolvedor();
            dev->setNome(nome);
            dev->setId(id);
            dev->setSalarioBase(salarioBase);
            dev->setQuantidadeDeProjetos(qtdDeProjetos);

            lista[contador] = dev;
        }
        if(tipo == 2){
            float bonusMensal;
            cout<< "Digite o bonus mensal do seu gerente: ";
            cin>> bonusMensal;

            Gerente* gerente= new Gerente();
            gerente->setNome(nome);
            gerente->setId(id);
            gerente->setSalarioBase(salarioBase);
            gerente->setBonusMensal(bonusMensal);

            lista[contador] = gerente;
        }
        if(tipo == 3){
            int horasTrabalhadas;
            cout<< "Digite a quantidade de horas trabalhadas do seu estagiário: ";
            cin>> horasTrabalhadas;
            Estagiario* estagiario= new Estagiario();
            estagiario->setNome(nome);
            estagiario->setId(id);
            estagiario->setSalarioBase(salarioBase);
            estagiario->setHorasTrabalhadas(horasTrabalhadas);

            lista[contador] = estagiario;
        }

        contador++;

        if(contador >= 10){
            cout << "Limite de funcionários atingido." << endl;
            break;
        }
        cout << "Funcionário adicionado com sucesso!" << endl;
        if (contador < 6) {
            cout << "Você pode adicionar mais " << (10 - contador) << " funcionários." << endl;
        } else {
            int resposta;

            while (true) {
                cout << "Você atingiu o mínimo de 6 funcionários. Deseja adicionar mais? (1 - Sim/0 - Não): ";
                cin >> resposta;
                if (resposta == 0 || resposta == 1) {
                    break;
                } else {
                    cout << "Opção inválida. Por favor, digite 1 para sim ou 0 para não." << endl;
                }
            }

            if (resposta == 0) {
                cout << "Você escolheu não adicionar mais funcionários." << endl;
                break; // Sai do loop se o usuário não quiser adicionar mais funcionários
            }
        }

        contador++; // Incrementa o contadorador de funcionários
    }

    lista[0]->exibirInformacoes();

    for (int i = 0; i < contador; i++) {
        if (lista[i] != nullptr) {
            lista[i]->exibirInformacoes();
        }
    }
    // Libera a memória alocada
}