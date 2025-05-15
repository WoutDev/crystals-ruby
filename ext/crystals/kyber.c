#include "kyber.h"

VALUE rb_cKyber;
VALUE rb_cPublicKey;
VALUE rb_cPrivateKey;
VALUE rb_cCiphertext;

// TODO: Have this depend on the security_level of the Kyber object
#define PKBYTES PQCLEAN_MLKEM512_CLEAN_CRYPTO_PUBLICKEYBYTES
#define SKBYTES PQCLEAN_MLKEM512_CLEAN_CRYPTO_SECRETKEYBYTES

VALUE generate_keypair(VALUE self) {
    uint8_t pk[PKBYTES];
    uint8_t sk[SKBYTES];

    PQCLEAN_MLKEM512_CLEAN_crypto_kem_keypair(pk, sk);

    VALUE rb_pk = rb_str_new((const char*)pk, PKBYTES);
    VALUE rb_sk = rb_str_new((const char*)sk, SKBYTES);

    return rb_ary_new_from_args(2, rb_pk, rb_sk);
}

void Init_Kyber(VALUE Crystals) {
    rb_cKyber = rb_define_class_under(Crystals, "Kyber", rb_cObject);

    rb_define_method(rb_cKyber, "generate_keypair", generate_keypair, 0);
}
