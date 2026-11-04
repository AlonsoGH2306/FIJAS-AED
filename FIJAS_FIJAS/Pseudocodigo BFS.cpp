BFS(G, s):

para cada vértice v en V:
    dist[v] = ∞
    padre[v] = nulo

dist[s] = 0
ENQUEUE(Q, s)

mientras Q no esté vacía:
    u = FRONT(Q)
    DEQUEUE(Q)

    para cada v en adj[u]:
        si dist[v] == ∞:
            dist[v] = dist[u] + 1
            padre[v] = u
            ENQUEUE(Q, v)