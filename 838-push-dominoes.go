func pushDominoes(dominoes string) string {
    fill := func(bs []byte, b byte) {
        // Fill an entire byte slice with one character.
        for i := range bs {
            bs[i] = b
        }
    }
    fillHalves := func(bs []byte, left, right byte) {
        // Fill the left half of a byte slice with one char, and the right half with another.
        // If the slice has an odd size, the middle element is untouched.
        for i := 0; i < len(bs) / 2; i++ {
            bs[i] = left
        }
        for i := (len(bs)+1) / 2; i < len(bs); i++ {
            bs[i] = right
        }
    }
    
    out := []byte(dominoes)
    last := -1

    for i, r := range([]byte(dominoes)) {
        switch r {
        case 'L':
            if last == -1 || dominoes[last] == 'L' {
                fill(out[last+1:i], 'L')
            } else {
                fillHalves(out[last+1:i], dominoes[last], r)
            }
            last = i
        case 'R':
            if last >= 0 && dominoes[last] == 'R' {
                fill(out[last+1:i], 'R')
            }
            last = i
        }
    }
    if last >= 0 && dominoes[last] == 'R' {
        fill(out[last+1:], 'R')
    }
    return string(out)
}
