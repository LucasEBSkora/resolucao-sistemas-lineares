#include "Resolvedor.hpp"
#include "Matriz.hpp"

class ResolvedorEliminacao : public Resolvedor {
  public:
    ResolvedorEliminacao(Matriz& m);
    ~ResolvedorEliminacao();
    Matriz* resolver();
};