#include <iostream>
#include <sstream>
#include <fstream>
#include "Estudante.h"
#include "Aula.h"
#include "GestaoHorarios.h"
#include "UCTurma.h"
#include <limits>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

queue<Pedido> totalPedidos;

void Option1(GestaoHorarios gestor, string code){
    vector <Estudante> StudentsUC;
    for (Estudante a: gestor.getEstudantes()){
        for (UCTurma turma: a.getturmasEstudante()){
            if (turma.getUC()==code) StudentsUC.push_back(a);
        }
    }
    sort(StudentsUC.begin(),StudentsUC.end());
    for (Estudante a: StudentsUC){
        cout << a.getCode() << ',' << a.getName() << endl;
    }
    cout << "Estão inscritos " << StudentsUC.size() << " alunos nesta disciplina";
}
void Option2(GestaoHorarios gestor, string turma, string code){
    vector<Estudante> StudentsTurma;
    for (Estudante a: gestor.getEstudantes()){
        for (UCTurma turmas: a.getturmasEstudante()){
            if (turmas.getUC()==code && turmas.getClassCode()==turma) StudentsTurma.push_back(a);
        }
    }
    sort(StudentsTurma.begin(),StudentsTurma.end());
    for (Estudante a: StudentsTurma){
        cout << a.getCode() << ',' << a.getName() << endl;
    }
    if (StudentsTurma.empty()) cout << "Nenhum estudante está inscrito na turma " << turma << " da UC " << code << "." << endl;
    else cout << "Estão inscritos " << StudentsTurma.size() << " alunos na turma " << turma << " da UC " << code << "." << endl;
}
void Option3(GestaoHorarios gestor, int code) {
    vector<UCTurma> turmas;
    vector<Aula> horario;
    vector<Estudante> estudantes = gestor.getEstudantes();
    vector<UCTurma> bigturmas = gestor.getUCTurmas();
    turmas = find(estudantes.begin(),estudantes.end(),Estudante(code,"unimportant"))->getturmasEstudante();
    /*for (Estudante e: gestor.getEstudantes()){
        if (e.getCode() == code) turmas = e.getturmasEstudante();
    }*/
    for (UCTurma t: turmas) {
        for (Aula a: find(bigturmas.begin(),bigturmas.end(),t)->getHorarioUCTurma()) horario.push_back(a);
    }
    sort(horario.begin(), horario.end());
    int counter = 0;
    while (counter!=7){
        if (counter==0) cout << "Monday:" << endl;
        else if (counter==1) cout << "Tuesday:" << endl;
        else if (counter==2) cout << "Wednesday:" << endl;
        else if (counter==3) cout << "Thursday:" << endl;
        else if (counter==4) cout << "Friday:" << endl;
        else if (counter==5) cout << "Sunday:" << endl;
        else if (counter==6) cout << "Saturday:" << endl;

        for(Aula a: horario){
            if (a.getDay()=="Monday" && counter==0) a.print();
            else if (a.getDay()=="Tuesday" && counter==1) a.print();
            else if (a.getDay()=="Wednesday" && counter==2) a.print();
            else if (a.getDay()=="Thursday" && counter==3) a.print();
            else if (a.getDay()=="Friday" && counter==4) a.print();
            else if (a.getDay()=="Saturday" && counter==5) a.print();
            else if (a.getDay()=="Sunday" && counter==6) a.print();
        }
        counter++;
    }
}
void Option4(GestaoHorarios gestor, string ano){
    vector<Estudante> estudantes;
    if (ano=="3"){
        for (Estudante a: gestor.getEstudantes()){
            for(UCTurma turma: a.getturmasEstudante()){
                if (turma.getClassCode().at(0)==ano.at(0)){
                    estudantes.push_back(a);
                    break;
                }
            }
        }
    }
    if (ano=="2"){
        for (Estudante a: gestor.getEstudantes()){
            for(UCTurma turma: a.getturmasEstudante()){
                if (turma.getClassCode().at(0)==ano.at(0)){
                    estudantes.push_back(a);
                    break;
                }
            }
        }
    }
    if (ano=="1"){
        for (Estudante a: gestor.getEstudantes()){
            for(UCTurma turma: a.getturmasEstudante()){
                if (turma.getClassCode().at(0)==ano.at(0)){
                    estudantes.push_back(a);
                    break;
                }
            }
        }
    }
    sort(estudantes.begin(),estudantes.end());
    for (Estudante e: estudantes){
        cout << e.getCode() << ", " << e.getName() << endl;
    }
    if (estudantes.empty()) cout << "Nenhum aluno está inscrito em cadeiras do " << ano << "º ano letivo.";
    else cout << "Estão inscritos " << estudantes.size() << " alunos em cadeiras do " << ano << "º ano letivo.";
}


void Option6(GestaoHorarios gestor ,string studentcode_, string uccode, string classcode ){
    UCTurma turma= UCTurma(uccode, classcode);
    int studentcode = stoi(studentcode_);
    std::vector<Estudante>::iterator it;
    std::vector<UCTurma>::iterator itr;

    for ( it = gestor.getEstudantes().begin(); it!=gestor.getEstudantes().end(); it++){
        if (it->getCode()==studentcode){
            for (itr=it->getturmasEstudante().begin(); itr!=it->getturmasEstudante().end(); itr++ ){
                if (turma==*itr){
                    Pedido(it->getCode(), it->getName(), itr->getUC(), itr->getClassCode());
                    it->setpreferenciaFalse();
                }

            }
            if (itr==it->getturmasEstudante().end()){
                cout<< "O estudante já não se encontrava nesta turma";
            }
        break;
        }
    }
    if (it==gestor.getEstudantes().end()){
        cout << "O Estudante escolhido não existe";
    }

}
void Option5(GestaoHorarios gestor ,string studentcode_, string uccode, string classcode ){
    UCTurma turma= UCTurma(uccode, classcode);
    int studentcode = stoi(studentcode_);
    std::vector<Estudante>::iterator it;
    std::vector<UCTurma>::iterator itr;

    for ( it = gestor.getEstudantes().begin(); it!=gestor.getEstudantes().end(); it++){
        if (it->getCode()==studentcode){
            for (itr=it->getturmasEstudante().begin(); itr!=it->getturmasEstudante().end(); itr++ ){
                if (turma==*itr){
                    Pedido pedido=Pedido(it->getCode(), it->getName(), itr->getUC(), itr->getClassCode());

                    it->setpreferenciaTrue();

                    totalPedidos.push(pedido);

                }

            }
            if (itr==it->getturmasEstudante().end()){
                cout<< "O estudante já se encontrava nesta turma";
            }
            break;
        }
    }
    if (it==gestor.getEstudantes().end()){
        cout << "O Estudante escolhido não existe";
    }

}
Estudante find_by_name(GestaoHorarios gestor, int studentcode){
    for ( auto it = gestor.getEstudantes().begin(); it!=gestor.getEstudantes().end(); it++){
        if (it->getCode()==studentcode){
            return *it;
        }
    }
}
void ProcessarPedidos(GestaoHorarios gestor){

    int size= totalPedidos.size();
    while(size--){
       Estudante found= find_by_name(gestor, totalPedidos.front().getstudentcode());
    }

}

int main() {
    bool flag=true;
    GestaoHorarios gestor = GestaoHorarios();
    int quit;
    cout << gestor.getEstudantes().size();
    while(flag) {
        cout << endl << "Gestor de Horários de Estudantes L.EIC" << endl;
        cout << "Digite 0 a qualquer momento para fechar o programa" << endl;
        cout << "---------------------------------------------------------" << endl;
        cout << "1 - Ver estudantes de uma cadeira" << endl;
        cout << "2 - Ver estudantes de uma turma" << endl;
        cout << "3 - Ver horário de um estudante" << endl;
        cout << "4 - Ver estudantes de um ano letivo" << endl;
        cout << "5 - Adicionar aluno a uma turma" << endl;
        cout << "6 - Remover aluno de uma turma" << endl;
        cout << "7 - Alterar turma de um estudante numa UC" << endl;
        cout << "---------------------------------------------------------" << endl;
        cout << "Selecione uma opção: ";
        int selection = 0;
        while (!(cin >> selection) or selection > 9 or selection < 0) {
            cout << "Opção inválida!" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << endl << "Selecione uma opção: ";
        }
        if (selection == 1) {
            string code;
            vector<string> codigos = gestor.getCodes();
            cout << "Insira o código da UC: ";
            while (cin>>code and find(codigos.begin(), codigos.end(), code) == codigos.end()) {
                if (code=="0") break;
                cout << "Opção inválida!" << endl;
                cin.clear();
                cout << endl << "Insira o código da UC: ";
            }
            if (code=="0") flag = false;
            Option1(gestor, code);
            cout << endl << "Insira 0 para sair do programa ou 1 para voltar ao menu principal: ";
            while (!(cin >> quit) or (quit != 0 and quit != 1)) {
                cout << "Opção inválida!" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << endl << "Selecione uma opção: ";
            }
            if (quit==0) flag = false;
        }
        if (selection == 2){
            string code;
            string turma;
            vector<string> codigos = gestor.getCodes();
            vector<string> turmas = gestor.getTurmas();
            cout << "Insira o código da UC: ";
            while (cin>>code and find(codigos.begin(), codigos.end(), code) == codigos.end()) {
                if (code=="0") break;
                cout << "Opção inválida!" << endl;
                cin.clear();
                cout << endl << "Insira o código da UC: ";
            }
            if (code=="0") flag = false;
            cout << "Insira a turma: ";
            while (cin>>turma and find(turmas.begin(), turmas.end(), turma) == turmas.end()) {
                if (turma=="0") break;
                cout << "Opção inválida!" << endl;
                cin.clear();
                cout << endl << "Insira a turma: ";
            }
            if (turma=="0") flag = false;
            Option2(gestor,turma,code);
            cout << endl << "Insira 0 para sair do programa ou 1 para voltar ao menu principal: ";
            while (!(cin >> quit) or (quit != 0 and quit != 1)) {
                cout << "Opção inválida!" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << endl << "Selecione uma opção: ";
            }
            if (quit==0) flag = false;
        }
        if (selection == 3){
            int code;
            cout << "Insira o código mecanógrafico do estudante: ";
            vector<string> Turmas= gestor.getTurmas();
            vector<Estudante> estudantes = gestor.getEstudantes();
            while (!(cin>>code) or find(estudantes.begin(), estudantes.end(), code) == estudantes.end()) {
                if (code==0) break;
                cout << "Opção inválida!" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << endl << "Insira o código mecanógrafico do estudante: ";
            }
            if (code==0) flag = false;
            Option3(gestor,code);
            cout << endl << "Insira 0 para sair do programa ou 1 para voltar ao menu principal: ";
            while (!(cin >> quit) or (quit != 0 and quit != 1)) {
                cout << "Opção inválida!" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << endl << "Selecione uma opção: ";
            }
            if (quit==0) flag = false;
        }
        if (selection==4){
            string year;
            cout << "Insira o ano letivo: ";
            while(!(cin>>year) or (year!="1" and year!="2" and year!="3")){
                if (year=="0") break;
                cout << "Opção inválida!" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << endl << "Insira o ano letivo: ";
            }
            Option4(gestor, year);
            cout << endl << "Insira 0 para sair do programa ou 1 para voltar ao menu principal: ";
            while (!(cin >> quit) or (quit != 0 and quit != 1)) {
                cout << "Opção inválida!" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << endl << "Insira o ano letivo: ";
            }
            if (quit==0) flag = false;
        }
        if (selection==0){
            flag=false;
        }

//    for (UCTurma c : gestor.getUCTurmas()) c.print();           // test
//    for (Estudante c: gestor.getEstudantes()) c.print();        // test
    }
    return 0;
}