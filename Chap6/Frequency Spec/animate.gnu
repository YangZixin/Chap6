set term pdfcairo lw 2 font "Times␣New␣Roman , 5 "
set output "FixedIdealComb.pdf"
set xlabel "Power (arbitrary units)"
set ylabel "Frequency (Hz)"
plot "FixedIdeal.dat" with lines title "String excited at the center", "FixedIdeal05.dat" with lines linetype 0 title "String excited 5 percent from its center"
set output
