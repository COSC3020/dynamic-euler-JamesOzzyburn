function factorial(n) {
    if(n === 0) return 1;
    else return n * factorial(n - 1);
}

function e(n) {
    if(n === 0) return 1;
    else return 1.0 / factorial(n) + e(n - 1);
}
