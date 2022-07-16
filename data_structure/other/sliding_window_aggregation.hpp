#pragma once
/**
 * @brief Sliding Window Aggregation
*/
template <typename T>
struct sliding_window_aggregation{
  function<T(T, T)> f;
  T E;
  stack<pair<T, T>> fr, bk;
  sliding_window_aggregation(function<T(T, T)> f, T E): f(f), E(E){
  }
  void push(T x){
    if (fr.empty()){
      fr.push(make_pair(x, x));
    } else {
      fr.push(make_pair(x, f(fr.top().second, x)));
    }
  }
  void pop(){
    if (bk.empty()){
      while (!fr.empty()){
        T x = fr.top().first;
        fr.pop();
        if (bk.empty()){
          bk.push(make_pair(x, x));
        } else {
          bk.push(make_pair(x, f(x, bk.top().second)));
        }
      }
    }
    bk.pop();
  }
  T get(){
    T ans1 = E;
    if (!fr.empty()){
      ans1 = fr.top().second;
    }
    T ans2 = E;
    if (!bk.empty()){
      ans2 = bk.top().second;
    }
    return f(ans2, ans1);
  }
};