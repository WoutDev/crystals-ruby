require "mkmf"

abort "missing malloc()" unless have_func("malloc")
abort "missing free()"   unless have_func("free")

$INCFLAGS << " -I$(srcdir)/pq-crystals"
puts $INCFLAGS

KYBER_REF = File.join(File.expand_path('.', __dir__), "pq-crystals/kyber/ref")
Dir.chdir(KYBER_REF) do
    system('make', 'shared') or abort "ERROR: failed to build Kyber in #{KYBER_REF}"

    # TODO: Look at why pqcrystals don't include this in their Makefile. There are GitHub issues about this.
    system('cp randombytes.c randombytes.h ../../..') or abort "ERROR: failed to copy randombytes"
end

$LIBPATH << File.join(KYBER_REF, 'lib')
$libs = append_library($libs, "pqcrystals_kyber512_ref")
$libs = append_library($libs, "pqcrystals_fips202_ref")
$LDFLAGS << " -Wl,-rpath,#{File.join(KYBER_REF, 'lib')}"

create_makefile "crystals/crystals"
