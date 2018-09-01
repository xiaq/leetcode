func findMinArrowShots(points [][]int) int {
    sort.Slice(points, func(i, j int) bool {
        return points[i][1] < points[j][1]
    })
    result := 0
    last := 0
    for i, point := range points {
        if i == 0 || point[0] > last {
            result++
            last = point[1]
        }
    }
    return result
}
