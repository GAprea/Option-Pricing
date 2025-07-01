# Explanation & Notes

## Black–Scholes

<p align="center">
  <img
    src="../images/equations/d1.svg"
    alt="d1 formula"
    style="background-color: white;"
  /><br/>
  <img
    src="../images/equations/d2.svg"
    alt="d2 formula"
    style="background-color: white;"
  /><br/>
  <img
    src="../images/equations/bs.svg"
    alt="Black–Scholes formula"
    style="background-color: white;"
  />
</p>

---

## Monte Carlo Simulation

<p align="center">
  <img
    src="../images/equations/mc.svg"
    alt="MC terminal S_T"
    style="background-color: white;"
  /><br/>
  <img
    src="../images/equations/payoff.svg"
    alt="discounted payoff"
    style="background-color: white;"
  />
</p>

---

## PDE (Crank–Nicolson)

<p align="center">
  <img
    src="../images/equations/pde.svg"
    alt="Black–Scholes PDE"
    style="background-color: white;"
  />
</p>

on \([0,S_{\max}]\times[0,T]\) with  
- **Terminal**: \(V(S,T)=\max(S-K,0)\)  
- **Boundaries**: \(V(0,t)=0\),  
  \(V(S_{\max},t)=S_{\max}-K\,e^{-r_d(T-t)}\)

---

## Quadrature (Simpson’s Rule)

<p align="center">
  <img
    src="../images/equations/quad.svg"
    alt="quadrature integral"
    style="background-color: white;"
  />
</p>

via composite Simpson’s rule, where \(f_{\mathrm{LN}}\) is the risk-neutral lognormal density.
