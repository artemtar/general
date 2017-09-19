package Lab1;
import java.util.Random;
import java.util.Scanner;
import java.lang.*;

public class invertible_complex implements invertible{
		/**complex number is z = u + i*v
		 * where u is real part is val_x
		 * v is imaginary part is val_y
		 */
	    double val_x;
	    double val_y;
	    static Random rand;
	    public invertible_complex () { val_x = 0; val_y = 0; if (rand==null) rand = new Random();}
	    public void randomize() { val_x = rand.nextInt(100); val_y = rand.nextInt(100);}
	    public void reset_2_zero() { val_x = 0; val_y = 0; }
	    public void reset_2_identity() { val_x = 1; val_y = 0; }
	    public void init (){
	        Scanner scanner = new Scanner(System.in);
	        System.out.print("Enter a real part of number: ");
	        this.val_x = scanner.nextFloat();
	        System.out.print("Enter a imaginary part of number: ");
	        this.val_y = scanner.nextFloat();
	        //scanner.close();
	    }
	    public invertible_complex get_inverse() throws ArithmeticException { 
	      if (this.val_x == 0 & this.val_y == 0) {
	        throw new ArithmeticException();
	      }
	      else {//looking for inverse
	        double den = Math.pow(this.val_x, 2) + Math.pow(this.val_y, 2); 
	        invertible_complex t = new invertible_complex();
	        t.val_x = this.get_real() / den;
	        t.val_y = -1 * this.get_imag() / den;	   	        
	        return t;
	      }
	    }
	    public invertible_complex multiply_by(invertible B){//standard formula for complex multiplication
	      invertible_complex b = (invertible_complex)B;
	      invertible_complex t = new invertible_complex();
	      t.val_x = this.get_real() * b.get_real() - this.get_imag() * b.get_imag();
	      t.val_y = this.get_real() * b.get_imag() + this.get_imag() * b.get_real();	  	      
	      return t;
	    }
	  public void display(String  name){
	      if(this.val_y > 0) System.out.println("" + name + " is: " + val_x + " + " + val_y + "i");
	      if(this.val_y < 0) System.out.println("" + name + " is: " + val_x + " " + val_y + "i");
	      if(this.val_y == 0) System.out.println("" + name + " is: " + val_x + " + "  + "0i");
	  }
	  public double get_real(){
		  return val_x;
	}
	  public double get_imag (){
		  return val_y;
	  }	  

}
