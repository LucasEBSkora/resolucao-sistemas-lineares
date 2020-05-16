
#include "Matriz.hpp"

#include "ResolvedorEliminacao.hpp"
int main () {


  Matriz matriz("1.matriz");

  ResolvedorEliminacao resolvedor(matriz);

  Matriz* resposta = resolvedor.resolver();

  resposta->imprimir();
  delete resposta;

  return 0;  
}