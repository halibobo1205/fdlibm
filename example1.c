//
// Created by lizibo on 2022/4/8.
//

#include "fdlibm.h"
#include "stdlib.h"
#include "stdio.h"


long cal(long balance, long quant) {
    long newBalance = balance + quant;
    double g = pow(1.0 +  (double)29218/4761432,0.0005);
    printf("g = %1.64e\n", g);
    double e = pow(1.0 +  (double)29218/newBalance,0.0005);
    printf("e = %1.64e\n", e);
    double f = pow(1.0 +  (double)quant/newBalance, 0.0005);
    printf("f = %1.64e\n", f);
    return 0;
}


int main() {
    cal(4732214,29218);
    exit(0);
}


