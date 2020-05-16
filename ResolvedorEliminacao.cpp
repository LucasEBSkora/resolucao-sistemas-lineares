#include "ResolvedorEliminacao.hpp"

#include <iostream>
#include <math.h>

#include "constantes.hpp"

ResolvedorEliminacao::ResolvedorEliminacao(Matriz& m) : Resolvedor{m} {

}

ResolvedorEliminacao::~ResolvedorEliminacao() {

}

Matriz* ResolvedorEliminacao::resolver() {
  std::cout << "Método de eliminação de gauss-jordan com pivoteamento parcial: \n" << std::endl;

  for (unsigned int i = 0; i < matriz->getLargura() - 1; ++i) {

    std::cout << "Procurando pivô na "<< i + 1 << " coluna:\n" << std::endl;

    unsigned int melhorPivo = i;
    for (unsigned int j = i; j < matriz->getAltura(); ++j)
      if ( fabs((*matriz)[j][i]) > fabs((*matriz)[melhorPivo][i])) melhorPivo = j;

    bool linhaPivoZerado = true;
    
    unsigned int j;
    for (j = 0; j < matriz->getLargura() - 1; ++j) 
      if (fabs((*matriz)[melhorPivo][j]) > constantes::epsilon) {

        linhaPivoZerado = false;
        break;
      }

    if (linhaPivoZerado && fabs((*matriz)[melhorPivo][j]) > constantes::epsilon) {
      std::cout << "equação sem resolução na linha " << melhorPivo + 1 << "! Terminando processamento.\n" << std::endl;
      return matriz; 
    }
    

    if ((*matriz)[melhorPivo][i] == 0.0) {
      std::cout << "\tEssa coluna tem todos os coeficientes zerados! Continuando para a próxima.\n" << std::endl;
      continue;
    }


    if (melhorPivo != i) {
      std::cout << "\tO melhor pivô está na " << melhorPivo + 1 << "ª linha! Trocando a linha " << i + 1 << " com a linha " << melhorPivo + 1 << ":\n" << std::endl;

      matriz->trocarLinhas(i, melhorPivo);
      matriz->imprimirComoMatrizAumentada();
    } else {
      std::cout << "\n\tO melhor pivô já está na linha " << i + 1 << " então nada precisa ser feito.\n" << std::endl;
    }

    if ((*matriz)[i][i] != 1.0) {
      std::cout << "\nnormalizando linha:\n" << std::endl;
      //Li <- Li*(1/m[i][i])
      std::cout << "\n\t L" << i + 1 << "<- L" << i + 1 << "*(1/"<< (*matriz)[i][i] << ")\n" << std::endl;
      matriz->multiplicarLinha(i, 1.0/(*matriz)[i][i]);

      matriz->imprimirComoMatrizAumentada();

    }

    std::cout << "\nAnulando coeficientes na coluna do pivo:\n" << std::endl;

    for (unsigned int j = 0; j < matriz->getAltura(); ++j) {
      if (j != i && (*matriz)[j][i] != 0.0) {
        //Lj <- Lj - (m[j][i])*Li
        std::cout << "\n\tL" << j + 1 << "<- L" << j + 1 << " -(" << (*matriz)[j][i] << ")*L" << i + 1 << '\n' <<std::endl;
        matriz->somarLinhas(j, i, -(*matriz)[j][i]);
        matriz->imprimirComoMatrizAumentada();
      }
    }


    
  }

  return matriz;
}
