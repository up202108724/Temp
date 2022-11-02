//
// Created by andre on 19-10-2022.
//
#ifndef AED_PROJECT_ESTUDANTE_H
#define AED_PROJECT_ESTUDANTE_H

#include <string>
#include <vector>
#include "UCTurma.h"
#include "Pedido.h"

class Estudante {
public:
    Estudante(int studentcode, string name);
    int getCode() const;
    string getName() const;
    vector<UCTurma> getturmasEstudante();
    void adicionarTurma(const UCTurma &turma);
    void print() const;
    bool operator==(const Estudante &aluno) const;
    bool operator==(int x) const;
    bool operator<(const Estudante& aluno) const;
    void removerTurma(const UCTurma& turma);
    void setpreferenciaTrue();
    void setpreferenciaFalse();
    bool getpreferencia();
    queue<Pedido> getpedidos();
    void addpedido(Pedido pedido);
    void removepedido(Pedido pedido);
private:
    int studentcode_;
    string name_;
    vector<UCTurma> turmasEstudante;
    bool preferencia_;
    queue<Pedido> pedidos;
};


#endif //AED_PROJECT_ESTUDANTE_H
