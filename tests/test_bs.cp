#define CATCH_CONFIG_MAIN
#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>
#include "fxoptions/bs.hpp"

TEST_CASE("Black‑Scholes call price for EUR/USD at strike 1.185", "[bs]") {
    // Market parameters as of July 1, 2025
    double S0    = 1.18;       // Spot FX rate EUR/USD
    double K     = 1.185;      // Strike price
    double T     = 36.0 / 365; // Time to expiry ≈ 0.0986 years
    double sigma = 0.1023;     // Implied volatility ≈ 10.23%
    double r_d   = 0.0215;     // EUR interest rate (domestic)
    double r_f   = 0.0433;     // USD interest rate (foreign)

    double p = fx::black_scholes_price(S0, K, T, sigma, r_d, r_f);

    // Expected call price from prior output
    REQUIRE_THAT(p, Catch::Matchers::WithinAbs(0.0116448, 1e-6));
}
