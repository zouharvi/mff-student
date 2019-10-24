## Fifteen
| finished | MB | max GVal | expanded | time | alg |
|----------|----|----------|----------|------|-----|
|**Fifteen 1**|
| yes | 65.63 | 20 | 64417 | 19.5 | BFS |
| yes | 71.30  | 45702  | 82229 | 20.0 | DFS |
| yes | 56.10  | 20     | 6602  | 1.0 | IDS |
|**Fifteen 2**|
| yes | 65.62 | 14 | 74514 | 15.9 | BFS |
| no  | 109.1  | 129885 | 256938 | 114.1 | DFS |
| yes | 56.05  | 14     | 4855  | 1.1 | IDS |
|**Fifteen 3**|
| no  | 100.22 | 15 | 158452 | 66.81 | BFS |
| no  | 102 | 109904 | 217404 | 87.5 | DFS |
| no  | 82.89 | 19 | 148306 | 139.2 | IDS |

Both BFS and IDS were able to finish Fifteen-2, with IDS being faster and using less memory. They both found the optimal solution.

## TSP
| finished | MB | max GVal | expanded | time | alg |
|----------|----|----------|----------|------|-----|
|**TSP 1**|
| yes | 47.04 | 287 | 326 | 0.007 | BFS |
| yes | 47.03 | 207 | 16 | 0.020 | DFS |
| yes | 47.03 | 125 | 42 | 0.013 | IDS |
|**TSP 2**|
| no  | 1320.96 | 723 | 1838916 | 75.3 | BFS |
| yes | 46.65 | 1280 | 121 | 0.006 | DFS |
| no  | 172.47 | 269 | 170018 | 52.51 | IDS |

A solution for TSP-2 was found with DFS, even though it is far from optimal.

## Cube
| finished | MB | max GVal | expanded | time | alg |
|----------|----|----------|----------|------|-----|
|**Cube 1**|
| yes | 517.98 | 9 | 1104497 | 4.76 | BFS |
| no | 876.88 | 488717 | 1879023 | 5.68 | DFS |
| yes | 55.83 | 9 | 5166 | 0.036 | IDS |
|**Cube 2**|
| no  | 5373.21 | 7 | 11316638 | 53.36 | BFS |
| no  | 1690.49 | 6 | 3084576 | 11.2 | DFS |
| no  | 4030.78 | 8 | 8408760 | 184.35 | IDS |

Both BFS and IDS found the optimal solution for Cube-1, though not for Cube-2 because of the vast search space.