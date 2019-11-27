#! /usr/bin/env ruby
require "numo/narray"

science = Numo::DFloat[65,80,67,35,58,60,72,75,68,92,36,50,2,58.5,46,42,78,62,84,70]
english = Numo::DFloat[44,87,100,63,52,60,58,73,55,86,29,56,89,23,65,84,64,27,86,84]

printf("-------理科-------\n 平均:")
puts science.mean
printf(" 標準偏差:")
puts science.stddev
printf(" 合計:")
puts science.sum
printf("-------英語-------\n 平均:")
puts english.mean
printf(" 標準偏差:")
puts english.stddev
printf(" 合計:")
puts english.sum

puts '------偏差値-------'
for i in 1..20
  printf(" 理科:%f  ",(science[i-1]-science.mean)/science.stddev*10+50)
  printf("英語:%f\n",(english[i-1]-english.mean)/english.stddev*10+50)
end

printf("\n-----並び替え------\n理科:")
p science.sort.reverse
printf("英語:")
p english.sort.reverse
