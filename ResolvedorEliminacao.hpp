#ifndef __RESOLVEDOR_ELIMINACAO_HPP__
#define __RESOLVEDOR_ELIMINACAO_HPP__

#include "Resolvedor.hpp"
#include "Matriz.hpp"

class ResolvedorEliminacao : public Resolvedor {
  public:
    ResolvedorEliminacao(Matriz& m);
    ~ResolvedorEliminacao();
    Matriz* resolver();
};

#endif