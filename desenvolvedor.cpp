#include <iostream>
using namespace std;

#include "desenvolvedor.h"

void Desenvolvedor::setQuantidadeDeProjetos(int quantidadeDeProjetos) {
    this->quantidadeDeProjetos = quantidadeDeProjetos;
}

int Desenvolvedor::getQuantidadeDeProjetos() {
    return this->quantidadeDeProjetos;
}


float Desenvolvedor::calcularSalarioFinal(){
    int qtdProjetos = this->quantidadeDeProjetos;
    int salario_base = this->salarioBase;
    float salario_final = salario_base + (500*qtdProjetos);
    return salario_final;
}
void Desenvolvedor::exibirInformacoes(){
    cout << "ID: " << this->getId() << endl;
    cout << "Nome: " << this->nome << endl;
    cout << "Tipo: Desenvolvedor" << endl;
    cout << "Projetos: " << this->quantidadeDeProjetos<<endl;
    cout << "Salário base: " << this->salarioBase << endl;
    cout << "Salário final: " << this->calcularSalarioFinal() << endl;
    cout << endl;
}
