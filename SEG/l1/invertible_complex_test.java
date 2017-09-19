package l1;

public class invertible_complex_test {
    public static void main(String args[]) {
    invertible_complex A = new invertible_complex();
    A.randomize();
    A.display("A");
    invertible_complex B = new invertible_complex();
    B.randomize();
    B.display("B");
    invertible_complex AxB = (invertible_complex) A.multiply_by(B);
    AxB.display("A*B");
    invertible_complex C = (invertible_complex) A.get_inverse();
    C.display("1/A");
    invertible_complex D = (invertible_complex) B.multiply_by(C);
    D.display("B/A");
    invertible_complex E = new invertible_complex();
    E.reset_2_zero();
    try {
        invertible_complex F = (invertible_complex) E.get_inverse();
        F.display("divideByZero");
      } catch (Exception e) {
          System.out.println("divideByZero");
      }
      System.out.println("done!");
    invertible_complex G = new invertible_complex();
    invertible_complex H = new invertible_complex();    
    solver s = new  solver(G, H);
    s.set_both();
    G.display("G");
    H.display("H");
    System.out.println("Solution is: " );   
    s.solve_for_x();
    
}}
