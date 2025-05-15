require "mkmf"

abort "missing malloc()" unless have_func("malloc")
abort "missing free()"   unless have_func("free")

$INCFLAGS << " -I$(srcdir)/ml-kem-512"
puts $INCFLAGS

KYBER_REF = File.join(File.expand_path('.', __dir__), "ml-kem-512")
Dir.chdir(KYBER_REF) do
  system('make') or abort "ERROR: failed to build Kyber in #{KYBER_REF}"
end

$LIBPATH << File.join(KYBER_REF)
$libs = append_library($libs, "ml-kem-512_clean")
$LDFLAGS << " -Wl,-rpath,#{File.join(KYBER_REF)}"

create_makefile "crystals/crystals"
