#include <iostream>
#include <string>
#include <limits>
#include <algorithm>
#include <cctype>

using namespace std;

// Estrutura que representa um aluno
struct Aluno {
    int matricula;
    string nome;
    string curso;
};

// Estrutura que representa um no da arvore
struct No {
    Aluno aluno;
    No* esquerda;
    No* direita;

    No(Aluno a) {
        aluno = a;
        esquerda = nullptr;
        direita = nullptr;
    }
};

// Classe da Arvore Binaria de Busca
class ArvoreABB {
private:
    No* raiz;
    int total;

    // Normaliza o nome para comparar sem diferenciar maiusculas e minusculas
    string normalizarNome(string nome) {
        transform(nome.begin(), nome.end(), nome.begin(), [](unsigned char c) {
            return toupper(c);
        });

        return nome;
    }

    // Verifica se uma matricula ja existe na arvore
    bool matriculaExiste(No* no, int matricula) {
        if (no == nullptr) {
            return false;
        }

        if (no->aluno.matricula == matricula) {
            return true;
        }

        return matriculaExiste(no->esquerda, matricula) ||
               matriculaExiste(no->direita, matricula);
    }

    // Insere um aluno na arvore usando o nome como chave de ordenacao
    No* inserir(No* no, Aluno aluno) {
        if (no == nullptr) {
            total++;
            return new No(aluno);
        }

        string nomeNovo = normalizarNome(aluno.nome);
        string nomeAtual = normalizarNome(no->aluno.nome);

        if (nomeNovo < nomeAtual) {
            no->esquerda = inserir(no->esquerda, aluno);
        }
        else if (nomeNovo > nomeAtual) {
            no->direita = inserir(no->direita, aluno);
        }
        else {
            cout << "Aluno ja cadastrado!" << endl;
        }

        return no;
    }

    // Busca um aluno pelo nome
    No* buscar(No* no, string nome) {
        if (no == nullptr) {
            return nullptr;
        }

        string nomeBusca = normalizarNome(nome);
        string nomeAtual = normalizarNome(no->aluno.nome);

        if (nomeBusca == nomeAtual) {
            return no;
        }

        if (nomeBusca < nomeAtual) {
            return buscar(no->esquerda, nome);
        }

        return buscar(no->direita, nome);
    }

    // Percurso em ordem: esquerda, raiz, direita
    // Esse percurso mostra os alunos em ordem alfabetica
    void listarEmOrdem(No* no) {
        if (no == nullptr) {
            return;
        }

        listarEmOrdem(no->esquerda);

        cout << no->aluno.nome
             << " - Matricula: " << no->aluno.matricula
             << " - Curso: " << no->aluno.curso << endl;

        listarEmOrdem(no->direita);
    }

    // Calcula a altura da arvore por arestas
    int altura(No* no) {
        if (no == nullptr) {
            return -1;
        }

        int alturaEsquerda = altura(no->esquerda);
        int alturaDireita = altura(no->direita);

        if (alturaEsquerda > alturaDireita) {
            return alturaEsquerda + 1;
        }

        return alturaDireita + 1;
    }

    // Libera a memoria utilizada pela arvore
    void destruir(No* no) {
        if (no == nullptr) {
            return;
        }

        destruir(no->esquerda);
        destruir(no->direita);
        delete no;
    }

public:
    ArvoreABB() {
        raiz = nullptr;
        total = 0;
    }

    ~ArvoreABB() {
        destruir(raiz);
    }

    // Metodo publico para inserir aluno
    void inserirAluno(int matricula, string nome, string curso) {
        if (matriculaExiste(raiz, matricula)) {
            cout << "Matricula ja cadastrada!" << endl;
            return;
        }

        Aluno aluno;
        aluno.matricula = matricula;
        aluno.nome = nome;
        aluno.curso = curso;

        raiz = inserir(raiz, aluno);
    }

    // Metodo publico para buscar aluno
    void buscarAluno(string nome) {
        No* resultado = buscar(raiz, nome);

        if (resultado == nullptr) {
            cout << "Aluno nao encontrado!" << endl;
        }
        else {
            cout << endl;
            cout << "Aluno encontrado:" << endl;
            cout << "Nome: " << resultado->aluno.nome << endl;
            cout << "Matricula: " << resultado->aluno.matricula << endl;
            cout << "Curso: " << resultado->aluno.curso << endl;
        }
    }

    // Metodo publico para listar todos os alunos
    void listarAlunos() {
        if (raiz == nullptr) {
            cout << "Nenhum aluno cadastrado." << endl;
            return;
        }

        cout << endl;
        cout << "--- Alunos em ordem alfabetica ---" << endl;
        listarEmOrdem(raiz);
    }

    // Mostra total de alunos e altura da arvore
    void exibirInformacoes() {
        cout << endl;
        cout << "--- Informacoes da arvore ---" << endl;
        cout << "Total de alunos: " << total << endl;
        cout << "Altura da arvore: " << altura(raiz) << endl;
    }
};

int main() {
    ArvoreABB arvore;
    int opcao;

    do {
        cout << endl;
        cout << "===== MENU =====" << endl;
        cout << "1 - Inserir aluno" << endl;
        cout << "2 - Buscar aluno" << endl;
        cout << "3 - Listar alunos em ordem alfabetica" << endl;
        cout << "4 - Exibir informacoes da arvore" << endl;
        cout << "5 - Carregar exemplo" << endl;
        cout << "0 - Sair" << endl;
        cout << "Opcao: ";
        cin >> opcao;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (opcao == 1) {
            int matricula;
            string nome;
            string curso;

            cout << "Matricula: ";
            cin >> matricula;

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Nome completo: ";
            getline(cin, nome);

            cout << "Curso: ";
            getline(cin, curso);

            arvore.inserirAluno(matricula, nome, curso);
        }
        else if (opcao == 2) {
            string nome;

            cout << "Digite o nome do aluno: ";
            getline(cin, nome);

            arvore.buscarAluno(nome);
        }
        else if (opcao == 3) {
            arvore.listarAlunos();
        }
        else if (opcao == 4) {
            arvore.exibirInformacoes();
        }
        else if (opcao == 5) {
            arvore.inserirAluno(101, "John Smith", "Engenharia de Software");
            arvore.inserirAluno(102, "Alice Johnson", "Sistemas de Informacao");
            arvore.inserirAluno(103, "Michael Brown", "Ciencia da Computacao");
            arvore.inserirAluno(104, "Emily Davis", "Engenharia de Software");

            cout << "Exemplo carregado com sucesso!" << endl;
        }
        else if (opcao != 0) {
            cout << "Opcao invalida!" << endl;
        }

    } while (opcao != 0);

    cout << "Programa encerrado." << endl;

    return 0;
}