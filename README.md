# Option-Pricing

[![Build Status](https://github.com/GAprea/Option-Pricing/actions/workflows/ci.yml/badge.svg)](https://github.com/GAprea/Option-Pricing/actions)  
[![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg)](LICENSE)

A modern C++17 library for pricing European FX call options under the lognormal model, offering four methods:

- **Black–Scholes** closed-form  
- **Monte Carlo** simulation with variance-reduction hooks  
- **PDE** via Crank–Nicolson finite differences  
- **Quadrature** (Simpson’s rule) on the risk-neutral density  

---

## 📦 Installation

1. Clone this repo:
   ```bash
   git clone https://github.com/GAprea/Option-Pricing.git
   cd Option-Pricing
