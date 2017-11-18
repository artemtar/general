package com.google.firebase.udacity.friendlychat;

import android.content.Context;
import android.support.annotation.LayoutRes;
import android.support.annotation.NonNull;
import android.widget.ArrayAdapter;

/**
 * Created by artem on 2017-11-17.
 */

public class CustomAdapter extends ArrayAdapter<String> {
    public CustomAdapter(@NonNull Context context,  String[] something) {
        super(context, R.layout.custom, something);
    }

}
