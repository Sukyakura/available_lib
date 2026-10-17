# 形式的冪級数（FPS）完全版＋頻出母関数テンプレ

---

# 1. 等比級数系（最重要）

## 基本

$$
\frac{1}{1-x} = \sum_{n=0}^{\infty} x^n
$$

$$
\frac{1}{1-ax} = \sum_{n=0}^{\infty} a^n x^n
$$

---

## 重複組合せ

$$
\frac{1}{(1-x)^k}
=
\sum_{n=0}^{\infty}
\binom{n+k-1}{k-1} x^n
$$

---

# 2. n, n^2, n^3 系（超重要）

## Σ n x^n

$$
\sum_{n=0}^{\infty} n x^n
=
\frac{x}{(1-x)^2}
$$

---

## Σ n^2 x^n

$$
\sum_{n=0}^{\infty} n^2 x^n
=
\frac{x(1+x)}{(1-x)^3}
$$

---

## Σ n^3 x^n

$$
\sum_{n=0}^{\infty} n^3 x^n
=
\frac{x(1+4x+x^2)}{(1-x)^4}
$$

---

## 一般形

$$
\sum_{n=0}^{\infty} n^k x^n
=
\frac{x P_k(x)}{(1-x)^{k+1}}
$$

ここで $P_k(x)$ は次数 $k$ の多項式。

---

# 3. 指数・対数系

$$
\exp(x)
=
\sum_{n=0}^{\infty}
\frac{x^n}{n!}
$$

$$
\log\frac{1}{1-x}
=
\sum_{n=1}^{\infty}
\frac{x^n}{n}
$$

---

# 4. 二項展開

$$
(1+x)^k
=
\sum_{n=0}^{\infty}
\binom{k}{n} x^n
$$

---

# 5. 線形漸化式

$$
a_n = c_1 a_{n-1} + \dots + c_k a_{n-k}
$$

$$
F(x)
=
\frac{\text{初期多項式}}
{1 - c_1 x - \dots - c_k x^k}
$$

---

# 6. FPS演算（ACL想定）

- 畳み込み：O(n log n)
- 逆元：O(n log n)
- log：O(n log n)
- exp：O(n log n)
- sqrt：O(n log n)
- 冪乗：O(n log n)

---

# 7. 競プロ最頻出パターン

### ★★★★★
- 1/(1-x)
- 1/(1-x)^k
- Σ n x^n
- Σ n^2 x^n
- 逆元
- 畳み込み

### ★★★★
- exp
- log
- 線形漸化式

---