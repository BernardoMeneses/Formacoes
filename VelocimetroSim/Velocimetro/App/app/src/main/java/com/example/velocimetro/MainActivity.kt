package com.example.velocimetro

import android.os.Bundle
import android.os.Handler
import android.os.Looper
import android.view.MotionEvent
import android.widget.Button
import android.widget.TextView
import androidx.appcompat.app.AppCompatActivity

class MainActivity : AppCompatActivity() {
    private lateinit var tvSpeed: TextView
    private lateinit var btnAccelerate: Button
    private lateinit var btnLock: Button
    private lateinit var clippedNeedleView: ClippedNeedleView

    private var speed = 0
    private var isLocked = false
    private val handler = Handler(Looper.getMainLooper())

    private val increaseSpeedRunnable = object : Runnable {
        override fun run() {
            increaseSpeed()
            handler.postDelayed(this, 10) // Aumenta a cada 10ms
        }
    }

    private val decreaseSpeedRunnable = object : Runnable {
        override fun run() {
            decreaseSpeed()
            handler.postDelayed(this, 50) // Diminui a cada 50ms
        }
    }

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        tvSpeed = findViewById(R.id.tv_speed)
        btnAccelerate = findViewById(R.id.btn_accelerate)
        btnLock = findViewById(R.id.btn_lock)
        clippedNeedleView = findViewById(R.id.clipped_needle_view)

        btnAccelerate.setOnTouchListener { v, event ->
            when (event.action) {
                MotionEvent.ACTION_DOWN -> {
                    // Para a diminuição da velocidade e inicia o aumento da velocidade
                    handler.removeCallbacks(decreaseSpeedRunnable)
                    handler.post(increaseSpeedRunnable)
                }
                MotionEvent.ACTION_UP, MotionEvent.ACTION_CANCEL -> {
                    // Para o aumento da velocidade e inicia a diminuição da velocidade
                    handler.removeCallbacks(increaseSpeedRunnable)
                    handler.post(decreaseSpeedRunnable)
                }
            }
            v.performClick()
            true
        }

        btnLock.setOnClickListener {
            toggleLock()
        }
    }

    private fun increaseSpeed() {
        if (!isLocked && speed < 180) {
            speed += 1
            tvSpeed.text = "$speed Km/h"
            updateNeedle()
        }
    }

    private fun decreaseSpeed() {
        if (!isLocked && speed > 0) {
            speed -= 1
            tvSpeed.text = "$speed Km/h"
            updateNeedle()
        }
    }

    private fun toggleLock() {
        isLocked = !isLocked
        btnLock.text = if (isLocked) "Unlock" else "Lock"
        if (isLocked) {
            handler.removeCallbacks(increaseSpeedRunnable)
            handler.removeCallbacks(decreaseSpeedRunnable)
            speed = 0
            tvSpeed.text = "$speed Km/h"
            updateNeedle()
        }
    }

    private fun updateNeedle() {
        clippedNeedleView.setAngle(speed.toFloat())
    }
}





