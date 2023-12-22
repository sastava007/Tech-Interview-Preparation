
int isLeap(int n){
 
 
    //code here
    
    if(n % 400 == 0){
        return 1;
    }
    
    else if(n % 4 == 0 && n % 100 != 0){
        return 1;
    }
    
    else{
        return 0;
    }

    
    
    
}
