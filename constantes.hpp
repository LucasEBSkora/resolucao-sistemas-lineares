#ifndef __CONSTANTES_HPP__
#define __CONSTANTES_HPP__

#include <limits>

namespace constantes {
  const double pseudozero{std::numeric_limits<double>().min()};
  const double epsilon{1e-10};
}

#endif