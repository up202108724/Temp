//
// Created by andre on 19-10-2022.
//

#include "Aula.h"
#include <string>
#include <iostream>
using namespace std;

Aula::Aula(string uccode, string classcode, string dia, float inicio, float duracao, string tipo) {
    uccode_ = uccode;
    classcode_ = classcode;
    dia_=dia;
    inicio_=inicio;
    duracao_=duracao;
    tipo_=tipo;
    fim_=inicio+duracao;
}

void Aula::print() {
    cout << "\tUC: " << uccode_ << ", Turma: " << classcode_ << ", Duração: " << inicio_ << "-" << fim_ << ", Tipo: " << tipo_ << endl;
}

string Aula::getDay() const{
    return dia_;
}

float Aula::getInicio() const{
    return inicio_;
}

float Aula::getFim() const{
    return fim_;
}

bool Aula::operator<(const Aula &aula2) const {
    return inicio_<aula2.getInicio();
}
string Aula::getTipo() const{
    return tipo_;
}