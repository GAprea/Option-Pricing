#include "fxoptions/pde.hpp"
#include <vector>
#include <algorithm>
#include <cmath>

namespace fx {

double pde_cn_price(
    double S0, double K, double T,
    double sigma, double r_d, double r_f,
    std::size_t M, std::size_t N)
{
    double Smax = 3 * std::max(S0, K);
    double dS   = Smax / M;
    double dt   = T / N;

    std::vector<double> S(M+1), V(M+1);
    for (std::size_t i=0; i<=M; ++i) {
        S[i] = i*dS;
        V[i] = std::max(S[i] - K, 0.0);
    }

    std::vector<double> a(M-1), b(M-1), c(M-1);
    double A = r_d - r_f, sq = sigma*sigma;
    for (std::size_t i=1; i<M; ++i) {
        a[i-1] = -0.25*dt*(sq*i*i - A*i);
        b[i-1] =  1.0 + 0.5*dt*(sq*i*i + r_d);
        c[i-1] = -0.25*dt*(sq*i*i + A*i);
    }

    std::vector<double> c_star(M-1), d_star(M-1);
    for (int n=int(N)-1; n>=0; --n) {
        std::vector<double> d(M-1);
        double t = n*dt;
        double V0 = 0.0;
        double VM = Smax - K*std::exp(-r_d*(T-t));

        for (std::size_t i=1; i<M; ++i) {
            double alpha =  0.25*dt*(sq*i*i - A*i);
            double beta  =  1.0 - 0.5*dt*(sq*i*i + r_d);
            double gamma =  0.25*dt*(sq*i*i + A*i);
            d[i-1] = alpha*V[i-1] + beta*V[i] + gamma*V[i+1];
        }
        d[0]    -= a[0]*V0;
        d[M-2]  -= c[M-2]*VM;

        c_star[0] = c[0]/b[0];
        d_star[0] = d[0]/b[0];
        for (std::size_t i=1; i<M-1; ++i) {
            double m = b[i] - a[i]*c_star[i-1];
            c_star[i] = c[i]/m;
            d_star[i] = (d[i] - a[i]*d_star[i-1]) / m;
        }

        std::vector<double> Vnew(M-1);
        Vnew[M-2] = d_star[M-2];
        for (int i=int(M)-3; i>=0; --i)
            Vnew[i] = d_star[i] - c_star[i]*Vnew[i+1];

        for (std::size_t i=1; i<M; ++i)
            V[i] = Vnew[i-1];
        V[0] = V0; V[M] = VM;
    }

    std::size_t idx = std::min<std::size_t>(std::floor(S0/dS), M-1);
    double w = (S0 - S[idx]) / dS;
    return V[idx]*(1-w) + V[idx+1]*w;
}

} // namespace fx
