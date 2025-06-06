#ifndef GERENTE_H
#define GERENTE_H

#include "funcionario.h"

class Gerente : public Funcionario{
    private:
        float bonusMensal;
    public:
        void setBonusMensal(float bonusMensal);

        float calcularSalarioFinal();
        void exibirInformacoes();
};

#endif