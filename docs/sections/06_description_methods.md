# Description of Methods

**Black–Scholes**  
Exact analytical solution under lognormal dynamics, computed in $O(1)$ time per call.

**Monte Carlo Simulation**  
Flexible estimator via random sampling; can handle exotic or path-dependent payoffs. Variance reduction (antithetic, control variates) can be enabled.

**PDE Solver (Crank–Nicolson)**  
Implicit finite-difference scheme solving the backward PDE. Unconditionally stable, second-order accurate in both time and space.

**Quadrature (Simpson’s Rule)**  
Direct numerical integration of the risk-neutral density for integrable payoffs, using composite Simpson’s rule.
