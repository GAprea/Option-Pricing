#pragma once

namespace fx {

/// Quadrature (Simpson’s Rule) price for a European FX call.
double quadrature_price(
    double S0, double K, double T,
    double sigma, double r_d, double r_f,
    std::size_t n_steps);

} // namespace fx
