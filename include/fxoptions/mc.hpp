#pragma once
#include <cstddef>

namespace fx {

/// Monte Carlo price for a European FX call.
double monte_carlo_price(
    double S0, double K, double T,
    double sigma, double r_d, double r_f,
    std::size_t n_paths);

} // namespace fx
