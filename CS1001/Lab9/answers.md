Problem #1
==========
1. Memory leaks.
2. There is a List pointer in main being used but it isn't being deleted.

Problem #2
==========
1. Some will be in definitely lost and some will be indirectly lost because
   the pointers aren't being deleted in main and neither are the objects.
2. I was right, wow!
3. The dtor class has a destructor that deletes its pointer member but the
   plain class does not.

Problem #3
==========
1. vect (the pointer to the first element of the vector) was being deleted
   before copy could actually use it so it was showing up as 0 instead of 1
   and copy wasn't being deleted at all.
