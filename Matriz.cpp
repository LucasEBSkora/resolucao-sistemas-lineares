#include "Matriz.hpp"

#include <stdlib.h>
#include <iostream>
#include <iomanip>

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

Matriz::~Matriz() {
  for (unsigned int i = 0; i < altura; ++i) delete matriz[i];
  delete matriz;
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
  double* linha1 = matriz[indice1];
  double* linha2 = matriz[indice2];
  double aux;
  for (unsigned int i = 0; i < largura; ++i) {
    aux = linha1[i];
    linha1[i] = linha2[i];
    linha2[i] = aux;
  }
}

void Matriz::somarLinhas(unsigned int indice1, unsigned int indice2, double coeficiente = 1) {
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

void Matriz::imprimir(unsigned short precisao) const {
  std::cout << std::fixed << std::setprecision(precisao);
  
  for (unsigned int i = 0; i < altura; ++i) {
    for (unsigned int j = 0; j < largura; ++j) {
      std::cout << matriz[i][j] << " ";
    }
    std::cout << '\n';
  }

  std::cout.flush();
}
