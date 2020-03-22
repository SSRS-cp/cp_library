# Data_Structures
## UnionFind
UnionFind木 (経路圧縮のみ) です。

```C++
int unionfind_root(vector<int> &parent, int x)
```
UnionFind木parentの頂点xの根を求めます。

```C++
bool unionfind_union(vector<int> &parent, int x, int y)
```
UnionFind木parentの頂点xと頂点yの属するグループを併合します。頂点xと頂点yが同じグループに属していた場合trueを、そうでない場合はfalseを返します。

## UnionFind_2
UnionFind木 (経路圧縮+rank)です。

## Segment_Tree
セグメント木でRange Minimum Queryを行います。

```C++
vector<int> segtree(vector<int> &A)
```
配列Aからセグメント木を構築します。

```C++
void segtree_update(vector<int> &ST, int i, int x)
```
セグメント木STのA[i]にあたる要素をxに更新します。

```C++
int segtree_query(vector<int> &ST, int x, int y, int i, int L, int R)
```
セグメント木STの[x,y)区間に対するクエリの結果を、区間[L,R)に対応するセグメント木STの要素iが求めます。

# Graph
## Single_Source_Shortest_Path_(Dijkstra)
ダイクストラ法を利用して、単一始点最短路の長さを求めます。

```C++
vector<long long> dijkstra(vector<vector<pair<int, int>>> &E, int s)
```
重み付きグラフEの頂点sを始点とする単一始点最短路を求めます。頂点sから到達できない頂点に対してはINFを返します。

## Single_Source_Shortest_Path_(Bellman_Ford)
ベルマンフォード法を利用して、単一始点最短路の長さを求めます。

```C++
vector<long long> bellman_ford(vector<vector<pair<int, int>>> &E, int s)
```
重み付きグラフEの頂点sを始点とする単一始点最短路を求めます。頂点sから到達できない頂点にはINFを返します。

```C++
bool detect_negative_cycles(vector<vector<pair<int, int>>> &E, int s)
```
重み付きグラフEに、頂点sから到達可能な負の閉路が存在するかを求めます。存在する場合はtrue、存在しない場合はfalseを返します。

```C++
bool detect_negative_cycles_2(vector<vector<pair<int, int>>> &E)
```
重み付きグラフEに、負の閉路が存在するかを求めます。

```C++
vector<bool> find_negative_cycles(vector<vector<pair<int, int>>> &E)
```
重み付きグラフEのすべての負の閉路を検出します。負の閉路に含まれる頂点に対してはtrue、そうでない頂点に対してはfalseを返します。

## All_Pairs_Shortest_Path_(Warshall_Floyd)
ワーシャルフロイド法を利用して、全点対間最短路の長さを求めます。

```C++
vector<vector<long long>> warshall_floyd(vector<vector<pair<int, int>>> &E)
```
重み付きグラフEの全点対間最短路の長さを求めます。頂点sから頂点tに到達できない場合、その頂点対に対応する要素に対してはINFを返します。

# Dynamic_Programming
## Longest_Common_Subsequence
動的計画法を利用して、最長共通部分列を求めます。

```C++
int longest_common_subsequence_length(string &S, string &T)
```
文字列Sと文字列Tの最長共通部分列の長さを求めます。

```C++
string longest_common_subsequence(string &S, string &T)
```
文字列Sと文字列Tの最長共通部分列を求めます。

```C++
int longest_common_subsequence_length(vector<int> &A, vector<int> &B)
```
配列Aと配列Bの最長共通部分列の長さを求めます。

```C++
vector<int> longest_common_subsequence(vector<int> &A, vector<int> &B)
```
配列Aと配列Bの最長共通部分列を求めます。

## Matrix_Chain_Multiplication
動的計画法を利用して、連鎖行列積問題を解きます。

```C++
long long matrix_chain_multiplication(vector<long long> &A)
```
行列M_0, M_1, ..., M_{n-2}があり、M_iがA_i×A_{i+1}行列である(0≦i≦n-1)とき、積M_0M_1...M_{n-2}を計算するのに必要なスカラーの乗算回数の最小値を求めます。

# Math
## Modulo
MODで割った余りを扱います。MODの値はグローバル変数として与えられる必要があります。MODは素数である必要があります。

```C++
long long modsub(long long a, long long b)
```
a-bをMODで割った余りを求めます。aとbは非負整数である必要があります。

```C++
long long modpow(long long a, long long b)
```
二分累乗法を利用して、aのb乗をMODで割った余りを求めます。

```C++
long long modinv(long long a)
```
aの逆元を求めます。

```C++
long long modfact(long long n)
```
nの階乗をMODで割った余りを求めます。値は配列mfに記録され、再利用されます。

```C++
long long modbinom1(long long n, long long r)
```
二項係数nCrをMODで割った余りを求めます。それぞれのクエリに対しO(1)で値を返しますが、O(n)の前計算が必要になります。

```C++
long long modbinom2(long long n, long long r)
```
二項係数nCrをMODで割った余りを求めます。nが大きくても計算できますが、それぞれのクエリに対しO(r)の時間が必要になります。

## Catalan Number
カタラン数を求めます。

```C++
long long catalan_number(long long n)
```
カタラン数C_nをMODで割った余りを求めます。
