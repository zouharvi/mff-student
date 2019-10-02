%Dostanu graf a vrchol, vydám upravený graf
% graf v podobě [x-[y,z]], výsledek ve formě [x-[y,z]-čas]

dfs(X-[], A, A, G, []).
dfs(X-[Y|Ys], A, A1, G, V):- member(Y, A), dfs(X-Ys, A, A1, G, V).
dfs(X-[Y|Ys], A, AV, G, V):- get_time(T1), \+ member(Y, A), append([Y], A, A1), hrany(Y, G, H), dfs(Y-H, A1, A2, G, V1), get_time(T2), T3 is T2 - T1, dfs(X-Ys, A2, AV, G, V2), append(V1, V2, V3), append([Y-H-T3], V3, V).

timer(G, S, V):- get_time(T1), hrany(S, G, H), dfs(S-H, [S], A1, G, V1), get_time(T2), T3 is T2 - T1, append([S-H-T3], V1, V).

hrany(X, [X-Y|Z], Y).
hrany(X, [Y1-Y2|Z], V):- hrany(X, Z, V). 
