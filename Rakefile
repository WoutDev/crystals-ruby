# frozen_string_literal: true

require "bundler/gem_tasks"
require "rspec/core/rake_task"

RSpec::Core::RakeTask.new(:spec)

require "rubocop/rake_task"

RuboCop::RakeTask.new

task default: %i[spec rubocop]

require "rake/extensiontask"

Rake::ExtensionTask.new "crystals" do |ext|
  ext.lib_dir = "lib/crystals"
end