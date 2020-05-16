#include "ResolvedorEliminacao.hpp"

#include <iostream>
#include <math.h>

ResolvedorEliminacao::ResolvedorEliminacao(Matriz& m) : Resolvedor{m} {

}

ResolvedorEliminacao::~ResolvedorEliminacao() {

}

Matriz* ResolvedorEliminacao::resolver() {
  std::cout << "Metodo de eliminacao de gauss-jordan com pivoteamento parcial: \n" << std::endl;

  for (unsigned int i = 0; i < matriz->getLargura() - 1; ++i) {
    std::cout << "Procurando pivô na "<< i + 1 << "ª coluna: " << std::endl;

    unsigned int melhorPivo = 0;
    for (unsigned int j = 1; j < matriz->getAltura(); ++j)
      if ( fabs((*matriz)[j][i]) > fabs((*matriz)[melhorPivo][i])) melhorPivo = j;

    if ((*matriz)[melhorPivo][i] == 0.0) {
      std::cout << "Essa coluna tem todos os coeficientes zerados! Continuando para a proxima.\n" << std::endl;
      continue;
    }

    if (melhorPivo != i) {
      std::cout << "O melhor pivo esta na " << melhorPivo + 1 << "ª linha! Trocando a linha " << i + 1 << " com a linha " << melhorPivo + 1 << ':' << std::endl;

      matriz->trocarLinhas(i, melhorPivo);
      matriz->imprimirComoMatrizAumentada();
    } else {
      std::cout << "O melhor pivo ja esta na linha " << i + 1 << "entao nada precisa ser feito.\n" << std::endl;
    }

    if ((*matriz)[i][i] != 1.0) {
      std::cout << "normalizando linha:\n" << std::endl;
      //Li <- Li*(1/m[i][i])
      std::cout << "\t L" << i + 1 << "<- L" << i + 1 << "*(1/"<< (*matriz)[i][i] << ")\n" << std::endl;
      matriz->multiplicarLinha(i, 1.0/(*matriz)[i][i]);

      matriz->imprimirComoMatrizAumentada();

    }

    std::cout << "Anulando coeficientes na coluna do pivo:\n" << std::endl;

    for (unsigned int j = 0; j < matriz->getAltura(); ++j) {
      if (j != i && (*matriz)[j][i] != 0.0) {
        //Lj <- Lj - (m[j][i])*Li
        std::cout << "\tL" << j + 1 << "<- L" << j + 1 << " -(" << (*matriz)[j][i] << ")*L" << i + 1 << '\n' <<std::endl;
        matriz->somarLinhas(j, i, -(*matriz)[j][i]);
        matriz->imprimirComoMatrizAumentada();
      }
    }


    
  }

  return matriz;
}
