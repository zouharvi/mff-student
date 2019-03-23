:- ['main.pl'].


% Data points for knn
% p([x,y] of class)
p([1,1] of a).
p([1,3] of a).
p([1,7] of b).
p([2,2] of a).
p([2,3] of a).
p([2,5] of b).
p([3,2] of a).
p([4,1] of a).
p([4,5] of c).
p([4,6] of b).
p([4,7] of b).
p([5,5] of b).
p([5,6] of c).
p([6,2] of b).
p([6,5] of c).
p([6,6] of c).
p([7,1] of b).
p([7,6] of c).


% Figure of example above
%   1 2 3 4 5 6 7
%   -------------
% 1|a . a 2 . . b|
% 2|. a a . b . .|
% 3|. a . . . . .|
% 4|a . . . c b b|
% 5|. . . . b c .|
% 6|. b . 3 c c .|
% 7|b 1 . . . c .|
%   -------------

% Run the following example for points indicated on the plane
% 1. knn(4, [2, 7], C).
% 2. knn(4, [1, 4], C).
% 3. knn(4, [6, 4], C).