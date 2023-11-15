// Pode-se fazer utilizando x mod13
function rot13(str) {
    let ans = ""
    for(let i = 0; i < str.length; i++) {
        let aC = str.charCodeAt(i)
        if(aC <= 77 && aC >=65)
            ans+= String.fromCharCode(aC+13)
        else if(aC >= 78 && aC <=90)
            ans += String.fromCharCode(aC-13)
        else 
          ans += str[i]
    }
    return ans;
}

rot13("SERR PBQR PNZC");