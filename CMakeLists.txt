cmake_minimum_required(VERSION 3.2.0)

# Library as INTERFACE; does not produce build output
add_library(mint INTERFACE)

target_include_directories(mint INTERFACE include/)
