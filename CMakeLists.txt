cmake_minimum_required(VERSION 3.22)
project(myAccount C)

set(CMAKE_C_STANDARD 99)

add_executable(myAccount main.c account/myAccount2.c account/myAccount1.c cmr/customerManage.c)
