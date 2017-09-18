package Lab1;

public class solver {
	private invertible A;
	private invertible b;
	
	solver (invertible passedA, invertible passedB){
		A = passedA;
		b = passedB;

	}
	
	public void set_A(){
		A.init();
	}
	public void set_b(){
		b.init();
	}
	
	public void set_both(){
		System.out.println("Set first number");
		this.set_A();
		System.out.println("Set second number");
		this.set_b();
	}
	
	public void solve_for_x(){	
		 invertible_complex X = (invertible_complex) b.multiply_by(A.get_inverse());
		 X.display("x");
	}
}
