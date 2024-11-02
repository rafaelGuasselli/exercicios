from collections import deque
import sys
import threading

def main():
    import sys
    sys.setrecursionlimit(1 << 25)
    N, M = map(int, sys.stdin.readline().split())
    movie_to_actors = []
    actor_to_movies = [[] for _ in range(M+1)]  # 1-based indexing for actors

    total_actors_in_movies = 0

    for movie_id in range(N):
        parts = sys.stdin.readline().split()
        ni = int(parts[0])
        actors = list(map(int, parts[1:]))
        movie_to_actors.append(actors)
        total_actors_in_movies += ni
        for actor in actors:
            actor_to_movies[actor].append(movie_id)

    Q = int(sys.stdin.readline())
    queries = [tuple(map(int, sys.stdin.readline().split())) for _ in range(Q)]

    # For visited arrays
    vis_id = 1
    visited = [0] * (M + N + 1)  # M actors + N movies, indexing from 1 to M+N

    # For parent tracking
    parent = [(-1, -1)] * (M + N + 1)  # (parent node, edge type), edge type: 0 for actor, 1 for movie

    for xi, yi in queries:
        if xi == yi:
            print(1)
            print(xi)
            continue

        # Check if xi and yi have any common movies
        xi_movies = set(actor_to_movies[xi])
        yi_movies = set(actor_to_movies[yi])
        common_movies = xi_movies & yi_movies
        if common_movies:
            m = common_movies.pop()
            print(3)
            print(f"{xi} {m+1} {yi}")
            continue

        # Bidirectional BFS
        vis_id += 1
        fwd_queue = deque()
        bwd_queue = deque()

        visited[xi] = vis_id
        visited[yi] = -vis_id

        fwd_parent = {}
        bwd_parent = {}

        fwd_queue.append(xi)
        bwd_queue.append(yi)

        meeting_node = None

        found = False

        while fwd_queue and bwd_queue:
            # Expand forward frontier
            for _ in range(len(fwd_queue)):
                u = fwd_queue.popleft()
                if visited[u] == -vis_id:
                    meeting_node = u
                    found = True
                    break

                if u <= M:
                    # u is an actor, go to movies
                    for m in actor_to_movies[u]:
                        v = M + m + 1  # Indexing movies from M+1
                        if visited[v] == 0:
                            visited[v] = vis_id
                            parent[v] = (u, 0)
                            fwd_queue.append(v)
                        elif visited[v] == -vis_id:
                            meeting_node = v
                            parent[v] = (u, 0)
                            found = True
                            break
                else:
                    # u is a movie, go to actors
                    m = u - M -1
                    for actor in movie_to_actors[m]:
                        if visited[actor] == 0:
                            visited[actor] = vis_id
                            parent[actor] = (u, 1)
                            fwd_queue.append(actor)
                        elif visited[actor] == -vis_id:
                            meeting_node = actor
                            parent[actor] = (u, 1)
                            found = True
                            break
                if found:
                    break
            if found:
                break

            # Expand backward frontier
            for _ in range(len(bwd_queue)):
                u = bwd_queue.popleft()
                if visited[u] == vis_id:
                    meeting_node = u
                    found = True
                    break

                if u <= M:
                    # u is an actor, go to movies
                    for m in actor_to_movies[u]:
                        v = M + m + 1
                        if visited[v] == 0:
                            visited[v] = -vis_id
                            parent[v] = (u, 0)
                            bwd_queue.append(v)
                        elif visited[v] == vis_id:
                            meeting_node = v
                            parent[v] = (u, 0)
                            found = True
                            break
                else:
                    # u is a movie, go to actors
                    m = u - M -1
                    for actor in movie_to_actors[m]:
                        if visited[actor] == 0:
                            visited[actor] = -vis_id
                            parent[actor] = (u, 1)
                            bwd_queue.append(actor)
                        elif visited[actor] == vis_id:
                            meeting_node = actor
                            parent[actor] = (u, 1)
                            found = True
                            break
                if found:
                    break
            if found:
                break

        if not found:
            print(-1)
            continue

        # Reconstruct path
        path = []

        # From meeting_node back to xi
        u = meeting_node
        path1 = []
        while u != xi:
            par_u, edge_type = parent[u]
            if edge_type == 0:
                # Came from actor
                if u <= M:
                    # u is actor
                    path1.append(u)
                else:
                    # u is movie
                    path1.append(u - M -1)
            else:
                if u <= M:
                    path1.append(u)
                else:
                    path1.append(u - M -1)
            u = par_u
        path1.append(xi)
        path1.reverse()

        # From meeting_node back to yi
        u = meeting_node
        path2 = []
        while u != yi:
            par_u, edge_type = parent[u]
            if edge_type == 0:
                # Came from actor
                if u <= M:
                    # u is actor
                    path2.append(u)
                else:
                    # u is movie
                    path2.append(u - M -1)
            else:
                if u <= M:
                    path2.append(u)
                else:
                    path2.append(u - M -1)
            u = par_u
        path2 = path2[1:]  # Skip the meeting node

        full_path = path1 + path2[::-1]

        # Now print the path in the required format
        path_output = []
        for idx, node in enumerate(full_path):
            if idx % 2 == 0:
                # Actor
                path_output.append(str(node))
            else:
                # Movie
                path_output.append(str(node + 1))  # Movies are 0-indexed in list but 1-indexed in output

        print(len(path_output))
        print(' '.join(path_output))

if __name__ == "__main__":
    threading.Thread(target=main).start()
