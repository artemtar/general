package l1;

public interface invertible {
	public void init();
	  public void randomize();
	  public void reset_2_zero();
	  public void reset_2_identity();
	  public invertible get_inverse() throws ArithmeticException;
	  public invertible multiply_by(invertible val);
	  public void display(String  name);
}
