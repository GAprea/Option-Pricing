# Explanation & Notes

## Black–Scholes

<p align="center">
  <img src="../images/equations/d1.png" alt="d1 formula" /><br/>
  <img src="../images/equations/d2.png" alt="d2 formula" /><br/>
  <img src="../images/equations/bs.png"  alt="Black–Scholes formula" />
</p>

---

## Monte Carlo Simulation

<p align="center">
  <img src="../images/equations/mc.png"     alt="MC terminal S_T" /><br/>
  <img src="../images/equations/payoff.png" alt="discounted payoff" />
</p>

---

## PDE (Crank–Nicolson)

<p align="center">
  <img src="../images/equations/pde.png" alt="Black–Scholes PDE" />
</p>

on \([0,S_{\max}]\times[0,T]\) with  
- **Terminal**: \(V(S,T)=\max(S-K,0)\)  
- **Boundaries**: \(V(0,t)=0\),  
  \(V(S_{\max},t)=S_{\max}-K\,e^{-r_d(T-t)}\)

---

## Quadrature (Simpson’s Rule)

<p align="center">
  <img src="../images/equations/quad.png" alt="quadrature integral" />
</p>

via composite Simpson’s rule, where \(f_{\mathrm{LN}}\) is the risk-neutral lognormal density.  
