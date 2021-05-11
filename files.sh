#! /bin/bash
for n in {1..1000}; do
    dd if=/dev/urandom of=files/file$( printf %03d "$n" ).bin bs=1 count=$(( RANDOM + 1024 ))
done
