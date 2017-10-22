package com.example.artem.l3;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {
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

    private String display = "";
    private String prevDisplay = "";
    private double A = 0, B = 0;
    private double res = 0;
    private op OP = op.EMPTY;
    private op prev = op.EMPTY;
    double Bprev;

    public double impEq(op operator, double A, double B) {
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

        Button b0 = (Button) findViewById(R.id.button0);
        b0.setOnClickListener(new Button.OnClickListener() {

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
                A = 0;
                B = 0;
                res = 0;
                Bprev = 0;
                prev = op.EMPTY;
                OP = op.EMPTY;
                textRes.setText(op.EMPTY.toString());
                textOP.setText(op.EMPTY.toString());
            }
        });
        Button bDiv = (Button) findViewById(R.id.buttonDiv);
        bDiv.setOnClickListener(new Button.OnClickListener() {

            @Override
            public void onClick(View view) {
                if (OP != op.EQ & OP != op.EMPTY & B == Bprev) {
                    B = Double.parseDouble(display);
                    res = impEq(prev, A, B);
                    A = res;
                    Bprev = B;
                    OP = op.DIV;
                    if (res - (int) res != 0) display = Double.toString(res);
                    else display = Integer.toString((int) res);
                    textOP.setText(OP.toString());
                    textRes.setText(display);
                    display = "";
                    prev = OP;
                } else if (OP == op.EQ) {
                    OP = op.DIV;
                    textOP.setText(OP.toString());
                    textRes.setText(op.EMPTY.toString());
                    display = "";
                } else if (display != "" || display == ".") {
                    OP = op.DIV;
                    prev = OP;
                    textOP.setText(OP.toString());
                    A = Double.parseDouble(textRes.getText().toString());
                    textRes.setText(op.EMPTY.toString());
                    display = "";
                    prev = OP;
                }
            }
        });
        Button bX = (Button) findViewById(R.id.buttonMultip);
        bX.setOnClickListener(new Button.OnClickListener() {

            @Override
            public void onClick(View view) {
                if (OP != op.EQ & OP != op.EMPTY & B == Bprev) {
                    B = Double.parseDouble(display);
                    res = impEq(prev, A, B);
                    A = res;
                    Bprev = B;
                    OP = op.MULT;
                    if (res - (int) res != 0) display = Double.toString(res);
                    else display = Integer.toString((int) res);
                    textOP.setText(OP.toString());
                    textRes.setText(display);
                    display = "";
                    prev = OP;
                } else if (OP == op.EQ) {
                    OP = op.MULT;
                    textOP.setText(OP.toString());
                    textRes.setText(op.EMPTY.toString());
                    display = "";
                    prev = OP;
                } else if (display != "" || display == ".") {
                    OP = op.MULT;
                    textOP.setText(OP.toString());
                    A = Double.parseDouble(textRes.getText().toString());
                    textRes.setText(op.EMPTY.toString());
                    display = "";
                    prev = OP;
                }
            }
        });
        Button bPlus = (Button) findViewById(R.id.button_plus);
        bPlus.setOnClickListener(new Button.OnClickListener() {

            @Override
            public void onClick(View view) {
                if (OP != op.EQ & OP != op.EMPTY & B == Bprev) {
                    B = Double.parseDouble(display);
                    res = impEq(prev, A, B);
                    A = res;
                    Bprev = B;
                    OP = op.PLUS;
                    if (res - (int) res != 0) display = Double.toString(res);
                    else display = Integer.toString((int) res);
                    textOP.setText(OP.toString());
                    textRes.setText(display);
                    display = "";
                    prev = OP;
                } else if (OP == op.EQ) {
                    OP = op.PLUS;
                    textOP.setText(OP.toString());
                    textRes.setText(op.EMPTY.toString());
                    display = "";
                    prev = OP;
                } else if (display != "" || display == ".") {
                    OP = op.PLUS;
                    textOP.setText(OP.toString());
                    A = Double.parseDouble(textRes.getText().toString());
                    textRes.setText(op.EMPTY.toString());
                    display = "";
                    prev = OP;
                }
            }
        });
        Button bMinus = (Button) findViewById(R.id.buttonMinus);
        bMinus.setOnClickListener(new Button.OnClickListener() {

            @Override
            public void onClick(View view) {
                if (OP != op.EQ & OP != op.EMPTY & B == Bprev) {
                    B = Double.parseDouble(display);
                    res = impEq(prev, A, B);
                    A = res;
                    Bprev = B;
                    OP = op.MINUS;
                    if (res - (int) res != 0) display = Double.toString(res);
                    else display = Integer.toString((int) res);
                    textOP.setText(OP.toString());
                    textRes.setText(display);
                    display = "";
                    prev = OP;
                } else if (OP == op.EQ) {
                    OP = op.MINUS;
                    textOP.setText(OP.toString());
                    textRes.setText(op.EMPTY.toString());
                    display = "";
                    prev = OP;
                } else if (display != "" || display == ".") {
                    OP = op.MINUS;
                    textOP.setText(OP.toString());
                    A = Double.parseDouble(display);
                    textRes.setText(op.EMPTY.toString());
                    display = "";
                    prev = OP;
                }
            }
        });

        Button bDot = (Button) findViewById(R.id.buttonDot);
        bDot.setOnClickListener(new Button.OnClickListener() {

            @Override
            public void onClick(View view) {
                String check = textRes.getText().toString();
                if (check.indexOf('.') == -1 & display.equals("")) {
                    display = "0.";
                    if (OP.equals(op.EQ)) {
                        OP = op.EMPTY;
                        textOP.setText(OP.toString());
                    }
                    textRes.setText(display);
                } else if (check.indexOf('.') == -1) {
                    display += op.DOT;
                    textRes.setText(display);
                } else if (OP.equals(op.EQ)) {
                    display = "0.";
                    textRes.setText(display);
                    OP = op.EMPTY;
                    textOP.setText(OP.toString());

                }

            }
        });
        Button bEQ = (Button) findViewById(R.id.buttonExecution);
        bEQ.setOnClickListener(new Button.OnClickListener() {

            @Override
            public void onClick(View view) {
                if (OP != op.EMPTY) {
                    textOP.setText(op.EQ.toString());
                    B = Double.parseDouble(display);
                    textRes.setText(op.EMPTY.toString());

                    switch (OP) {
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
                    prev = OP;
                    OP = op.EQ;
                    if (res - (int) res != 0) display = Double.toString(res);
                    else display = Integer.toString((int) res);
                    textRes.setText(display);
                    A = res;
                    Bprev = B;
                    display = "";
                    res = 0;
                }
                if (OP == op.EMPTY) {
                    A = Double.parseDouble(display);
                }
            }
        });

    }

}
