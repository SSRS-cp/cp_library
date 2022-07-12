---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Math/Convolution_(FFT).cpp\"\ndouble PI = acos(-1);\nvector<complex<double>>\
    \ fft(vector<complex<double>> A, bool inv){\n\tint N = A.size();\n\tcomplex<double>\
    \ r = polar((double) 1, (2 * PI) / (N));\n\tif (inv){\n\t\tr = pow(r, -1);\n\t\
    }\n\tvector<complex<double>> B(N);\n\tfor (int i = N / 2; i > 0; i /= 2){\n\t\t\
    complex<double> z = pow(r, i);\n\t\tcomplex<double> z2 = 1;\n\t\tfor (int j =\
    \ 0; j < N; j += i * 2){\n\t\t\tfor (int k = 0; k < i; k++){\n\t\t\t\tA[i + j\
    \ + k] *= z2;\n\t\t\t\tB[j / 2 + k] = A[j + k] + A[i + j + k];\n\t\t\t\tB[N /\
    \ 2 + j / 2 + k] = A[j + k] - A[i + j + k];\n\t\t\t}\n\t\t\tz2 *= z;\n\t\t}\n\t\
    \tswap(A, B);\n\t}\n\tif (inv){\n\t\tfor (int i = 0; i < N; i++){\n\t\t\tA[i]\
    \ /= N;\n\t\t}\n\t}\n\treturn A;\n}\nvector<double> convolution(vector<double>\
    \ A, vector<double> B){\n\tint deg = A.size() + B.size() - 1;\n\tint N = 1;\n\t\
    while (N < deg){\n\t\tN *= 2;\n\t}\n\tvector<complex<double>> A2(N, 0);\n\tfor\
    \ (int i = 0; i < A.size(); i++){\n\t\tA2[i] = A[i];\n\t}\n\tvector<complex<double>>\
    \ B2(N, 0);\n\tfor (int i = 0; i < B.size(); i++){\n\t\tB2[i] = B[i];\n\t}\n\t\
    A2 = fft(A2, false);\n\tB2 = fft(B2, false);\n\tvector<complex<double>> C2(N);\n\
    \tfor (int i = 0; i < N; i++){\n\t\tC2[i] = A2[i] * B2[i];\n\t}\n\tC2 = fft(C2,\
    \ true);\n\tvector<double> C(deg);\n\tfor (int i = 0; i < deg; i++){\n\t  C[i]\
    \ = C2[i].real();\n\t}\n\treturn C;\n}\n"
  code: "double PI = acos(-1);\nvector<complex<double>> fft(vector<complex<double>>\
    \ A, bool inv){\n\tint N = A.size();\n\tcomplex<double> r = polar((double) 1,\
    \ (2 * PI) / (N));\n\tif (inv){\n\t\tr = pow(r, -1);\n\t}\n\tvector<complex<double>>\
    \ B(N);\n\tfor (int i = N / 2; i > 0; i /= 2){\n\t\tcomplex<double> z = pow(r,\
    \ i);\n\t\tcomplex<double> z2 = 1;\n\t\tfor (int j = 0; j < N; j += i * 2){\n\t\
    \t\tfor (int k = 0; k < i; k++){\n\t\t\t\tA[i + j + k] *= z2;\n\t\t\t\tB[j / 2\
    \ + k] = A[j + k] + A[i + j + k];\n\t\t\t\tB[N / 2 + j / 2 + k] = A[j + k] - A[i\
    \ + j + k];\n\t\t\t}\n\t\t\tz2 *= z;\n\t\t}\n\t\tswap(A, B);\n\t}\n\tif (inv){\n\
    \t\tfor (int i = 0; i < N; i++){\n\t\t\tA[i] /= N;\n\t\t}\n\t}\n\treturn A;\n\
    }\nvector<double> convolution(vector<double> A, vector<double> B){\n\tint deg\
    \ = A.size() + B.size() - 1;\n\tint N = 1;\n\twhile (N < deg){\n\t\tN *= 2;\n\t\
    }\n\tvector<complex<double>> A2(N, 0);\n\tfor (int i = 0; i < A.size(); i++){\n\
    \t\tA2[i] = A[i];\n\t}\n\tvector<complex<double>> B2(N, 0);\n\tfor (int i = 0;\
    \ i < B.size(); i++){\n\t\tB2[i] = B[i];\n\t}\n\tA2 = fft(A2, false);\n\tB2 =\
    \ fft(B2, false);\n\tvector<complex<double>> C2(N);\n\tfor (int i = 0; i < N;\
    \ i++){\n\t\tC2[i] = A2[i] * B2[i];\n\t}\n\tC2 = fft(C2, true);\n\tvector<double>\
    \ C(deg);\n\tfor (int i = 0; i < deg; i++){\n\t  C[i] = C2[i].real();\n\t}\n\t\
    return C;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Math/Convolution_(FFT).cpp
  requiredBy: []
  timestamp: '2021-09-08 13:47:42+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/Convolution_(FFT).cpp
layout: document
redirect_from:
- /library/Math/Convolution_(FFT).cpp
- /library/Math/Convolution_(FFT).cpp.html
title: Math/Convolution_(FFT).cpp
---
