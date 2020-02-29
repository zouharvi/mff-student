pandoc -V papersize:a4 -V geometry:margin=1.5in -s -t latex -o notes_exam.pdf -f markdown notes_exam.md
rm -f notes_exam.html

# --toc --toc-depth=2