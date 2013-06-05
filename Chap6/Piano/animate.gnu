set term pdfcairo lw 2 font "Times␣New␣Roman , 5 "
set output "PianoC7Wave.pdf"
set ylabel "Signal (arbitrary unit)"
set xlabel "Time (ms)"
plot "PianoC7dddd.dat" with lines title "C7 Wave Signal"
set output
