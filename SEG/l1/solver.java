package Lab1;

public class solver {
	private invertible A;
	private invertible b;
	private solver(){
		this.set_A();
		this.set_b();
	}
	public void set_A(){
		A.init();
	}
	public void set_b(){
		b.init();
	}
	public invertible solve_for_x(){
		return b.multiply_by(A.get_inverse());
	}
}
