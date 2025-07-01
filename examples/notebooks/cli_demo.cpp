#include <iostream>
#include "fxoptions/bs.hpp"
#include "fxoptions/mc.hpp"

int main(int argc, char* argv[]) {
    if (argc < 7) {
        std::cout << "Usage: fxpricer S0 K T sigma r_d r_f\n";
        return 1;
    }
    double S0    = std::atof(argv[1]);
    double K     = std::atof(argv[2]);
    double T     = std::atof(argv[3]);
    double sigma = std::atof(argv[4]);
    double r_d   = std::atof(argv[5]);
    double r_f   = std::atof(argv[6]);

    auto bs = fx::black_scholes_price(S0,K,T,sigma,r_d,r_f);
    std::cout << "BS Price: " << bs << "\n";

    auto mc = fx::monte_carlo_price(S0,K,T,sigma,r_d,r_f,200000);
    std::cout << "MC Price: " << mc << "\n";
    return 0;
}
