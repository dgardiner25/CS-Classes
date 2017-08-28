Problem #1
==========
1. total(B) = 672 B.

~~~
     B
  672^                                               ##  :::::
     |                                               #   :
     |                                               # :::
     |                                     @@@@   :::# : :
     |                                     @      :  # : :
     |                                     @      :  # : :    ::
     |                                     @      :  # : :    :
     |                                     @   ::::  # : :    : :::
     |                                :::::@   :  :  # : :    : :
     |                                :    @   :  :  # : :    : :
     |                         @@@  :::    @   :  :  # : :    : :
     |                         @    : :    @   :  :  # : :    : :  ::
     |                    @@   @  ::: :    @   :  :  # : :    : :  : ::
     |                    @ :::@  : : :    @   :  :  # : :    : :  : :
     |                  ::@ :  @  : : :    @   :  :  # : :    : :  : :
     |            @@  ::: @ :  @  : : :    @   :  :  # : :    : :  : : ::
     |    @ :: @@ @   : : @ :  @  : : :    @   :  :  # : :    : :  : : : ::
     |    @ :  @ :@ ::: : @ :  @  : : :    @   :  :  # : :    : :  : : : :
     |   :@:: :@ :@ : : : @ :  @  : : :    @   :  :  # : :    : :  : : : : ::
     | :::@:: :@ :@ : : : @ :  @  : : :    @   :  :  # : :    : :  : : : : :
   0 +----------------------------------------------------------------------->KB
     0                                                                   2.250
~~~

2. Of course not!
3. 272 B.

Problem #2
==========
1. The average() function, called 1000 times.
2. The Vector paramter in average() was not being passed by reference so each
   time the function was called it would make a copy.
3. There are no calls of the copy constructor now. Since the parameter is being
   passed by reference, it is just a pointer to the first element.

Problem #3
==========
1. Line 7, Vector initialization; line 11, getline(); line 21, for loop 
   using [] operator;
   62,627 instructions.
2. I'm gonna go with no.
3. It's like 1,285 or something like that.
