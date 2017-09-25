

class bracketsBalance {

    private boolean bBalance (String exp){ 

        // INCLUDE YOUR CODE HERE

        return false;

    }

    public static void main(String[] args) {

        bracketsBalance b = new bracketsBalance();
        boolean result = b.bBalance(args[0]);
   
        if (result) System.out.println("The expression is balanced."); 
        else        System.out.println("The expression is NOT balanced."); 
    }
}