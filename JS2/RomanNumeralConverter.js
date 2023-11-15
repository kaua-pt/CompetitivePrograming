function convertToRoman(num) {
    const numbers = [
              ["","M","MM","MMM"],
              ["","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"],
              ["","X","XX","XXX","XL","L","LX","LXX","LXXX","XC",],
              ["","I","II","III","IV","V","VI","VII","VIII","IX"]
          ];

    let ans = "";
    num = num.toString();
    let a = 4 - num.length;

    for(let i = 0; i < num.length;i++){
        ans += numbers[a + i][parseInt(num[i],10)];
    }

    return ans;
}

convertToRoman(36);