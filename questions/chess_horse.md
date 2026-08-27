given a infinte chess board.
given a,b which represent a box in board with ath row and bth column.

find for given a,b cell is it possible to reach by a horse which starts at (0,0).

approach:
in each move it can move by (a-=2 & b-=1) or (a-=1 & b-=2).
which reduce to in each step decrease of 3.
therefore one condition to sastify for cell a,b to be reach is thier sum is multiple of 3.

    one more condition is that the difference shouldnt be more than double otherwise one of them gets exhaust early.
    therefore second condition is max(a,b)<=2*min(a,b).

beautiful visual question based on cses coin of piles.
