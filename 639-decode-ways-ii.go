const M = 1000000007

func numDecodings(s string) int {
    f := make([]int, len(s))
    for i := range s {
        switch i {
        case 0:
            f[i] = dw1(s[i])
        case 1:
            f[i] = (dw1(s[i]) * f[i-1]) % M + dw2(s[i-1], s[i])
        default:
            f[i] = (dw1(s[i]) * f[i-1]) % M + (dw2(s[i-1], s[i]) * f[i-2]) % M
        }
        f[i] %= M
    }
    return f[len(s)-1]
}

func dw1(r byte) int {
    switch r {
    case '*':
        return 9
    case '0':
        return 0
    default:
        return 1
    }
}

func dw2(r1, r2 byte) int {
    switch {
    case r1 == '*' && r2 == '*':
        return 15
    case r1 == '*':
        if r2 <= '6' {
            return 2
        }
        return 1
    case r2 == '*' :
        switch r1 {
        case '1':
            return 9
        case '2':
            return 6
        default:
            return 0
        }
    default:
        if r1 == '1' || (r1 == '2' && r2 <= '6') {
            return 1
        }
        return 0
    }
}
