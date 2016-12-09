//非对称加密算法，和RSA类似

bool IsNumber(const char *strNumber);
unsigned int PublicKey(unsigned int xKey);
bool ELGamal_encrypt(int yKey, char * mw, int &c1w, int *&c2w);
bool ELGamal_decrypt(int xKey, int c1w, int *c2w, char *mw, int cLong);