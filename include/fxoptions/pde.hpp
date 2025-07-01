#pragma once
#include <cstddef>

namespace fx {

/// PDE (Crank–Nicolson) price for a European FX call.
double pde_cn_price(
    double S0, double K, double T,
    double sigma, double r_d, double r_f,
    std::size_t M, std::size_t N);

} // namespace fx
