
#include "Matriz.hpp"
#include "ResolvedorEliminacao.hpp"
#include "constantes.hpp"

#include <iostream>

int main (int argc, char **argv) {
  if (argc != 3) {
    std::cout << "Utilização: ./build/ex caminho N\n"
    "\tOnde caminho é o caminho para o arquivo que armazena a matriz, no qual a primeira linha armazena as dimensões da matriz, separados por espaços,\n"
    "\tE as linhas seguintes armazenam os valores das entradas da matriz, também separados por espaços.\n"
    "\n\tE N é o método de resolução à utilizar, onde:"
    "\n\t\t0 -> Método da eliminação de Gauss-Jordan.\n"
    << std::endl;
    return -1;
  }

  std::cout << "atenção! esse programa considera valores menores em módulo do que " << constantes::epsilon << " como 0\n" << std::endl;
  
  Matriz matriz(argv[1]);

  matriz.imprimirComoMatrizAumentada();
  std::cout << '\n';

  int N = atoi(argv[2]);

  Resolvedor* resolvedor;

  switch (N) {
  case 0:
    resolvedor = new ResolvedorEliminacao(matriz);
    break;
  default:
    std::cout << "Valor inválido de N! Os valores válidos são:\n\t\t0 -> Método da eliminação de Gauss-Jordan." << std::endl;
    return -1;
    break;
  }

  Matriz* resposta = resolvedor->resolver();


  std::cout << '\n';
  std::cout << '\n';


  resposta->imprimirComoMatrizAumentada();

  delete resolvedor;

  return 0;  
}