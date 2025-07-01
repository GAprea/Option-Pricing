#include "fxoptions/mc.hpp"
#include <random>
#include <algorithm>
#include <cmath>

namespace fx {

double monte_carlo_price(
    double S0, double K, double T,
    double sigma, double r_d, double r_f,
    std::size_t n_paths)
{
    std::mt19937_64 rng{std::random_device{}()};
    std::normal_distribution<double> nd(0.0,1.0);
    double sum = 0.0;
    for (std::size_t i=0; i<n_paths; ++i) {
        double z = nd(rng);
        double ST = S0 * std::exp((r_d - r_f - 0.5*sigma*sigma)*T
                    + sigma*std::sqrt(T)*z);
        sum += std::max(ST - K, 0.0);
    }
    return std::exp(-r_d*T) * (sum / n_paths);
}

} // namespace fx
