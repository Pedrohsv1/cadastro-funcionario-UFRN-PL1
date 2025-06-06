#ifndef DESENVOLVEDOR_H
#define DESENVOLVEDOR_H

#include "funcionario.h"

class Desenvolvedor : public Funcionario{
    private:
        int quantidadeDeProjetos;
    public:
        void setQuantidadeDeProjetos(int quantidadeDeProjetos);
        int getQuantidadeDeProjetos();

        float calcularSalarioFinal();
        void exibirInformacoes();
};

#endif