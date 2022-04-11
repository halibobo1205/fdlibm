//
// Created by lizibo on 2022/4/8.
//

#include "fdlibm.h"
#include "stdlib.h"
#include "stdio.h"


long supply = 1000000000000000000L;

long exchangeToSupply(long balance, long quant) {
    long newBalance = balance + quant;
    double issuedSupply = (double) -supply * (1.0 - pow(1.0 + (double) (quant) / (double) (newBalance), 0.0005));
    long out = (long) issuedSupply;
    supply += out;
    return out;
}

long exchangeFromSupply(long balance, long supplyQuant) {
    supply -= supplyQuant;
    double exchangeBalance = (double) balance * (pow(1.0 + (double) supplyQuant / (double) supply, 2000.0) - 1.0);
    return (long) exchangeBalance;
}

long Exchange(long sellTokenBalance, long buyTokenBalance, long sellTokenQuant) {
    long relay = exchangeToSupply(sellTokenBalance, sellTokenQuant);
    return exchangeFromSupply(buyTokenBalance, relay);
}

int main() {
    double y0();
    printf("y0(1e300) = %1.20e\n", y0(1e300));
    //double y0();
    /*_LIB_VERSION =  _IEEE_;
    printf("IEEE: y0(1e300) = %1.20e\n",y0(1e300));
    _LIB_VERSION = _XOPEN_;
    printf("XOPEN y0(1e300) = %1.20e\n",y0(1e300));
    _LIB_VERSION = _POSIX_;
    printf("POSIX y0(1e300) = %1.20e\n",y0(1e300));
    _LIB_VERSION = _SVID_;
    printf("SVID  y0(1e300) = %1.20e\n",y0(1e300));*/
    printf("%ld", Exchange(4732214, 2202692725330, 29218) + 608405);
    exit(0);
}


