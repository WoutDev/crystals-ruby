require "mkmf"

abort "missing malloc()" unless have_func "malloc"
abort "missing free()"   unless have_func "free"

abort 'missing git executable' unless find_executable('git')

result = xsystem 'git clone git@github.com:pq-crystals/dilithium.git'
puts result
puts $@

create_makefile "crystals/crystals"