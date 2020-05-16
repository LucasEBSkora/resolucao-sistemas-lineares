
#include "Matriz.hpp"
#include "ResolvedorEliminacao.hpp"
#include "constantes.hpp"

#include <iostream>

int main () {

  std::cout << "atenção! esse programa considera valores menores em módulo do que " << constantes::epsilon << " como 0" << std::endl;

  Matriz matriz("teste.matriz");

  matriz.imprimirComoMatrizAumentada();

  std::cout << '\n';

  ResolvedorEliminacao resolvedor(matriz);

  Matriz* resposta = resolvedor.resolver();


  std::cout << '\n';
  std::cout << '\n';


  resposta->imprimirComoMatrizAumentada();

  return 0;  
}