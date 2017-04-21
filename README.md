# Tic-Tac-Toe AI

A tic-tac-toe AI program that never loses. This program uses the minimax algorithm.

https://en.wikipedia.org/wiki/Minimax#Minimax_algorithm_with_alternate_moves

### Usage
Requires C++ 11

### Algorithm Details
A minimax algorithm is a recursive algorithm for choosing the next move in an n-player game, usually a two-player, back and forth game. A value is associated with each position or state of the game. This value is computed by means of a position evaluation function and it indicates how good it would be for a player to reach that position. The player then makes the move that maximizes the minimum value of the position resulting from the opponent's possible following moves. If it is A's turn to move, A gives a value to each of his legal moves.

A simple version of the minimax algorithm, stated below, deals with games such as tic-tac-toe, where each player can win, lose, or draw. If player A can win in one move, his best move is that winning move. If player B knows that one move will lead to the situation where player A can win in one move, while another move will lead to the situation where player A can, at best, draw, then player B's best move is the one leading to a draw. Late in the game, it's easy to see what the "best" move is. The Minimax algorithm helps find the best move, by working backwards from the end of the game. At each step it assumes that player A is trying to maximize the chances of A winning, while on the next turn player B is trying to minimize the chances of A winning (i.e., to maximize B's own chances of winning).

### Pseudocode
~~~~
function minimax(n: node): int =
    if leaf(n) then return evaluate(n)
    if n is a max node
       v := L
       for each child of n
          v' := minimax (child)
          if v' > v, v:= v'
       return v
    if n is a min node
       v := W
       for each child of n
          v' := minimax (child)
          if v' < v, v:= v'
       return v
~~~~
