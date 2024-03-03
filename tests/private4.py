def lcs(X, Y):
    m = len(X)
    n = len(Y)
    dp = [0] * (n + 1)
    
    for i in range(1, m + 1):
        prev = 0
        for j in range(1, n + 1):
            temp = dp[j]
            if X[i - 1] == Y[j - 1]:
                dp[j] = prev + 1
            else:
                dp[j] = max(dp[j], dp[j - 1])
            prev = temp
    
    lcs_length = dp[n]
    lcs_sequence = []
    i, j = m, n
    while i > 0 and j > 0:
        if X[i - 1] == Y[j - 1]:
            lcs_sequence.append(X[i - 1])
            i -= 1
            j -= 1
        elif dp[j] == dp[j - 1]:
            j -= 1
        else:
            i -= 1
    
    return lcs_length, ''.join(reversed(lcs_sequence))

def print_lcs(X, Y):
    lcs_length, lcs_sequence = lcs(X, Y)
    print("Longest Common Subsequence Length:", lcs_length)
    print("Longest Common Subsequence:", lcs_sequence)

def main():
    X = "ABCBDAB"
    Y = "BDCAB"
    print_lcs(X, Y)
    
    X = "AGGTAB"
    Y = "GXTXAYB"
    print_lcs(X, Y)

if __name__ == "__main__":
    main()
