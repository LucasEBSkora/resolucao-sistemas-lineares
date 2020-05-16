#include "Matriz.hpp"

#include <stdlib.h> 

#include <math.h>

#include <iostream>
#include <iomanip>
#include <fstream>

#include "constantes.hpp"

Matriz::Matriz(const std::vector<std::vector<double>> m) {
  altura = m.size();
  if (!altura) exit(-1);
  largura = m[0].size();

  for (auto linha : m) {
    while (linha.size() != largura) linha.push_back(0.0);
  }

  matriz = new double*[altura];

  for (unsigned int i = 0; i < altura; ++i) {
    matriz[i] = new double[largura];
  }

  for (unsigned int i = 0; i < altura; ++i) {
    for (unsigned int j = 0; j < largura; ++j) {
      matriz[i][j] = m[i][j];
    }
  }

}

Matriz::Matriz(const char *caminho) {
  std::ifstream arquivo(caminho);

  if (!arquivo.is_open()) exit(-1);

  arquivo >> altura;
  arquivo >> largura;

  matriz = new double*[altura];

  for (unsigned int i = 0; i < altura; ++i) {
    matriz[i] = new double[largura];
  }

  for (unsigned int i = 0; i < altura; ++i) 
    for (unsigned int j = 0; j < largura; ++j) 
      arquivo >> matriz[i][j];

}

Matriz::Matriz() : matriz{nullptr}, largura{0}, altura{0} {

}

Matriz::Matriz(const Matriz& m) : largura{m.getLargura()}, altura{m.getAltura()} {
  matriz = new double*[altura];

  for (unsigned int i = 0; i < altura; ++i) {
    matriz[i] = new double[largura];
  }

  for (unsigned int i = 0; i < altura; ++i) 
    for (unsigned int j = 0; j < largura; ++j) 
      matriz[i][j] = m[i][j];
}

Matriz::~Matriz() {
  for (unsigned int i = 0; i < altura; ++i) delete[] matriz[i];
  delete []matriz;
}

const double* Matriz::operator [](unsigned int indice) const {
  if (indice >= altura) exit(-1);
  else return matriz[indice];
}

void Matriz::multiplicarLinha(unsigned int indice, double valor) {
  double* linha = matriz[indice];
  for (unsigned int i = 0; i < largura; ++i) 
    linha[i] *= valor;
}

void Matriz::trocarLinhas(unsigned int indice1, unsigned int indice2) {
  double* aux = matriz[indice1];
  matriz[indice1] = matriz[indice2];
  matriz[indice2] = aux;
}

void Matriz::somarLinhas(unsigned int indice1, unsigned int indice2, double coeficiente /*= 1*/) {
  double* linha1 = matriz[indice1];
  double* linha2 = matriz[indice2];
  for (unsigned int i = 0; i < largura; ++i) {
    linha1[i] += coeficiente*linha2[i];
  }

}

unsigned int Matriz::getLargura() const {
  return largura;
}

unsigned int Matriz::getAltura() const {
  return altura;
}

void Matriz::imprimir(unsigned short precisao /* = 5*/) const {

  
  std::cout << std::fixed << std::setprecision(precisao);

  unsigned short algarismosEsquerdaVirgula = 0;
  for (unsigned int i = 0; i < altura; ++i) {
    for (unsigned int j = 0; j < largura; ++j) {
      double espacos = 0;
      double valor = fabs(matriz[i][j]);
      espacos += ceil(log10(valor));

      if (espacos > algarismosEsquerdaVirgula) algarismosEsquerdaVirgula = espacos;
    }
  }

  unsigned short espacos = precisao + algarismosEsquerdaVirgula;

  for (unsigned int i = 0; i < altura; ++i) {
    std::cout << "| ";
    for (unsigned int j = 0; j < largura; ++j) {
      if (matriz[i][j] > -constantes::pseudozero) std::cout << " ";
      std::cout << std::setw(espacos) << matriz[i][j] << " ";
    }
    std::cout << "|\n";
  }

  std::cout.flush();
}

void Matriz::imprimirComoMatrizAumentada(unsigned short precisao /*= 5*/) const {
  
  
  std::cout << std::fixed << std::setprecision(precisao);

  unsigned short algarismosEsquerdaVirgula = 0;
  for (unsigned int i = 0; i < altura; ++i) {
    for (unsigned int j = 0; j < largura; ++j) {
      double espacos = 0;
      double valor = fabs(matriz[i][j]);
      espacos += ceil(log10(valor));

      if (espacos > algarismosEsquerdaVirgula) algarismosEsquerdaVirgula = espacos;
    }
  }

  unsigned short espacos = precisao + algarismosEsquerdaVirgula;

  for (unsigned int i = 0; i < altura; ++i) {
    std::cout << "| ";
    for (unsigned int j = 0; j < largura - 1; ++j) {
      if (matriz[i][j] > -constantes::pseudozero) std::cout << " ";
      std::cout << std::setw(espacos) << matriz[i][j] << " ";
    }

    std::cout << "| ";
    if (matriz[i][largura - 1] >= -constantes::pseudozero) std::cout << " ";
    std::cout << std::setw(espacos) << matriz[i][largura - 1] << " ";
    
    std::cout << "|\n";
  }

  std::cout.flush();
}