#include <iostream>
using namespace std;

#include "estagiario.h"

void Estagiario::setHorasTrabalhadas(int horasTrabalhadas) {
    this->horasTrabalhadas = horasTrabalhadas;
}


float Estagiario::calcularSalarioFinal(){
    int horasTrabalhadas = this->horasTrabalhadas;
    int salario_base = this->salarioBase;
    float salario_final = salario_base + (horasTrabalhadas/160.0);
    return salario_final;
}

void Estagiario::exibirInformacoes(){
    cout << "ID: " << this->getId() << endl;
    cout << "Nome: " << this->nome << endl;
    cout << "Tipo: Estagiario" << endl;
    cout << "Horas trabalhadas: " << this->horasTrabalhadas<<endl;
    cout << "Salário base: " << this->salarioBase << endl;
    cout << "Salário final: " << this->calcularSalarioFinal() << endl;
    cout << endl;
}
