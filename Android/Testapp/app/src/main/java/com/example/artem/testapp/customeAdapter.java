package com.example.artem.testapp;

import android.content.Context;
import android.support.annotation.LayoutRes;
import android.support.annotation.NonNull;
import android.support.annotation.Nullable;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;

/**
 * Created by artem on 2017-11-17.
 */

public class customeAdapter extends ArrayAdapter<String> {

    String[] info;
    Context c;
    int i;

    public customeAdapter(@NonNull Context context, @LayoutRes int resource, String[] s) {
        super(context, R.layout.anothercust);//add this layout to constructor
        info = s;
        c = context;
        i = resource;
    }

    @Override
    public int getCount() {
        return info.length;
    }

    @NonNull
    @Override
    public View getView(int position, @Nullable View convertView, @NonNull ViewGroup parent) {
        LayoutInflater inf =(LayoutInflater) c.getSystemService(Context.LAYOUT_INFLATER_SERVICE);
        return super.getView(position, convertView, parent);
    }

}
