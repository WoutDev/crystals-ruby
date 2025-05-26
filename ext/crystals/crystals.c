#include "ruby.h"
#include "kyber.h"

VALUE Crystals = Qnil;

void Init_crystals() {
    Crystals = rb_define_module("Crystals");

    Init_Kyber(Crystals);
}
