package dev.flutter.impeller.demo;

import android.opengl.GLSurfaceView;
import android.os.Bundle;
import android.util.Log;

import androidx.activity.EdgeToEdge;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.graphics.Insets;
import androidx.core.view.ViewCompat;
import androidx.core.view.WindowInsetsCompat;

import dev.flutter.impeller.Impeller;

public class MainActivity extends AppCompatActivity {

    private GLSurfaceView surfaceView;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        surfaceView = new ImpellerSurfaceView(this);
        setContentView(surfaceView);
    }
}