#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include "fxoptions/bs.hpp"

TEST_CASE("BS price vs known value", "[bs]") {
    double p = fx::black_scholes_price(1.2,1.25,1.0,0.15,0.05,0.02);
    REQUIRE( Approx(p).margin(1e-6) == 0.0644887 );
}
