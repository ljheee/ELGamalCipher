# ELGamalCipher
ELGamal加解密算法（c语言实现）。
非对称加密算法，和RSA类似。

ELGamal密码体制是T.ElGamal在1985年提出的公钥密码体制。它的安全性是基于求解离散对数问题的困难性，是RSA以后比较有希望的一个公钥密码。美国的DSS(Digital Signature Standard)的DSA(Digital Signature Algorithm)算法就是经ElGamal算法演变而来。目前DSA算法应用也非常广泛。
1．公钥的生成算法
    系统提供一个大素数p和GF(p)上的本原元素g。对每一个用户A可选择
    XA∈[ 0, 1, 2, ……,p-1]
    计算YA = gXA mod p
    其中，XA就是用户的私钥，YA就成为用户的公钥，将YA公开，XA保密，由A自己掌握。
2．加密算法
    若A欲与B保密通信，设明文是m，m∈[ 0, 1, 2, ……,p-1]则可按如下步骤进行：
    （1）A找出B的公钥YB = gXB mod p
    （2）A任意选随机数x∈[ 0, 1, 2, ……,p-1]，A计算C1 = (g)x mod p
    （3）A计算：K = (YB)x mod p = (gx)XB mod p，求C2  = ( K*m ) mod p
    （4）A将（C1，C2）作为密文发送给B
3．解密算法
    B收到密文以后解密方法如下：
    （1）B用自己的密钥XB计算：K = (YB)x mod p = (gx)XB mod p = (C1)XB mod p
    （2）B计算：K-1 mod p
    （3）求m = ( K-1*C2 ) mod p
    举例说明如下：
    设p = 11，g = 7，在GF（11）上有70=1，71=7，72=5，73=2，74=3，75=10，76=4，77=6，78=9，79=8，710=1，因此7是GF（11）上的本原元素。
    设A的私钥XA = 3，公钥YA = 2；B的私钥XB = 5，公钥YB = 10，假定A要将信息m = 7发送给B，A取随机数x = 5，A计算C1 = g5 mod 11 = 10，K = (YB)5 mod 11 = 10，C2 = K*m mod 11 = 70 mod 11 = 4。A 将（10，4）作为密文发送给B，B收到后计算K = (C1)XB mod p = 105 mod 11 = 10，K-1 = 10（根据K* K-1 = 1 mod 11），则m = K-1* C2  = 40 mod 11 = 7。
