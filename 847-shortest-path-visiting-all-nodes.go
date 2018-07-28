func shortestPathLength(graph [][]int) int {
    n := len(graph)

    solution := 100000
    lenPath := 0
    visited := make([]bool, n)
    nvisited := 0
    taken := make([][]bool, n)
    for i := 0; i < n; i++ {
        taken[i] = make([]bool, len(graph[i]))
    }

    var find func(v int)

    find = func(v int) {
        if lenPath >= solution || solution == n-1 {
            return
        }
        if !visited[v] {
            visited[v] = true
            nvisited++
            defer func() {
                visited[v] = false
                nvisited--
            }()
            if nvisited == n {
                solution = lenPath
                return
            }
        }
        for t := 0; t < 2; t++ {
            // In the firt iteration, try all unvisited nodes.
            // In the second iteration, try all visited nodes.
            // This tends to find short paths faster.
            wantVisited := t == 1
            for j := 0; j < len(graph[v]); j++ {
                if taken[v][j] || visited[graph[v][j]] != wantVisited {
                    continue
                }
                taken[v][j] = true
                lenPath++
                find(graph[v][j])
                lenPath--
                taken[v][j] = false
            }
        }
    }
    
    for i := 0; i < n; i++ {
        find(i)
    }
    return solution
}
