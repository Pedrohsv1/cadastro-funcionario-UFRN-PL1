#include <iostream>
#include <string>
#include <cstdio>

#include "funcionario.h"
#include "desenvolvedor.h"
#include "gerente.h"
#include "estagiario.h"


int main() {
    //vetor de ponteiros
    Funcionario ** lista = (Funcionario**)malloc(10*sizeof(Funcionario*));

    //solicitação de 6 funcionários no mínimo
    int cont=0;
    //sem entrada e cont = 7 -> F F -> sai do while
    while(cont < 2){
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
            
        cout<< "Digite o tipo do seu funcinário (1-Desenvolvedor, 2-Gerente, 3-Estagiario): ";
        cin>> tipo;
            

        if(tipo == 1){
            int qtdDeProjetos;
            cout<< "Digite a quantidade de projetos do seu desenvolvedor: ";
            cin>> qtdDeProjetos;

            Desenvolvedor* dev = new Desenvolvedor();
            dev->setNome(nome);
            dev->setId(id);
            dev->setSalarioBase(salarioBase);
            dev->setQuantidadeDeProjetos(qtdDeProjetos);

            lista[cont] = dev;
            cont++;

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

            lista[cont] = gerente;
            cont++;
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

            lista[cont] = estagiario;
            cont++;

        }
    }

    lista[0]->exibirInformacoes();
}