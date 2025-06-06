#ifndef ESTAGIARIO_H
#define ESTAGIARIO_H

#include "funcionario.h"

class Estagiario : public Funcionario{
    private:
        int horasTrabalhadas;
    public:
        void setHorasTrabalhadas(int horasTrabalhadas);

        float calcularSalarioFinal();
        void exibirInformacoes();
};

#endif