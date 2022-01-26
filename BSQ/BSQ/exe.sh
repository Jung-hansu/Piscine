#!/bin/sh
#perl perl_generator.sh 0 0 1 > map1
#perl perl_generator.sh 10 10 1 > map2
perl perl_generator_num.sh 15 15 1 > map
cat map
make all
./BSQ map
make fclean