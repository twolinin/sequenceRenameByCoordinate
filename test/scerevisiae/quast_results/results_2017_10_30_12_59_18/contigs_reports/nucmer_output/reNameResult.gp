set terminal canvas jsdir ""
set output "/bip7_disk/jyunhong_104/sequenceRenameByCoordinate/test/scerevisiae/quast_results/results_2017_10_30_12_59_18/contigs_reports/nucmer_output/reNameResult.html"
set xtics rotate ( \
 "0" 0, \
 "2000000" 2000000, \
 "4000000" 4000000, \
 "6000000" 6000000, \
 "8000000" 8000000, \
 "10000000" 10000000, \
 "12000000" 12000000, \
 "" 12157105 \
)
set ytics ( \
 "0" 0, \
 "2000000" 2000000, \
 "4000000" 4000000, \
 "6000000" 6000000, \
 "8000000" 8000000, \
 "10000000" 10000000, \
 "12000000" 12000000, \
 "" 12325448 \
)
set size 1,1
set grid
set key outside bottom right
set border 0
set tics scale 0
set xlabel "Reference" noenhanced
set ylabel "Assembly" noenhanced
set format "%.0f"
set xrange [1:12157105]
set yrange [1:12325448]
set linestyle 1  lt 1 lc rgb "red" lw 3 pt 7 ps 0.5
set linestyle 2  lt 3 lc rgb "blue" lw 3 pt 7 ps 0.5
set linestyle 3  lt 2 lc rgb "yellow" lw 3 pt 7 ps 0.5
plot \
 "/bip7_disk/jyunhong_104/sequenceRenameByCoordinate/test/scerevisiae/quast_results/results_2017_10_30_12_59_18/contigs_reports/nucmer_output/reNameResult.fplot" title "FWD" w lp ls 1, \
 "/bip7_disk/jyunhong_104/sequenceRenameByCoordinate/test/scerevisiae/quast_results/results_2017_10_30_12_59_18/contigs_reports/nucmer_output/reNameResult.rplot" title "REV" w lp ls 2
