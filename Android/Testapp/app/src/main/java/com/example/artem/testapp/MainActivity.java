package com.example.artem.testapp;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.widget.LinearLayout;
import android.view.View;
import android.widget.TextView;
import android.widget.ListView;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        LinearLayout lm = (LinearLayout) findViewById(R.id.main_layiut);
        LayoutInflater inf = getLayoutInflater();

        View cust = (View) inf.inflate(R.layout.what, lm, false);
        TextView t = (TextView) cust.findViewById(R.id.textView);
        t.setText("new whateeber");
        lm.addView(cust);
        ListView listmain = (ListView) findViewById(R.id.listMain);
        String[] s = {"1", "2", "3", "4", "5", "6", "7"};
        customeAdapter c = new customeAdapter(MainActivity.this, s);
        listmain.setAdapter(c);




    }
}
