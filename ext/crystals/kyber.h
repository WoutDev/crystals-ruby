#ifndef RUBY_CRYSTALS_H__
#define RUBY_CRYSTALS_H__

#include "ml-kem-512/api.h"

#include "ruby.h"

RUBY_EXTERN VALUE rb_cKyber;

RUBY_EXTERN void Init_Kyber(VALUE Crystals);

#endif