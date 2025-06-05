#include <iostream>
using namespace std;

#include "funcionario.h"

void Funcionario::setNome(string nome) {
    this->nome = nome;
}

string Funcionario::getNome() {
    return this->nome;
}

void Funcionario::setSalarioBase(float salarioBase) {
    this->salarioBase = salarioBase;
}

float Funcionario::getSalarioBase() {
    return this->salarioBase;
}

void Funcionario::setId(int id) {
    this->id = id;
}

int Funcionario::getId() {
    return this->id;
}

void Funcionario::exibirInformacoes() {
    cout << "Nome: " << this->nome << endl;
    cout << "Sálario Base: " << this->salarioBase << endl;
    cout << endl;
}