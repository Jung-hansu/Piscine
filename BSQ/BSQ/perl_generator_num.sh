#!/usr/bin/perl
use warnings;
use strict;
die "program x y density" unless (scalar(@ARGV) == 3);
my ($x, $y, $density) = @ARGV;
print "$y\x31\x30\x37\n";
for (my $i = 0; $i < $y; $i++) {
    for (my $j = 0; $j < $x; $j++) {
if (int(rand($y) * 2) < $density) {
    print "\x30";
}
else { 
print "\x31"; }
}
print "\n"; }
# 공백 1 장애물 0 박스 7
# perl perl_generator.sh 10 10 1 > map10x10
# ./BSQ map10x10