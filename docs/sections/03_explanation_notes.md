# Explanation & Notes

## Black–Scholes

Define  
\[
d_1 = \frac{\ln(S_0/K) + (r_d - r_f + \tfrac12\sigma^2)\,T}{\sigma\sqrt{T}},\quad
d_2 = d_1 - \sigma\sqrt{T}.
\]  
Then  
\[
C = S_0 e^{-r_f T} N(d_1) - K e^{-r_d T} N(d_2),
\]  
where $N(\cdot)$ is the standard normal CDF.

## Monte Carlo Simulation

Draw $Z_i\sim\mathcal N(0,1)$ and simulate  
\[
S_T^{(i)} = S_0 \exp\!\bigl((r_d - r_f - \tfrac12\sigma^2)T + \sigma\sqrt{T}\,Z_i\bigr).
\]  
The discounted payoff  
\[
\exp(-r_d T)\max(S_T^{(i)} - K, 0)
\]  
is averaged over all paths.

## PDE (Crank–Nicolson)

Solve backwards the PDE  
\[
V_t + (r_d - r_f)S\,V_S + \tfrac12\sigma^2 S^2\,V_{SS} - r_d V = 0
\]  
on $[0,S_{\max}]\times[0,T]$, with  
- Terminal: $V(S,T)=\max(S-K,0)$  
- Boundary: $V(0,t)=0$,  
  $V(S_{\max},t)=S_{\max}-K e^{-r_d (T-t)}$.

## Quadrature (Simpson’s Rule)

Compute  
\[
\int_K^{S_{\max}}(S-K)\,f_{\mathrm{LN}}(S)\,\mathrm{d}S
\]  
using composite Simpson’s rule, where $f_{\mathrm{LN}}$ is the risk-neutral lognormal density.
