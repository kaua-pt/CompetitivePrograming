function telephoneCheck(str) {
    const validRgx = [/^\d{3}-\d{3}-\d{4}/,
                          /^(\d{3})\d{3}-\d{4}/,
                          /^(\d{3})\s\d{3}-\d{4}/,
                          /^\d{3}\s\d{3}\s\d{4}/,
                          /^\d{10}$/,
                          /^1\s\d{3}\s\d{3}\s\d{4}/,
                          /^1\s\d{3}-\d{3}-\d{4}/,
                          /^\(\d{3}\)\d{3}-\d{4}/,
                          /^1\(\d{3}\)\d{3}-\d{4}/,
                          /^1\s\(\d{3}\)\s\d{3}-\d{4}/ ];
  
    let isValid = validRgx.some(rg => rg.test(str));
  
    return isValid;
  }
  
  telephoneCheck("555-555-5555");