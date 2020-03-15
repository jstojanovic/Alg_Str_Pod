int faktorijel(int n){
    if(n<=1){
        return 1;
    }
    else{
        podrjesenje = faktorijel(n-1);
        rjesenje = podrjesenje * n;
        return rjesenje;
    }
}

