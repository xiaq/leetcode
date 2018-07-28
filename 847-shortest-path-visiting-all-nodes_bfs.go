func shortestPathLength(graph [][]int) int {
    n := len(graph)
    if n == 1 {
        return 0
    }
    allVisited := (1 << uint(n)) - 1

    // Low 16 bits: bitmask for visited nodes
    // High 16 bits: current node
    q := make([]int, n)
    seen := make(map[int]bool)
    for i := 0; i < n; i++ {
        q[i] = (1 << uint(i)) | (i << 16)
        seen[q[i]] = true
    }

    for d := 0; len(q) > 0; d++ {
        newq := make([]int, 0, len(q))
        for _, state := range q {
            visited, u := state & 0xffff, state >> 16
            for _, v := range graph[u] {
                newVisited := visited | (1 << uint(v))
                if newVisited == allVisited {
                    return d + 1
                }
                newState := newVisited | (v << 16)
                if !seen[newState] {
                    seen[newState] = true
                    newq = append(newq, newState)
                }
            }
        }
        q = newq
    }
    panic("no solution")
}
