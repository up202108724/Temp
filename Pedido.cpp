//
// Created by andre on 02-11-2022.
//

#include "Pedido.h"
#include "UCTurma.h"
#include "Estudante.h"
Pedido::Pedido(int studentcode, string name, string uccode, string classcode ) {
    studentcode_=studentcode;
    name_=name;
    uccode_=uccode;
    classcode_=classcode;


}
int Pedido::getstudentcode() {
    return studentcode_;
}
string Pedido::getname() {
    return name_;
}
string Pedido::getuccode() {
    return uccode_;
}
string Pedido::getclasscode() {
    return classcode_;
}