Problem #1
==========
1. The segfault is in the append() function.
2. The last() function always returns NULL, so dereferencing l gives a
   segfault.

Problem #2
==========
1. The infinite loop is in the print() function.
2. The addresses loop, meaning that the last pointer is pointing
   to the first, rather than NULL.

Problem #3
==========
1. The issue is that the sum() function was checking while the next pointer
   was null, so it was skipping over the last value.

Problem #4
==========
1. It is a little confusing (probably because pointers are still pretty
   confusing for me) but I could see it being a useful tool further along in
   my career. I've never used a debugger before so I don't know what I
   should be expecting or what all they really do.
