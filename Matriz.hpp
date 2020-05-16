#ifndef __MATRIZ_HPP__
#define __MATRIZ_HPP__

#include <vector>

class Matriz {
  private: 

    static double pseudozero;


    double** matriz;
    unsigned int largura;
    unsigned int altura;

  public:
    //Para carregar de um vetor criado em tempo de execução ou através de uma lista de inicialização
    Matriz(std::vector<std::vector<double>> m);
    //Para criar a partir de um arquivo
    Matriz(const char* caminhoArquivo);
    //Vazio
    Matriz();
    //Construtor cópia
    Matriz(const Matriz& m);
    // Matriz(unsigned int linhas, unsigned int colunas);
    ~Matriz();
    const double* operator [](unsigned int indice) const;
    void multiplicarLinha(unsigned int indice, double valor);
    void trocarLinhas(unsigned int indice1, unsigned int indice2);
    void somarLinhas(unsigned int indice1, unsigned int indice2, double coeficiente = 1);
    unsigned int getLargura() const;
    unsigned int getAltura() const;
    void imprimir(unsigned short precisao = 5) const;
    void imprimirComoMatrizAumentada(unsigned short precisao = 5) const;
};

#endif