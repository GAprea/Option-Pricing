#include "fxoptions/quadrature.hpp"
#include <cmath>

namespace fx {

double quadrature_price(
    double S0, double K, double T,
    double sigma, double r_d, double r_f,
    std::size_t n_steps)
{
    if (n_steps % 2) ++n_steps;
    double Smax = S0 * std::exp((r_d - r_f)*T + 6*sigma*std::sqrt(T));
    double h    = (Smax - K) / n_steps;

    auto density = [&](double S){
        double mu  = (r_d - r_f - 0.5*sigma*sigma)*T;
        double var = sigma*sigma*T;
        double x   = std::log(S/S0);
        return std::exp(-0.5*(x-mu)*(x-mu)/var)
             / (S*std::sqrt(2*M_PI*var));
    };

    auto integrand = [&](double S){ return (S-K)*density(S); };

    double sum = integrand(K) + integrand(Smax);
    for (std::size_t i=1; i<n_steps; ++i) {
        double factor = (i%2==0 ? 2.0 : 4.0);
        sum += factor * integrand(K + i*h);
    }
    return std::exp(-r_d*T) * (h/3.0) * sum;
}

} // namespace fx
