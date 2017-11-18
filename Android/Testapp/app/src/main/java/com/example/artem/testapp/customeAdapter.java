package com.example.artem.testapp;

import android.content.Context;
import android.os.SystemClock;
import android.support.annotation.LayoutRes;
import android.support.annotation.NonNull;
import android.support.annotation.Nullable;
import android.support.v4.graphics.BitmapCompat;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.Chronometer;
import android.widget.ImageView;
import android.widget.TextView;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;

/**
 * Created by artem on 2017-11-17.
 */

public class customeAdapter extends ArrayAdapter<String> {

    String[] info;
    Context c;
    int i;

    public customeAdapter(@NonNull Context context, /*@LayoutRes int resource,*/ String[] s) {
        super(context, R.layout.anothercust);//add this layout to constructor
        info = s;
        c = context;
        //i = resource;
    }

    @Override
    public int getCount() {
        return info.length;
    }

    @NonNull
    @Override
    public View getView(int position, @Nullable View convertView, @NonNull ViewGroup parent) {

        ViewHolder vH = new ViewHolder();

        if (convertView == null) {
            LayoutInflater inf = (LayoutInflater) c.getSystemService(Context.LAYOUT_INFLATER_SERVICE);
            convertView = inf.inflate(R.layout.anothercust, parent, false);/// creating new view to return
            vH.img = (ImageView) convertView.findViewById(R.id.imageView);
            vH.t1 = (TextView) convertView.findViewById(R.id.textView2);
            vH.t2 = (TextView) convertView.findViewById(R.id.text3);
            vH.c = (Chronometer) convertView.findViewById(R.id.chrono);
            convertView.setTag(vH);
        } else {
            vH = (ViewHolder)convertView.getTag();
        }
        vH.t1.setText(info[position]);
        vH.t2.setText("profile");
        vH.img.setImageResource(R.drawable.pic1);
        vH.img.setScaleType(ImageView.ScaleType.CENTER_INSIDE);
        vH.c.setBase(SystemClock.elapsedRealtime());
        vH.c.start();
        return convertView;
    }

    //class that is used in  resuicling
    static class ViewHolder {
        ImageView img;
        TextView t1;
        TextView t2;
        Chronometer c;
    }

}
