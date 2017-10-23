package com.example.artem.l3;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity { // setting the constants
    public enum op {
        ONE {
            public String toString() {
                return "1";
            }
        },
        TWO {
            public String toString() {
                return "2";
            }
        },
        THREE {
            public String toString() {
                return "3";
            }
        },
        FOUR {
            public String toString() {
                return "4";
            }
        },
        FIVE {
            public String toString() {
                return "5";
            }
        },
        SIX {
            public String toString() {
                return "6";
            }
        },
        SEVEN {
            public String toString() {
                return "7";
            }
        },
        EI {
            public String toString() {
                return "8";
            }
        },
        NINE {
            public String toString() {
                return "9";
            }
        },
        ZERO {
            public String toString() {
                return "0";
            }
        },
        MULT {
            public String toString() {
                return "x";
            }
        },
        DIV {
            public String toString() {
                return "/";
            }
        },
        EQ {
            public String toString() {
                return "=";
            }
        },
        MINUS {
            public String toString() {
                return "-";
            }
        },
        PLUS {
            public String toString() {
                return "+";
            }
        },
        DOT {
            public String toString() {
                return ".";
            }
        },
        EMPTY {
            public String toString() {
                return "";
            }
        }
    }

    private String display = ""; //variable is called the diplay but is more accurately the input field
    private double A = Double.MAX_VALUE, B = 0; //removed the result double since I felt it was not needed
    private op OP = op.EMPTY;

    public double impEq(op operator, double A, double B) { //gives the result a value. Performs a basic math operation
        double res = 0;
        switch (operator) {
            case MINUS:
                res = A - B;
                break;
            case PLUS:
                res = A + B;
                break;
            case DIV:
                res = A / B;
                break;
            case MULT:
                res = A * B;
                break;
        }
        return res;

    }



    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        final TextView textRes = (TextView) findViewById(R.id.displayText);
        final TextView textOP = (TextView) findViewById(R.id.displayOp);
        textRes.setCursorVisible(false);

        Button b0 = (Button) findViewById(R.id.button0);
        b0.setOnClickListener(new Button.OnClickListener() {//when the button is pressed update the display string

            @Override
            public void onClick(View view) {
                display += op.ZERO;
                textRes.setText(display);
            }
        });

        Button b1 = (Button) findViewById(R.id.button1);
        b1.setOnClickListener(new Button.OnClickListener() {

            @Override
            public void onClick(View view) {
                display += op.ONE;
                textRes.setText(display);

            }
        });

        Button b2 = (Button) findViewById(R.id.button2);
        b2.setOnClickListener(new Button.OnClickListener() {

            @Override
            public void onClick(View view) {
                display += op.TWO;
                textRes.setText(display);

            }
        });

        Button b3 = (Button) findViewById(R.id.button3);
        b3.setOnClickListener(new Button.OnClickListener() {

            @Override
            public void onClick(View view) {

                display += op.THREE;
                textRes.setText(display);

            }
        });
        Button b4 = (Button) findViewById(R.id.button4);
        b4.setOnClickListener(new Button.OnClickListener() {

            @Override
            public void onClick(View view) {

                display += op.FOUR;
                textRes.setText(display);

            }
        });
        Button b5 = (Button) findViewById(R.id.button5);
        b5.setOnClickListener(new Button.OnClickListener() {

            @Override
            public void onClick(View view) {

                display += op.FIVE;
                textRes.setText(display);

            }
        });
        Button b6 = (Button) findViewById(R.id.button6);
        b6.setOnClickListener(new Button.OnClickListener() {

            @Override
            public void onClick(View view) {

                display += op.SIX;
                textRes.setText(display);

            }
        });
        Button b7 = (Button) findViewById(R.id.button7);
        b7.setOnClickListener(new Button.OnClickListener() {

            @Override
            public void onClick(View view) {
                display += op.SEVEN;
                textRes.setText(display);

            }
        });
        Button b8 = (Button) findViewById(R.id.button8);
        b8.setOnClickListener(new Button.OnClickListener() {

            @Override
            public void onClick(View view) {

                display += op.EI;
                textRes.setText(display);

            }
        });
        Button b9 = (Button) findViewById(R.id.button9);
        b9.setOnClickListener(new Button.OnClickListener() {

            @Override
            public void onClick(View view) {
                display += op.NINE;
                textRes.setText(display);

            }
        });
        Button bCE = (Button) findViewById(R.id.buttonCE);
        bCE.setOnClickListener(new Button.OnClickListener() {

            @Override
            public void onClick(View view) {
                display = "";
                A = Double.MAX_VALUE;
                B = 0;
                OP = op.EMPTY;
                textRes.setText(op.EMPTY.toString());
                textOP.setText(op.EMPTY.toString());
            }
        });
        Button bDiv = (Button) findViewById(R.id.buttonDiv);
        bDiv.setOnClickListener(new Button.OnClickListener() {

            @Override
            public void onClick(View view) {
                if (display ==""){
                    if (A != Double.MAX_VALUE){
                        if (OP== op.EMPTY){
                            OP = op.DIV;
                            textOP.setText(OP.toString());
                        }
                    }
                }else{
                    if (OP == op.EMPTY){
                        A = Double.parseDouble(display);
                        OP = op.DIV;
                        textOP.setText(OP.toString());
                        display = "";
                    }else{
                        B = Double.parseDouble(display);
                        A = impEq(OP, A, B);
                        if (A - (int) A != 0) {textRes.setText(Double.toString(A));}
                        else {
                            textRes.setText(Integer.toString((int) A));
                        }
                        OP = op.DIV;
                        textOP.setText(OP.toString());
                        display = "";
                    }
                }
            }
        });
        Button bX = (Button) findViewById(R.id.buttonMultip);
        bX.setOnClickListener(new Button.OnClickListener() {

            @Override
            public void onClick(View view) {
                if (display ==""){
                    if (A != Double.MAX_VALUE){
                        if (OP== op.EMPTY){
                            OP = op.MULT;
                            textOP.setText(OP.toString());
                        }
                    }
                }else{
                    if (OP == op.EMPTY){
                        A = Double.parseDouble(display);
                        OP = op.MULT;
                        textOP.setText(OP.toString());
                        display = "";
                    }else{
                        B = Double.parseDouble(display);
                        A = impEq(OP, A, B);
                        if (A - (int) A != 0) {textRes.setText(Double.toString(A));}
                        else {
                            textRes.setText(Integer.toString((int) A));
                        }
                        OP = op.MULT;
                        textOP.setText(OP.toString());
                        display = "";
                    }
                }

            }
        });
        Button bPlus = (Button) findViewById(R.id.button_plus);
        bPlus.setOnClickListener(new Button.OnClickListener() {

            @Override
            public void onClick(View view) {
                if (display ==""){
                    if (A != Double.MAX_VALUE){
                        if (OP== op.EMPTY){
                            OP = op.PLUS;
                            textOP.setText(OP.toString());
                        }
                    }
                }else{
                    if (OP == op.EMPTY){
                        A = Double.parseDouble(display);
                        OP = op.PLUS;
                        textOP.setText(OP.toString());
                        display = "";
                    }else{
                        B = Double.parseDouble(display);
                        A = impEq(OP, A, B);
                        if (A - (int) A != 0) {textRes.setText(Double.toString(A));}
                        else {
                            textRes.setText(Integer.toString((int) A));
                        }
                        OP = op.PLUS;
                        textOP.setText(OP.toString());
                        display = "";
                    }
                }
            }


        });
        Button bMinus = (Button) findViewById(R.id.buttonMinus);
        bMinus.setOnClickListener(new Button.OnClickListener() {

            @Override
            public void onClick(View view) {
                if (display ==""){
                    if (A != Double.MAX_VALUE){
                        if (OP== op.EMPTY){
                            OP = op.MINUS;
                            textOP.setText(OP.toString());
                        }
                    }
                }else{
                    if (OP == op.EMPTY){
                        A = Double.parseDouble(display);
                        OP = op.MINUS;
                        textOP.setText(OP.toString());
                        display = "";
                    }else{
                        B = Double.parseDouble(display);
                        A = impEq(OP, A, B);
                        if (A - (int) A != 0) {textRes.setText(Double.toString(A));}
                        else {
                            textRes.setText(Integer.toString((int) A));
                        }
                        OP = op.MINUS;
                        textOP.setText(OP.toString());
                        display = "";
                    }
                }

            }
        });

        Button bDot = (Button) findViewById(R.id.buttonDot);
        bDot.setOnClickListener(new Button.OnClickListener() {

            @Override
            public void onClick(View view) {
                if (display.equals("")){
                    display = "0.";

                }
                else if (!display.contains(".")) {

                    display += op.DOT;
                }
                textRes.setText(display);


            }
        });
        Button bEQ = (Button) findViewById(R.id.buttonExecution);
        bEQ.setOnClickListener(new Button.OnClickListener() {

            @Override
            public void onClick(View view) {
                if (OP != op.EMPTY&&display!="") { // needs to be an operation and an operand
                    B = Double.parseDouble(display);
                    textOP.setText(op.EQ.toString());
                    A = impEq(OP,A,B);
                    OP = op.EMPTY;
                    if (A - (int) A != 0) {textRes.setText(Double.toString(A));}
                    else {
                        textRes.setText(Integer.toString((int) A));
                    }
                    display = ""; //reset input field.
                }/*else{
                    A = Double.parseDouble(display);// this line was causing errors all over the place. Cannot parse an empty String
                }*/
            }
        });

    }

}
