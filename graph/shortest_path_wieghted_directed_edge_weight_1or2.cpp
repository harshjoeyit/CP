/*
      Shortest path in a wieghted DIRECTED graph, with 
      wieghts being either 0 or 1. Number of vertices = n.

      Approach: BFS 

      Note: We cannot user 0/1 BFS it is used ONLY when 1 of the edge wieght is = 0
      Example where 0/1 BFS fails 

      (1,2,1)
      (2,3,1)
      (3,4,1)
      (1,4,2)

      0/1 BFS => dis(1,4) = 3
      correct => dis(1,4) = 2 

      1. For every edge (u, v, w), if w = 2, then we add an extra vertex (u+n)
      such that u --> (u+n) ---> v and new edges are of 1 wieght each 
      (u, u+n, 1) and (u+n, v, 1)

      2. Simple BFS to find the distance from souce to destination 
*/