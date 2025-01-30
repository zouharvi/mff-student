:- ['main.pl'].


% Data points for knn
% p([x,y] of value)
p([1,1] of [9, -6]).
p([1,3] of [7, -5]).
p([1,7] of [4, -2]).
p([2,2] of [8, -5.2]).
p([2,3] of [6, -3.1]).
p([2,5] of [5, -2]).
p([3,2] of [6, -3]).
p([4,1] of [5, -2.1]).
p([4,5] of [4, -2]).
p([4,6] of [3, 0]).
p([4,7] of [3, 0.1]).
p([5,5] of [2, 2]).
p([5,6] of [1, 4]).
p([6,2] of [4, 8]).
p([6,5] of [1, 5]).
p([6,6] of [1, 2.7]).
p([7,1] of [4, 5.7]).
p([7,6] of [0, 20]).


% Figure of example above (only the first dimension)
%   1 2 3 4 5 6 7
%   -------------
% 1|9 . 7 B . . 4|
% 2|. 8 6 . 5 . .|
% 3|. 6 . . . . .|
% 4|5 . . . 4 3 3|
% 5|. . . . 2 1 .|
% 6|. 4 . C 1 1 .|
% 7|4 A . . . 0 .|
%   -------------

% Run the following example for points indicated on the plane
% 1. knn(4, [2, 7], C).
% 2. knn(4, [1, 4], C).
% 3. knn(4, [6, 4], C).