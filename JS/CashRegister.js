const checkCashRegister = (price, cash, cid) => {
    const BASE = {
      "PENNY": .01,
      "NICKEL": .05,
      "DIME": .10,
      "QUARTER": .25,
      "ONE": 1.00,
      "FIVE": 5.00,
      "TEN": 10.00,
      "TWENTY": 20.00,
      "ONE HUNDRED": 100.00
    }
    let drawerMoney = 0,changeMoney = cash - price;
    const auxA = [];

    cid.map(elem => drawerMoney+=elem[1]);

    drawerMoney = drawerMoney.toFixed(2);
    if (changeMoney > drawerMoney) 
      return { status: "INSUFFICIENT_FUNDS", change: []};
    else if (changeMoney.toFixed(2) === drawerMoney) 
      return { status: "CLOSED", change: cid };
    else {
        cid = cid.reverse();
        for (let elem of cid) {
            let aux = [elem[0], 0];
            while (changeMoney >= BASE[elem[0]] && elem[1] > 0) {
                aux[1] += BASE[elem[0]];
                elem[1] -= BASE[elem[0]];
                changeMoney -= BASE[elem[0]];
                changeMoney = changeMoney.toFixed(2);
            }
            if (aux[1] > 0) 
                auxA.push(aux);
        }
    }
    
    if (changeMoney > 0)
      return { status: "INSUFFICIENT_FUNDS", change: [] };
    return { status: "OPEN", change: auxA};
}

checkCashRegister(19.5, 20, [["PENNY", 1.01], ["NICKEL", 2.05], ["DIME", 3.1], ["QUARTER", 4.25], ["ONE", 90], ["FIVE", 55], ["TEN", 20], ["TWENTY", 60], ["ONE HUNDRED", 100]]);