# Explanation & Notes

## Black–Scholes

<div align="center">
  <img 
    src="https://latex.codecogs.com/svg.latex?\displaystyle
    d_1 = \frac{\ln(S_0/K) + (r_d - r_f + \tfrac{1}{2}\sigma^2)\,T}
                {\sigma\sqrt{T}}"
    alt="d1 formula" />
</div>

<div align="center">
  <img 
    src="https://latex.codecogs.com/svg.latex?\displaystyle
    d_2 = d_1 - \sigma\sqrt{T}"
    alt="d2 formula" />
</div>

Then the call price is

<div align="center">
  <img 
    src="https://latex.codecogs.com/svg.latex?\displaystyle
    C = S_0\,e^{-r_fT}\,N(d_1)\;-\;K\,e^{-r_dT}\,N(d_2)"
    alt="Black-Scholes formula" />
</div>

---

## Monte Carlo Simulation

<div align="center">
  <img
    src="https://latex.codecogs.com/svg.latex?\displaystyle
    S_T^{(i)} = S_0\exp\bigl((r_d - r_f - \tfrac12\sigma^2)T
      + \sigma\sqrt{T}\,Z_i\bigr)"
    alt="MC terminal S_T" />
</div>

The discounted payoff is

<div align="center">
  <img
    src="https://latex.codecogs.com/svg.latex?\displaystyle
    \exp(-r_dT)\,\max\bigl(S_T^{(i)} - K,\,0\bigr)"
    alt="discounted payoff" />
</div>

---

## PDE (Crank–Nicolson)

Solve backwards the Black–Scholes PDE:

<div align="center">
  <img
    src="https://latex.codecogs.com/svg.latex?\displaystyle
    V_t + (r_d - r_f)\,S\,V_S + \tfrac12\sigma^2\,S^2\,V_{SS} - r_d\,V = 0"
    alt="BS PDE" />
</div>

on \([0,S_{\max}]\times[0,T]\) with  
- **Terminal**: \(V(S,T)=\max(S-K,0)\)  
- **Boundaries**: \(V(0,t)=0,\quad V(S_{\max},t)=S_{\max}-K\,e^{-r_d(T-t)}\)

---

## Quadrature (Simpson’s Rule)

Compute the integral

<div align="center">
  <img
    src="https://latex.codecogs.com/svg.latex?\displaystyle
    \int_K^{S_{\max}}(S-K)\,f_{\mathrm{LN}}(S)\,\mathrm{d}S"
    alt="quadrature integral" />
</div>

via composite Simpson’s rule, where \(f_{\mathrm{LN}}\) is the risk-neutral lognormal density.
