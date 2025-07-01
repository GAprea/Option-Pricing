# Introduction

Foreign-exchange (FX) options are fundamental building blocks in global finance, allowing market participants to hedge currency risk or speculate on future exchange rate moves. Under the risk-neutral measure, the spot rate $S$ evolves according to

\[
  \mathrm{d}S = (r_d - r_f)\,S\,\mathrm{d}t + \sigma\,S\,\mathrm{d}W,
\]

so that

\[
  \ln\!\bigl(S_T / S_0\bigr)
  \sim
  \mathcal{N}\!\Bigl((r_d - r_f - \tfrac12\sigma^2)\,T,\;\sigma^2\,T\Bigr).
\]

Here $r_d$ and $r_f$ are the domestic and foreign interest rates, and $\sigma$ is the volatility. This library provides four methods to price a European FX call option.
