package com.example.zigandroidexample;

import androidx.appcompat.app.AppCompatActivity;

import android.app.NativeActivity;
import android.os.Bundle;
import android.widget.TextView;

import com.example.zigandroidexample.databinding.ActivityMainBinding;

public class MainActivity extends NativeActivity {

    // Used to load the 'myraylibapplication' library on application startup.
    static {
        System.loadLibrary("main");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
    }


}
