# Billions-of-Blocks-solution

This solution requires https://github.com/Cubitect/cubiomes

install that repository and then copy seed_find.c seed_find.h POI.csv and Example.java into that directory.

compile : gcc -o seed_find seed_find.c -L. -lcubiomes -fwrapv -lm
run : seed_find > seed_list.txt

run: java  Example.java | sort -n > seed_word_list.txt

grep -f seed_list.txt seed_word_list.txt

details are in Billions of Blocks.pdf

