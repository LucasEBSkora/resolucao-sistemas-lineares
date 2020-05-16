#include "Matriz.hpp"

class Resolvedor {
  protected:
    Matriz* matriz;

  public:
    Resolvedor(const Matriz& m);
    virtual ~Resolvedor();
    virtual Matriz* resolver() = 0;
};