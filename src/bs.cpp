#include "fxoptions/bs.hpp"
#include <cmath>

namespace fx {
namespace {
    static double norm_cdf(double x) {
        return 0.5 * std::erfc(-x / std::sqrt(2.0));
    }
}

double black_scholes_price(
    double S0, double K, double T,
    double sigma, double r_d, double r_f)
{
    double srt = sigma * std::sqrt(T);
    double d1 = (std::log(S0/K) + (r_d - r_f + 0.5*sigma*sigma)*T) / srt;
    double d2 = d1 - srt;
    return S0*std::exp(-r_f*T)*norm_cdf(d1)
         - K*std::exp(-r_d*T)*norm_cdf(d2);
}

} // namespace fx
