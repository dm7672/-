int sz;

struct matrix {
    ll mat[sz][sz];
    matrix friend operator *(const matrix &a, const matrix &b){
        matrix c;
        for (int i = 0; i < sz; i++) {
          for (int j = 0; j < sz; j++) {
              c.mat[i][j] = 0;
              for (int k = 0; k < sz; k++) {
                  c.mat[i][j] += a.mat[i][k] * b.mat[k][j];
              }
          }
        }
        return c;
    }
};

matrix matpow(matrix base, ll n) {
    matrix ans{ {
      {1, 0},
      {0, 1}
    } }; // ans = E
    while (n) {
        if(n&1)
            ans = ans*base;
        base = base*base;
        n >>= 1;
    }
    return ans;
}
