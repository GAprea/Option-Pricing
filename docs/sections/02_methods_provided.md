# Methods Provided

- **Analytical (Black–Scholes)**  
  Closed‐form formula under the lognormal assumption, computed in $O(1)$ time per call.

- **Monte Carlo Simulation**  
  Flexible estimator via random sampling; can handle exotic or path-dependent payoffs with optional variance reduction.

- **PDE (Crank–Nicolson)**  
  Implicit finite‐difference solution of the backward PDE. Unconditionally stable, second-order accurate in both time and space.

- **Quadrature (Simpson’s Rule)**  
  Direct numerical integration of the risk-neutral density for integrable payoffs, using composite Simpson’s rule.
