function palindrome(str) {

    const re = /[A-Z]||[\d]/gi
    str = str.match(re).join("").toLowerCase()

    let N = str.length;
    for (let i = 0; i < N / 2; ++i) {
        if (str[i]!= str[N - 1 - i]) {
            return false;
        }
    }
    return true;
}
  
palindrome("eye");