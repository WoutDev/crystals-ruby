#include "kyber.h"

VALUE rb_cKyber;
VALUE rb_cPublicKey;
VALUE rb_cPrivateKey;
VALUE rb_cCiphertext;

// TODO: Have this depend on the security_level of the Kyber object
#define PKBYTES pqcrystals_kyber512_PUBLICKEYBYTES
#define SKBYTES pqcrystals_kyber512_SECRETKEYBYTES

VALUE generate_keypair() {
    uint8_t pk[PKBYTES];
    uint8_t sk[SKBYTES];

    pqcrystals_kyber512_ref_keypair(pk, sk);

    VALUE rb_pk = rb_str_new((const char*)pk, PKBYTES);
    VALUE rb_sk = rb_str_new((const char*)sk, SKBYTES);

    return rb_ary_new_from_args(2, rb_pk, rb_sk);
}

void Init_Kyber(VALUE Crystals) {
    rb_cKyber = rb_define_class_under(Crystals, "Kyber", rb_cObject);

    rb_define_method(rb_cKyber, "generate_keypair", generate_keypair, 0);
}
