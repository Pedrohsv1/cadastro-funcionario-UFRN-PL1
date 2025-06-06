#include <iostream>
using namespace std;

#include "gerente.h"

void Gerente::setBonusMensal(float bonusMensal) {
    this->bonusMensal = bonusMensal;
}


float Gerente::calcularSalarioFinal(){
    int bonusMensal = this->bonusMensal;
    int salario_base = this->salarioBase;
    float salario_final = salario_base + bonusMensal;
    return salario_final;
}
void Gerente::exibirInformacoes(){
    cout << "ID: " << this->getId() << endl;
    cout << "Nome: " << this->nome << endl;
    cout << "Tipo: Gerente" << endl;
    cout << "Bonus: " << this->bonusMensal<<endl;
    cout << "Salário base: " << this->salarioBase << endl;
    cout << "Salário final: " << this->calcularSalarioFinal() << endl;
    cout << endl;
}
