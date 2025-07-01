#pragma once
#include <cmath>

namespace fx {

/// Black–Scholes analytical price for a European FX call.
double black_scholes_price(
    double S0, double K, double T,
    double sigma, double r_d, double r_f);

} // namespace fx
