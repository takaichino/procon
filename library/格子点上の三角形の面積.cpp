//x[j-l]: x座標
//y[j-l]: y座標
//点jと点kを通る直線: ax+by+c=0

a = y[k] - y[j];
b = x[j] - x[k];
c = x[k] * y[j] - x[j] * y[k];
s = abs(a * x[l] + b * y[l] + c) / 2.0; //面積はXXXX.0かXXXX.5