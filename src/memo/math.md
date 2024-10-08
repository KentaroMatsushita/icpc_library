
## 二項係数
|n\k|0|1|2|3|4|5|6|7|8|9|10|
|:-----------|:-----------|:-----------|:-----------|:-----------|:-----------|:-----------|:-----------|:-----------|:-----------|:-----------|:-----------|
|**0**|1|
|**1**|1|1|
|**2**|1|2|1|
|**3**|1|3|3|1|
|**4**|1|4|6|4|1|
|**5**|1|5|10|10|5|1|
|**6**|1|6|15|20|15|6|1|
|**7**|1|7|21|35|35|21|7|1|
|**8**|1|8|28|56|70|56|28|8|1|
|**9**|1|9|36|84|126|126|84|36|9|1|
|**10**|1|10|45|120|210|252|210|120|45|10|1|
|**11**|1|11|55|165|330|462|462|330|165|55|11|
|**12**|1|12|66|220|495|792|924|792|495|220|66|
|**13**|1|13|78|286|715|1287|1a716|1716|1287|715|286|
|**14**|1|14|91|364|1001|2002|3003|3432|3003|2002|1001|
|**15**|1|15|105|455|1365|3003|5005|6435|6435|5005|3003|
|**16**|1|16|120|560|1820|4368|8008|11440|12870|11440|8008|
|**17**|1|17|136|680|2380|6188|12376|19448|24310|24310|19448|
|**18**|1|18|153|816|3060|8568|18564|31824|43758|48620|43758|
|**19**|1|19|171|969|3876|11628|27132|50388|75582|92378|92378|
|**20**|1|20|190|1140|4845|15504|38760|77520|125970|167960|184756|

$\binom{n}{k}=\binom{n-1}{k-1}+\binom{n-1}{k}$
$\binom{n}{k}=\frac{n}{k}\binom{n-1}{k-1}$
$\binom{L}{k}+\dots+\binom{R-1}{k}=\binom{R}{k+1}-\binom{L}{k+1}$

## 第一種スターリング数
$c(n,k)$: $1,2,\dots,n$ の順列で巡回置換 $k$ 個に分割できるものの個数

|$n$ \ $k$|0|1|2|3|4|5|6|7|
|:-----------|:-----------|:-----------|:-----------|:-----------|:-----------|:-----------|:-----------|:-----------|
|**0**|1|
|**1**|0|1|
|**2**|0|1|1|
|**3**|0|2|3|1|
|**4**|0|6|11|6|1|
|**5**|0|24|50|35|10|1|
|**6**|0|120|274|225|85|15|1
|**7**|0|720|1764|1624|735|175|21|1

$c(n,k)=c(n-1,k-1)+(n-1)c(n-1,k)$
$x(x+1)\dots(x+n-1)=\sum_{k=0}^n c(n,k)x^k$
$\sum_{k=0}^nc(n,k)=n!$
$\sum_{k=0}^n  2^kc(n,k)=(n+1)!$
$\sum_{k=0}^n(-1)^kc(n,k)=0$

$\sum_{k=0}^n c(n,k)x^k=x(x+1)\dots(x+n-1)$ を用いて分割統治し，片方の計算を polynomial taylor shift で再利用すると，$c(N,k)$ の $k$ に関する列挙が $O(N\log N)$ 時間でできる．

## 第二種スターリング数
$S(n,k)$: $1,2,\dots,n$ を $k$ 個の区別しない集合に分割する方法の数
|$n$ \ $k$|0|1|2|3|4|5|6|7|
|:-----------|:-----------|:-----------|:-----------|:-----------|:-----------|:-----------|:-----------|:-----------|
|**0**|1|
|**1**|0|1|
|**2**|0|1|1|
|**3**|0|1|3|1|
|**4**|0|1|7|6|1|
|**5**|0|1|15|25|10|1|
|**6**|0|1|31|90|65|15|1
|**7**|0|1|63|301|350|140|21|1

$S(n,k)=S(n-1,k-1)+kS(n-1,k)$
$x^n=\sum_{k=0}^nS(n,k)x(x-1)\dots(x-k+1)$
$S(n,k)=\frac{1}{k!}\sum_{m=1}^k(-1)^{k-m}\binom{k}{m}m^n$

最後の式と畳み込みを使うと $S(N,k)$ の $k$ に関する列挙が $O(N\log N)$ 時間でできる．

## ベル数
$B_n$: $1,2,\dots,n$ をいくつかの集合に分割する方法の数
|$n$|0|1|2|3|4|5|6|7|8|9|10|
|:-----------|:-----------|:-----------|:-----------|:-----------|:-----------|:-----------|:-----------|:-----------|:-----------|:-----------|:-----------|
|$B_n$|1|1|2|5|15|52|203|877|4140|21147|115975|

$B_{n+1}=\sum_{k=0}^n\binom{n}{k}B_k$
$B_n=\frac{1}{e}\sum_{k=0}^\infty\frac{k^n}{k!}$


指数型母関数 $\exp(\exp x - 1)=\sum_{n=0}^\infty B_n\frac{x^n}{n!}$ を使うと $B_0, B_1, \dots, B_n$ の計算が $O(N\log N)$ でできる．


## カタラン数
$C_n$: $n$ 個の $($ と $)$ を括弧列になるように並べる方法の数
|$n$|0|1|2|3|4|5|6|7|8|9|10|
|:-----------|:-----------|:-----------|:-----------|:-----------|:-----------|:-----------|:-----------|:-----------|:-----------|:-----------|:-----------|
|$C_n$|1|1|2|5|14|42|132|429|1430|4862|16796|

$C_n=\frac{1}{n+1}\binom{2n}{n}=\frac{(2n)!}{(n+1)!n!}$
$C_{n+1}=\frac{2(2n+1)}{n+2}C_n$
$C_{n+1}=\sum_{k=0}^nC_kC_{n-k}$

## モンモール数
$a_n$: $1,2,\dots,n$ の順列 $P$ で $P_i \neq i$ となるものの個数
|$n$|0|1|2|3|4|5|6|7|8|9|10|
|:-----------|:-----------|:-----------|:-----------|:-----------|:-----------|:-----------|:-----------|:-----------|:-----------|:-----------|:-----------|
|$a_n$||0|1|2|9|44|265|1854|14833|133496|1334961|

$a_n=(n-1)(a_{n-1}+a_{n-2})$
$a_n=na_{n-1}+(-1)^n$

## 分割数
$P_n$: $n$ を正の整数の和として表す方法の数
|$n$|0|1|2|3|4|5|6|7|8|9|10|
|:-----------|:-----------|:-----------|:-----------|:-----------|:-----------|:-----------|:-----------|:-----------|:-----------|:-----------|:-----------|
|$P_n$|1|1|2|3|5|7|11|15|22|30|42|

母関数は $\prod_{n=1}^\infty \frac{1}{1-x^n}=\sum_{n=0}^\infty P_nx^n$ である．五角数定理より $\prod_{n=1}^\infty (1-x^n)=\sum_{n=-\infty}^\infty (-1)^nx^{n(3n+1)/2}$ なので，$P_0,P_1,\dots,P_N$ を $O(N\log N)$ 時間で列挙できる．

## 母関数
$\frac{1}{1-x}=1+x+x^2+x^3+x^4+\dots=\sum_{n=0}^\infty x^n$

$\frac{1}{(1-x)^2}=1+2x+3x^2+4x^3+5x^4+\dots=\sum_{n=0}^\infty (n+1)x^n$

$\frac{1}{(1-x)^3}=1+3x+6x^2+10x^3+15x^4+\dots=\sum_{n=0}^\infty \frac{1}{2}(n+1)(n+2)x^n$

$\frac{1}{(1-x)^d}=\sum_{n=0}^\infty \binom{n+d-1}{n}x^n$

$\sqrt{1-x}=1-\frac{1}{2}x-\frac{1}{8}x^2-\frac{1}{16}x^3-\frac{5}{128}x^4-\dots=1-\sum_{n=1}^\infty \frac{(2n-2)!}{2^{2n-1}n!(n-1)!}x^n$

$\frac{1}{\sqrt{1-x}}=1+\frac{1}{2}x+\frac{3}{8}x^2+\frac{5}{16}x^3+\frac{35}{128}x^4-\dots=\sum_{n=0}^\infty \frac{(2n)!}{4^n n!}x^n$

$\frac{1-\sqrt{1-4x}}
{2x}=1+x+2x^2+5x^3+14x^4+\dots=\sum_{n=0}^\infty C_nx^n=\sum_{n=0}^\infty \frac{(2n)!}{(n+1)!n!}x^n$ (カタラン数)

$\frac{1}{\sqrt{1-4x}}=\sum_{n=0}^\infty\binom{2n}{n}x^n$

$\frac{1}{1-x-x^2}=1+x+2x^2+3x^3+5x^4+\dots=\sum_{n=0}^\infty F_nx^n$ (フィボナッチ数)

$\log(1-x)=-x-\frac{1}{2}x^2-\frac{1}{3}x^3-\frac{1}{4}x^4-\dots=\sum_{n=1}^\infty \frac{1}{n}x^n$

$\exp(\exp x - 1) = \sum_{n=0}^\infty B_n \frac{x^n}{n}$ (ベル数)

$\frac{1}{k}(\exp x - 1)^k = \sum_{n=0}^\infty S(n,k)\frac{x^n}{n!}$ (第二種スターリング数)

$\frac{\exp(-x)}{1-x}=1+\frac{1}{2}x^2+\frac{1}{3}x^3+\frac{3}{8}x^4+\dots=\sum_{n=0}^\infty a_n\frac{x^n}{n!}$ (モンモール数)

$C(x)^k=\left(\frac{1-\sqrt{1-4x}}{2x}\right)^k=\sum_{n=0}^\infty \frac{k}{n+k}\binom{2n+k-1}{n}$ (カタラン数の母関数の累乗)

