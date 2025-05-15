# frozen_string_literal: true

module Crystals
  class Kyber
    def initialize(security_level = 1024)
      raise "Invalid security level: #{security_level}" unless [512, 768, 1024].include?(security_level)

      @security_level = security_level
    end
  end
end